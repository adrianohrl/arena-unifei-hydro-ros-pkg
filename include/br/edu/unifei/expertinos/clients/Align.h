/**
 *  Align.h
 *
 *  Version: 1.1.0.0
 *  Created on: 02/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ALIGN_CLIENT_H_
#define ALIGN_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/AlignAction.h"
#include "AlignModes.h"
#include "AlignDistances.h"
#include "AlignStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Align
{

public:

	Align();
	~Align();

	void shutdown();
	bool checkServer();
	void sendGoal(const AlignGoal& goal);
	void sendGoal(AlignMode mode, AlignDistance distance);
	bool isServerActing();

private:

	AlignState state_;
	SimpleAction<AlignAction> client_;

	void activeCallback();
	void feedbackCallback(const AlignFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const AlignResultConstPtr& result);	

};

#endif /* ALIGN_CLIENT_H_ */
