/**
 *  Festo.cpp
 *
 *  Version: 1.0.0.0
 *  Created on: 16/03/2015
 *  Modified on: 02/04/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#include "br/edu/unifei/expertinos/robots/Festo.h"

using namespace br::edu::unifei::expertinos::robots;

/**
 *
 */
Festo::Festo(ros::NodeHandle nh, std::string name, std::string ns, bool holonomic) : Robot(nh, name, ns, holonomic) {
	setPort("12080");
	dist_sub_ = nh.subscribe("/" + ns + "distance_sensors", 1, &Festo::distanceSensorsCallback, this);
}

/**
 *
 */
Festo::~Festo() {
	dist_sub_.shutdown();
}

/**
 *
 */
void Festo::distanceSensorsCallback(const sensor_msgs::PointCloudConstPtr& msg) {
	dist_values_.clear();
	for (int i = 0; i < getNumberOfDistanceSensors(); i++) {
		dist_values_.push_back(msg->points[i]);
	}
}

/**
 *
 */
std::vector<geometry_msgs::Point32> Festo::getDistanceSensorsValue() const {
	return dist_values_;
}

/**
 *
 */	
geometry_msgs::Point32 Festo::getDistanceSensorValue(int index) const {
	geometry_msgs::Point32 value;
	if (index >= 0 && index < getNumberOfDistanceSensors()) {
		value = dist_values_.at(index);
	}
	return value;
}
