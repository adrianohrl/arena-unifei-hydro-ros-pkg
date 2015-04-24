/**
 *  RotateStates.h
 *
 *  Version: 1.0.0.0
 *  Created on: 20/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ROTATESTATES_H_
#define ROTATESTATES_H_

namespace RotateStates
{
	typedef enum 
	{
		IDLE, 
		ROTATING, 
		STOPPING,
		FINISHED
	} RS;
};

typedef RotateStates::RS RotateState;

#endif /* ROTATESTATES_H_ */
