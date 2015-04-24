/**
 *  MoveVelocityModes.h
 *
 *  Version: 1.0.0.0
 *  Created on: 23/11/2014
 *  Modified on: 24/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef MOVEVELOCITYMODES_H_
#define MOVEVELOCITYMODES_H_

namespace MoveVelocityModes
{
	typedef enum
	{
	     	CONSTANT,
		TRAPEZOIDAL,
		TRAPEZOIDAL_ONLY_ACC,
		TRAPEZOIDAL_ONLY_DEACC,
		TRIANGULAR,
		TRIANGULAR_ONLY_ACC,
		TRIANGULAR_ONLY_DEACC
	} MVM;
}

typedef MoveVelocityModes::MVM MoveVelocityMode;

#endif /* MOVEVELOCITYMODES_H_ */
