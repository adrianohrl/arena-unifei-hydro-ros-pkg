/**
 *  Align.h
 *
 *  Version: 1.1.0.0
 *  Created on: 06/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ALIGN_SERVER_H_
#define ALIGN_SERVER_H_

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <sensor_msgs/PointCloud.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_datatypes.h>
#include "robotino_motion/AlignAction.h"
#include "AlignModes.h"
#include "AlignDistances.h"
#include "AlignStates.h"

#define PI 3.14159
#define sign(a) (((a) < 0) ? -1 : (((a) > 0) ? 1 : 0))

#define FRONT_RIGHT_IR_INDEX 1 // Represents the distance sensor index seen on RIGHT to be used in the FRONT alignment mode 
#define FRONT_LEFT_IR_INDEX 8 // Represents the distance sensor index seen on LEFT to be used in the FRONT alignment mode 
#define RIGHT_RIGHT_IR_INDEX 7 // Represents the distance sensor index seen on RIGHT to be used in the RIGHT alignment mode 
#define RIGHT_LEFT_IR_INDEX 6 // Represents the distance sensor index seen on LEFT to be used in the RIGHT alignment mode 
#define LEFT_RIGHT_IR_INDEX 3 // Represents the distance sensor index seen on RIGHT to be used in the LEFT alignment mode  
#define LEFT_LEFT_IR_INDEX 2 // Represents the distance sensor index seen on LEFT to be used in the LEFT alignment mode  
#define BACK_RIGHT_IR_INDEX 5 // Represents the distance sensor index seen on RIGHT to be used in the BACK alignment mode 
#define BACK_LEFT_IR_INDEX 4 // Represents the distance sensor index seen on LEFT to be used in the BACK alignment mode   

#define LINEAR_Kp 0.9 // Proportional Controller Constant for linear movement components, that is, x and y
#define ANGULAR_Kp 10 // Proportional Controller Constant for angular movement component, that is, phi
#define LINEAR_TOLERANCE 0.025 // Error Tolerance used for linear alignment purpose
#define ANGULAR_TOLERANCE 0.005 // Error Tolerance used for angular alignment purpose

using namespace ros;
using namespace actionlib;
using namespace geometry_msgs;
using namespace robotino_motion;
using namespace sensor_msgs;	

class Align
{

public:

	Align(NodeHandle nh);
	~Align();

	void shutdown();
	void spin();
	bool isActing();

private:

	/** Node related Variables and Functions */
	NodeHandle nh_;
	double min_linear_vel_;
	double max_linear_vel_;
	double min_angular_vel_;
	double max_angular_vel_;

	void readParameters(NodeHandle& nh);

	/** Align Action related Variables and Functions */ 	
	SimpleAction<AlignAction> server_;
	AlignGoal goal_;
	AlignFeedback feedback_;
	AlignResult result_;

	void executeCallback(const AlignGoalConstPtr& goal);
	void preemptCallback();
	bool acceptNewGoal(const AlignGoalConstPtr& goal);

	/** Distance Sensor Topic Subscriber related Variables and Functions */
	Subscriber dist_sensors_sub_;
	PointCloud dist_sensors_msg_;
	bool dist_sensors_setted_;

	void distSensorsCallback(const PointCloud& msg);

	/** Velocity Topic Publisher related Variables and Functions */
	Publisher cmd_vel_pub_;
	Twist cmd_vel_msg_;

	void setVelocity(double vel_x, double vel_y, double vel_phi);
	void publishVelocity();

	/** Movement related Variables and Functions */
	AlignState state_;
	int left_ir_index_, right_ir_index_;
	int lateral_left_ir_index_, lateral_right_ir_index_; // used only in modes that uses two modes at the same time
	float left_ir_value_, right_ir_value_;
	float lateral_left_ir_value_, lateral_right_ir_value_; // used only in modes that uses two modes at the same time
	float reference_distance_value_;
	float initial_error_mean_;
	AlignMode mode_;
	AlignDistance distance_;

	void executeEmergencyStop();	
	void controlLoop();

};

#endif /* ALIGN_SERVER_H_ */
