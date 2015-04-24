/**
 *  Grab.h
 *
 *  Version: 1.1.0.0
 *  Created on: 02/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef GRAB_CLIENT_H_
#define GRAB_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/GrabAction.h"
#include "Colors.h"
#include "GrabStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Grab
{

public:

	Grab();
	~Grab();

	void shutdown();
	bool checkServer();
	void sendGoal(const GrabGoal& goal);
	void sendGoal(Color color);
	bool isServerActing();

private:

	GrabState state_;
	SimpleAction<GrabAction> client_;

	void activeCallback();
	void feedbackCallback(const GrabFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const GrabResultConstPtr& result);

};

#endif /* GRAB_CLIENT_H_ */
