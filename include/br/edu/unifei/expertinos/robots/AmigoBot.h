/**
 *  AmigoBot.h
 *
 *  Version: 1.0.0.0
 *  Created on: 16/03/2015
 *  Modified on: 01/04/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef AMIGOBOT_H_
#define AMIGOBOT_H_

#include "br/edu/unifei/expertinos/robots/Pioneer.h"

namespace br {

	namespace edu {

		namespace unifei {

			namespace expertinos {

				namespace robots {

					class AmigoBot : public Pioneer {

					public:

						AmigoBot(ros::NodeHandle nh);
						AmigoBot(ros::NodeHandle nh, std::string number);
						~AmigoBot();

						static const int NUMBER_OF_DISTANCE_SENSORS = 8;
	
						int getNumberOfDistanceSensors() const;

					};
			
				}
		
			}

		}

	}

}

#endif /* AMIGOBOT_H_ */
