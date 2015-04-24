/**
 *  Color.h
 *
 *  Version: 1.0.0.0
 *  Created on: 13/11/2014
 *  Modified on: 13/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef COLOR_H_
#define COLOR_H_

namespace Colors
{
	typedef enum
	{
		RED, 
		GREEN, 
		BLUE, 
		YELLOW, 
		ORANGE, 
		PINK, 
		BLACK
	} C;
}

typedef Colors::C Color;

#endif /* COLOR_H_ */
