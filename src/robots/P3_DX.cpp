/**
 *  P3_DX.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 16/03/2015
 *  Modified on: 01/04/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "br/edu/unifei/expertinos/robots/P3_DX.h"

using namespace br::edu::unifei::expertinos::robots;

/**
 *
 */
P3_DX::P3_DX(ros::NodeHandle nh) : Pioneer(nh, "p3_dx_", "p3_dx/", false) {
	float directions[] = {90.0, 50.0, 30.0, 10.0, -10.0, -30.0, -50.0, -90.0, -90.0, -130.0, -150.0, -170.0, 170.0, 150.0, 130.0, 90.0};
	DISTANCE_SENSORS_DIRECTION.assign(directions, directions + NUMBER_OF_DISTANCE_SENSORS);
}

/**
 *
 */
P3_DX::P3_DX(ros::NodeHandle nh, std::string number) : Pioneer(nh, "p3_dx_" + number + "_", "p3_dx/" + number + "/", false) {
	float directions[] = {90.0, 50.0, 30.0, 10.0, -10.0, -30.0, -50.0, -90.0, -90.0, -130.0, -150.0, -170.0, 170.0, 150.0, 130.0, 90.0};
	DISTANCE_SENSORS_DIRECTION.assign(directions, directions + NUMBER_OF_DISTANCE_SENSORS);
}

/**
 *
 */
P3_DX::~P3_DX() {
	
}

/**
 *
 */
int P3_DX::getNumberOfDistanceSensors() const {
	return P3_DX::NUMBER_OF_DISTANCE_SENSORS;
}

/**
 *
 */
std::vector<float> P3_DX::getDistanceSensorsDirection() const
{

}

/**
 *
 */
float P3_DX::getDistanceSensorDirection(int index) const
{

}
