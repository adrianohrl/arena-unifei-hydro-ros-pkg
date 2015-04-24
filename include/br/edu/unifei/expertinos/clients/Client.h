/**
 *  Move.h
 *
 *  Version: 1.1.0.0
 *  Created on: 23/11/2014
 *  Modified on: 24/04/2015
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include <ros/ros.h>
#include <string>
#include <actionlib/client/simple_action_client.h>
#include <actionlib/client/terminal_state.h>
#include "br/edu/unifei/expertinos/states/States.h"

namespace br {

	namespace edu {

		namespace unifei {

			namespace expertinos {

				namespace clients {

					template <class Action>
					class Client {

					public:

						Client(std::string ns);
						~Client();

						bool checkServer();
						bool isServerActing() const;
						states::States getState() const;

					protected:

						void sendGoal(const actionlib::Goal& goal);
						void setState(states::States state);

					private:

						template<class Action> actionlib::SimpleActionClient<Action> client_;
						states::State state_;

						virtual void activeCallback() = 0;
						virtual void feedbackCallback(const actionlib::FeedbackConstPtr& feedback) = 0;
						virtual void doneCallback(const actionlib::SimpleGoalState& state, const actionlib::ResultConstPtr& result) = 0;

					};

				}
		
			}
		
		}

	}

}

#endif /* CLIENT_H_ */
