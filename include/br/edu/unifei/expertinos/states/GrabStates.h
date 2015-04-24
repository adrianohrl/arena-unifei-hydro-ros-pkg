/**
 *  GrabStates.h
 *
 *  Version: 1.0.0.0
 *  Created on: 20/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef GRABSTATES_H_
#define GRABSTATES_H_

namespace GrabStates
{
	typedef enum 
	{
		IDLE, 
		GRABING, 
		STOPPING,
		FINISHED
	} GS;
};

typedef GrabStates::GS GrabState;

#endif /* GRABSTATES_H_ */
