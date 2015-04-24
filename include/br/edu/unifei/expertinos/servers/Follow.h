/**
 *  Follow.h
 *
 *  Version: 1.1.0.0
 *  Created on: 06/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef FOLLOW_SERVER_H_
#define FOLLOW_SERVER_H_

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <sensor_msgs/PointCloud.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_datatypes.h>
#include "robotino_motion/FollowAction.h"
#include "FollowModes.h"
#include "FollowStates.h"

#define PI 3.14159
#define sign(a) (((a) < 0) ? -1 : (((a) > 0) ? 1 : 0))

using namespace ros;
using namespace actionlib;
using namespace geometry_msgs;
using namespace robotino_motion;
using namespace sensor_msgs;	
	
class Follow
{

public:

	Follow(NodeHandle nh);
	~Follow();

	void shutdown();
	void spin();
	bool isActing();

private:

	/** Node related Variables and Functions */
	NodeHandle nh_;
	double min_linear_vel_;
	double max_linear_vel_;
	double linear_acc_;
	double min_angular_vel_;
	double max_angular_vel_;
	double angular_acc_;
	double percentage_acc_;

	void readParameters(NodeHandle& nh);

	/** Follow Action related Variables and Functions */ 	
	SimpleAction<FollowAction> server_;
	FollowGoal goal_;
	FollowFeedback feedback_;
	FollowResult result_;

	void executeCallback(const FollowGoalConstPtr& goal);
	void preemptCallback();
	bool acceptNewGoal(const FollowGoalConstPtr& goal);

	/** Distance Sensor Topic Subscriber related Variables and Functions */
	Subscriber dist_sensors_sub_;
	PointCloud dist_sensors_msg_;
	bool dist_sensors_setted_;

	void distSensorsCallback(const PointCloud& msg);

	/** Topic Publisher related Variables and Functions */
	Publisher cmd_vel_pub_;
	Twist cmd_vel_msg_;

	void setVelocity(double vel_x, double vel_y, double vel_phi);
	void publishVelocity();

	/** Movement related Variables and Functions */
	FollowState state_;
	int left_ir_index_, right_ir_index_;
	int lateral_left_ir_index_, lateral_right_ir_index_; // used only in modes that uses two modes at the same time
	float left_ir_value_, right_ir_value_;
	float lateral_left_ir_value_, lateral_right_ir_value_; // used only in modes that uses two modes at the same time
	FollowMode mode_;
	bool positive_way_;

	void executeEmergencyStop();	
	void controlLoop();

};

#endif /* FOLLOW_SERVER_H_ */
