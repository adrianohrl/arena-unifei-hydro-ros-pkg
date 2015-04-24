/**
 *  AlignStates.h
 *
 *  Version: 1.0.0.0
 *  Created on: 20/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ALIGNSTATES_H_
#define ALIGNSTATES_H_

namespace AlignStates
{
	typedef enum 
	{
		IDLE, 
		ALIGNING, 
		STOPPING,
		FINISHED
	} AS;
};

typedef AlignStates::AS AlignState;

#endif /* ALIGNSTATES_H_ */
