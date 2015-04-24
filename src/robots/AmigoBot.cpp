/**
 *  AmigoBot.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 16/03/2015
 *  Modified on: 01/04/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "br/edu/unifei/expertinos/robots/AmigoBot.h"

using namespace br::edu::unifei::expertinos::robots;


/**
 *
 */
AmigoBot::AmigoBot(ros::NodeHandle nh) : Pioneer(nh, "amg_bot_", "amigobot/", false) {
	float directions[] = {90.0, 41.0, 15.0, -15.0, -41.0, -90.0, -145.0, 145.0};
	DISTANCE_SENSORS_DIRECTION.assign(directions, directions + NUMBER_OF_DISTANCE_SENSORS);
}

/**
 *
 */
AmigoBot::AmigoBot(ros::NodeHandle nh, std::string number) : Pioneer(nh, "amg_bot_" + number + "_", "amigobot/" + number + "/", false) {
	float directions[] = {90.0, 41.0, 15.0, -15.0, -41.0, -90.0, -145.0, 145.0};
	DISTANCE_SENSORS_DIRECTION.assign(directions, directions + NUMBER_OF_DISTANCE_SENSORS);
}

/**
 *
 */
AmigoBot::~AmigoBot() {
	
}

/**
 *
 */
int AmigoBot::getNumberOfDistanceSensors() const {
	return AmigoBot::NUMBER_OF_DISTANCE_SENSORS;
}

/**
 *
 */
std::vector<float> AmigoBot::getDistanceSensorsDirection() const
{

}

/**
 *
 */
float AmigoBot::getDistanceSensorDirection(int index) const
{

}
