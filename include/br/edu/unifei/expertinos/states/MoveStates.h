/**
 *  MoveStates.h
 *
 *  Version: 1.0.0.0
 *  Created on: 23/11/2014
 *  Modified on: 23/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef MOVESTATES_H_
#define MOVESTATES_H_

namespace MoveStates
{
	typedef enum 
	{
		IDLE, 
		MOVING, 
		STOPPING,
		FINISHED
	} MS;
};

typedef MoveStates::MS MoveState;

#endif /* MOVESTATES_H_ */
