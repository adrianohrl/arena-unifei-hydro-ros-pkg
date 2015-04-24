/**
 *  Robot.h
 *
 *  Version: 1.0.0.0
 *  Created on: 11/03/2015
 *  Modified on: 02/04/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <ros/ros.h>
#include <vector>
#include <string>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/PointCloud.h> // geometry_msgs/Point32's header is already in here
#include <geometry_msgs/Twist.h>
#include <tf/transform_datatypes.h>

namespace br {

	namespace edu {

		namespace unifei {

			namespace expertinos {

				namespace servers {

					class Server {

					public:

						Server(ros::NodeHandle nh, std::string name, std::string ns, bool holonomic = false);
						~Server();

						void spin();
						void spinOnce();
						std::string getName() const;
						std::string getHostname() const;
						std::string getPort() const;
						bool isHolonomic() const;
						void setVelocity(double vel_x, double vel_y, double vel_phi);
						void resetOdometry();

						double getOdometry_X();
						double getOdometry_Y();
						double getOdometry_PHI();
						

						virtual int getNumberOfDistanceSensors() const = 0;
						virtual std::vector<geometry_msgs::Point32> getDistanceSensorsValue() const = 0;
						virtual geometry_msgs::Point32 getDistanceSensorValue(int index) const = 0;
						virtual std::vector<float> getDistanceSensorsDirection() const = 0;
						virtual float getDistanceSensorDirection(int index) const = 0;

					protected:
	
						void setHostname(std::string hostname);
						void setPort(std::string port);
						void setHolonomic(bool holonomic);

					private:

						ros::NodeHandle nh_;
						std::string name_;
						std::string hostname_;
						std::string port_;
						geometry_msgs::Twist cmd_vel_msg_;
						ros::Publisher cmd_vel_pub_;
						ros::Subscriber odom_sub_;
						bool odom_setted_;
						bool holonomic_;
						double min_linear_vel_, max_linear_vel_;
						double min_angular_vel_, max_angular_vel_;
						double start_x_, start_y_, start_phi_;
						double curr_x_, curr_y_, curr_phi_, prev_phi_;
						double disp_x_, disp_y_, disp_phi_;

						void readParameters();
						void publishVelocity();
						void odometryCallback(const nav_msgs::OdometryConstPtr& msg);
	
						virtual void distanceSensorsCallback(const sensor_msgs::PointCloudConstPtr& msg) = 0;

					};
			
				}

			}

		}

	}

}

#endif /* ROBOT_H_ */
