/**
 *  Translate.h
 *
 *  Version: 1.1.0.0
 *  Created on: 02/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef TRANSLATE_CLIENT_H_
#define TRANSLATE_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/TranslateAction.h"
#include "TranslateStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Translate
{

public:

	Translate();
	~Translate();

	void shutdown();
	bool checkServer();
	void sendGoal(const TranslateGoal& goal);
	void sendGoal(double move_x, double move_y);
	bool isServerActing();

private:

	TranslateState state_;
	SimpleAction<TranslateAction> client_;

	void activeCallback();
	void feedbackCallback(const TranslateFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const TranslateResultConstPtr& result);

};

#endif /* TRANSLATE_CLIENT_H_ */
