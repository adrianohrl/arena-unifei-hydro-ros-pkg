/**
 *  Follow.h
 *
 *  Version: 1.1.0.0
 *  Created on: 02/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef FOLLOW_CLIENT_H_
#define FOLLOW_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/FollowAction.h"
#include "FollowModes.h"
#include "FollowStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Follow
{

public:

	Follow();
	~Follow();

	void shutdown();
	bool checkServer();
	void sendGoal(const FollowGoal& goal);
	void sendGoal(FollowMode mode, bool positive_way);
	bool isServerActing();

private:

	FollowState state_;
	SimpleAction<FollowAction> client_;

	void activeCallback();
	void feedbackCallback(const FollowFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const FollowResultConstPtr& result);

};

#endif /* FOLLOW_CLIENT_H_ */
