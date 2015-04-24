/**
 *  Store.h
 *
 *  Version: 1.1.0.0
 *  Created on: 02/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef STORE_CLIENT_H_
#define STORE_CLIENT_H_

#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "robotino_motion/StoreAction.h"
#include "Colors.h"
#include "StoreStates.h"

using namespace actionlib;
using namespace boost;
using namespace robotino_motion;
using namespace ros;
	
class Store
{

public:

	Store();
	~Store();

	void shutdown();
	bool checkServer();
	void sendGoal(const StoreGoal& goal);
	void sendGoal(Color color);
	bool isServerActing();

private:

	StoreState state_;
	SimpleAction<StoreAction> client_;

	void activeCallback();
	void feedbackCallback(const StoreFeedbackConstPtr& feedback);
	void doneCallback(const SimpleGoalState& state, const StoreResultConstPtr& result);

};

#endif /* STORE_CLIENT_H_ */
