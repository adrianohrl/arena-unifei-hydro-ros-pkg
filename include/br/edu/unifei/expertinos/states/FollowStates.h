/**
 *  FollowStates.h
 *
 *  Version: 1.0.0.0
 *  Created on: 20/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef FOLLOWSTATES_H_
#define FOLLOWSTATES_H_

namespace FollowStates
{
	typedef enum 
	{
		IDLE, 
		FOLLOWING, 
		STOPPING,
		FINISHED
	} FS;
};

typedef FollowStates::FS FollowState;

#endif /* FOLLOWSTATES_H_ */
