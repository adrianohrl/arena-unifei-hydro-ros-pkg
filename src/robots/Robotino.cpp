/**
 *  Robotino.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 16/03/2015
 *  Modified on: 01/04/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "br/edu/unifei/expertinos/robots/Robotino.h"

using namespace br::edu::unifei::expertinos::robots;

/**
 *
 */
Robotino::Robotino(ros::NodeHandle nh) : Festo(nh, "robotino_", "robotino/", true) {
	float directions[] = {160.0, 120.0, 80.0, 40.0,  0.0, -40.0, -80.0, -120.0, -160.0};
	DISTANCE_SENSORS_DIRECTION.assign(directions, directions + NUMBER_OF_DISTANCE_SENSORS);
	
}

/**
 *
 */
Robotino::Robotino(ros::NodeHandle nh, std::string number) : Festo(nh, "robotino_" + number + "_", "robotino/" + number + "/", false) {
	float directions[] = {160.0, 120.0, 80.0, 40.0,  0.0, -40.0, -80.0, -120.0, -160.0};
	DISTANCE_SENSORS_DIRECTION.assign(directions, directions + NUMBER_OF_DISTANCE_SENSORS);
	
}

/**
 *
 */
Robotino::~Robotino() {
	
}

/**
 *
 */
int Robotino::getNumberOfDistanceSensors() const {
	return Robotino::NUMBER_OF_DISTANCE_SENSORS;
}

/**
 *
 */
std::vector<float> Robotino::getDistanceSensorsDirection() const
{

}

/**
 *
 */
float Robotino::getDistanceSensorDirection(int index) const
{

}
