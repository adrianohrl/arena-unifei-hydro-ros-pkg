/**
 *  Rotate.h
 *
 *  Version: 1.1.0.0
 *  Created on: 06/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROTATE_SERVER_H_
#define ROTATE_SERVER_H_

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_datatypes.h>
#include "robotino_motion/RotateAction.h"
#include "RotateStates.h"

#define PI 3.14159
#define sign(a) (((a) < 0) ? -1 : (((a) > 0) ? 1 : 0))

using namespace ros;
using namespace actionlib;
using namespace nav_msgs;
using namespace geometry_msgs;
using namespace robotino_motion;
	
class Rotate
{

public:

	Rotate(NodeHandle nh);
	~Rotate();

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

	/** Rotate Action related Variables and Functions */ 	
	SimpleAction<RotateAction> server_;
	RotateGoal goal_;
	RotateFeedback feedback_;
	RotateResult result_;

	void executeCallback(const RotateGoalConstPtr& goal);
	void preemptCallback();
	bool acceptNewGoal(const RotateGoalConstPtr& goal);

	/** Topic Subscribers related Variables and Functions */
	Subscriber odom_sub_;
	Odometry current_odom_msg_;
	Odometry start_odom_msg_;	
	bool odom_setted_;

	void odomCallback(const OdometryConstPtr& msg);

	/** Topic Publisher related Variables and Functions */
	Publisher cmd_vel_pub_;
	Twist cmd_vel_msg_;

	void setVelocity(double vel_x, double vel_y, double vel_phi);
	void publishVelocity();

	/** Movement related Variables and Functions */
	RotateState state_;
	double curr_x_, curr_y_, curr_phi_, prev_phi_;
	double dist_moved_x_, dist_moved_y_, dist_moved_phi_;
	double start_x_, start_y_, start_phi_;
	double forward_goal_phi_;

	void executeEmergencyStop();	
	void controlLoop();
};

#endif /* ROTATE_SERVER_H_ */
