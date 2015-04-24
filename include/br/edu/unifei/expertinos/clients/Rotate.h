/**
 *  Rotate.h
 *
 *  Version: 1.1.0.0
 *  Created on: 02/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROTATE_CLIENT_H_
#define ROTATE_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/RotateAction.h"
#include "RotateStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Rotate
{

public:

	Rotate();
	~Rotate();

	void shutdown();
	bool checkServer();
	void sendGoal(const RotateGoal& goal);
	void sendGoal(double move_phi);
	bool isServerActing();

private:

	RotateState state_;
	SimpleAction<RotateAction> client_;

	void activeCallback();
	void feedbackCallback(const RotateFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const RotateResultConstPtr& result);

};

#endif /* ROTATE_CLIENT_H_ */
