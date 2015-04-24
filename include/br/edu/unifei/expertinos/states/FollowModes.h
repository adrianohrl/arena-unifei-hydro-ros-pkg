/**
 *  FollowModes.h
 *
 *  Version: 1.0.0.0
 *  Created on: 13/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef FOLLOWMODES_H_
#define FOLLOWMODES_H_

namespace FollowModes
{
	typedef enum
	{
	     	ONE_CENTERED_LINE,
		TWO_SIDED_LINES,
		TWO_SQUARES,
		TWO_SIDED_WALLS,
		FRONT_SIDED_WALL,
		RIGHT_SIDED_WALL,
		LEFT_SIDED_WALL,
		BACK_SIDED_WALL
	} FM;
}

typedef FollowModes::FM FollowMode;

#endif /* FOLLOWMODES_H_ */
