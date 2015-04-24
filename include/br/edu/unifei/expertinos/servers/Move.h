/**
 *  Move.h
 *
 *  Version: 1.1.0.0
 *  Created on: 23/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef MOVE_SERVER_H_
#define MOVE_SERVER_H_

#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Twist.h>
#include <tf/transform_datatypes.h>
#include "robotino_motion/MoveAction.h"
#include "MovePathModes.h"
#include "MoveVelocityModes.h"
#include "MoveStates.h"

#define PI 3.14159
#define sign(a) (((a) < 0) ? -1 : (((a) > 0) ? 1 : 0))

#define INCREASE_VELOCITY 1
#define KEEP_CONSTANT_VELOCITY 0
#define DECREASE_VELOCITY -1

using namespace ros;
using namespace actionlib;
using namespace nav_msgs;
using namespace geometry_msgs;
using namespace robotino_motion;
	
class Move
{

public:

	Move(NodeHandle nh);
	~Move();

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
	double percentage_acc_;

	void readParameters(NodeHandle& nh);

	/** Move Action related Variables and Functions */ 	
	SimpleAction<MoveAction> server_;
	MoveGoal goal_;
	MoveFeedback feedback_;
	MoveResult result_;

	void executeCallback(const MoveGoalConstPtr& goal);
	void preemptCallback();
	bool acceptNewGoal(const MoveGoalConstPtr& goal);

	/** Topic Subscribers related Variables and Functions */
	Subscriber odom_sub_;
	Odometry current_odom_msg_;
	double curr_x_, curr_y_, curr_phi_, prev_phi_;
	Odometry start_odom_msg_;	
	double start_x_, start_y_, start_phi_;
	bool odom_setted_;

	void odomCallback(const OdometryConstPtr& msg);

	/** Topic Publisher related Variables and Functions */
	Publisher cmd_vel_pub_;
	Twist cmd_vel_msg_;
	double vel_x_, vel_y_, vel_phi_;

	void setVelocity(double vel_x, double vel_y, double vel_phi);
	void publishVelocity();

	/** Movement related Variables and Functions */
	MoveState state_;
	double dist_moved_x_, dist_moved_y_, dist_moved_phi_;
	double total_dist_x_, total_dist_y_, total_dist_phi_;
	double acceleration_x_, acceleration_y_, acceleration_phi_;
	MovePathMode path_mode_;
	MoveVelocityMode velocity_mode_;

	void executeEmergencyStop();	
	void controlLoop();
	void computeVelocities(double dist_moved_percentage, double total_dist_percentage, int acc_sign);
	double getComponentVelocity(double dist_moved, double total_dist);
	double getComponentVelocity(double dist_moved, double total_dist, double acceleration);
};

#endif /* MOVE_SERVER_H_ */
