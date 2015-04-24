/**
 *  AlignModes.h
 *
 *  Version: 1.0.0.0
 *  Created on: 13/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ALIGNMODES_H_
#define ALIGNMODES_H_

namespace AlignModes
{
	typedef enum
	{
	     	FRONT, 
		RIGHT, 
		LEFT, 
		BACK,
		FRONT_RIGHT,
		FRONT_LEFT,
		BACK_RIGHT,
		BACK_LEFT
	} AM;
}

typedef AlignModes::AM AlignMode;

#endif /* ALIGNMODES_H_ */
