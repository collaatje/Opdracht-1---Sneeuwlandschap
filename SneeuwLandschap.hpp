/*
 * SneeuwLandschap.hpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#ifndef SNEEUWLANDSCHAP_HPP_
#define SNEEUWLANDSCHAP_HPP_

//deze header hebben we nodig voor de functie rand()
#include <mastdlib.h>
#include <ma.h>
#include <MAUtil/Vector.h>


#include "SneeuwMan.hpp"
#include "SneeuwVlok.hpp"



class SneeuwLandschap
{
private:
	int sneeuwHoogte;
	SneeuwMan* sneeuwMan;

	MAUtil::Vector<SneeuwVlok*> sneeuwVlokArray;

public:
	SneeuwLandschap();
	virtual ~SneeuwLandschap();
	void draw();
	void run( MAEvent event );
};


#endif /* SNEEUWLANDSCHAP_HPP_ */
