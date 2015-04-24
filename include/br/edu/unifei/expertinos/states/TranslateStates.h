/**
 *  TranslateStates.h
 *
 *  Version: 1.0.0.0
 *  Created on: 20/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef TRANSLATESTATES_H_
#define TRANSLATESTATES_H_

namespace TranslateStates
{
	typedef enum 
	{
		IDLE, 
		TRANSLATING, 
		STOPPING,
		FINISHED
	} TS;
};

typedef TranslateStates::TS TranslateState;

#endif /* TRANSLATESTATES_H_ */
