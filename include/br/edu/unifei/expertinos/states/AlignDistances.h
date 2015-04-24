/**
 *  AlignDistances.h
 *
 *  Version: 1.0.0.0
 *  Created on: 13/11/2014
 *  Modified on: 20/11/2014
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Expertinos UNIFEI (expertinos.unifei@gmail.com)
 */

#ifndef ALIGNDISTANCES_H_
#define ALIGNDISTANCES_H_

namespace AlignDistances
{
	typedef enum
	{
	     	CLOSE, 
		NORMAL, 
		FAR
	} AD;
}

typedef AlignDistances::AD AlignDistance;

#endif /* ALIGNDISTANCES_H_ */
