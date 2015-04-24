/**
 *  MovePathModes.h
 *
 *  Version: 1.0.0.0
 *  Created on: 23/11/2014
 *  Modified on: 23/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef MOVEPATHMODES_H_
#define MOVEPATHMODES_H_

namespace MovePathModes
{
	typedef enum
	{
	     	TRANSLATIONAL,
		ROTATIONAL,
		TRANSLATIONAL_AND_ROTATIONAL,
		TANGENT
	} MPM;
}

typedef MovePathModes::MPM MovePathMode;

#endif /* MOVEPATHMODES_H_ */
