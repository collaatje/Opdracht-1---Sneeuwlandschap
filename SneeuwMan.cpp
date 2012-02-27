/*
 * SneeuwMan.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Tim
 */

#include "SneeuwMan.hpp"

//constructor
SneeuwMan::SneeuwMan(int positionX, int positionY)
{
	// Klasse-attributen initialiseren
	this->positionX = positionX;
	this->positionY = positionY;
}

// beweeg de sneeuwman in de richting "direction" < 0 is links; > 0 is rechts
void SneeuwMan::move( int direction )
{
	this->positionX += direction;
}

// tekent een SneeuwMan
void SneeuwMan::draw()
{
	// Stel de kleur in op grijs #777777
	maSetColor(0x777777);

	// Teken het hoofd van de sneeuwpop
	maFillRect(this->positionX+10, this->positionY-70, 20, 20);
	// Teken het lichaam van de sneeuwpop
	maFillRect(this->positionX, this->positionY-50, 40, 50);
}
