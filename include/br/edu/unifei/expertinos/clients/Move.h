/**
 *  Move.h
 *
 *  Version: 1.1.0.0
 *  Created on: 23/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef MOVE_CLIENT_H_
#define MOVE_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/MoveAction.h"
#include "MovePathModes.h"
#include "MoveVelocityModes.h"
#include "MoveStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Move
{

public:

	Move();
	~Move();

	void shutdown();
	bool checkServer();
	void sendGoal(const MoveGoal& goal);
	void sendGoal(double delta_x, double delta_y, double delta_phi, MovePathMode path_mode, MoveVelocityMode velocity_mode);
	bool isServerActing();

private:

	MoveState state_;
	SimpleAction<MoveAction> client_;

	void activeCallback();
	void feedbackCallback(const MoveFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const MoveResultConstPtr& result);

};

#endif /* MOVE_CLIENT_H_ */
