/*
 * SneeuwVlok.cpp
 *
 *  Created on: 27 feb. 2012
 *      Author: Tim
 */

#include "SneeuwVlok.hpp"

//constructor
SneeuwVlok::SneeuwVlok(int positionX, int positionY)
{
	// Klasse-attributen initialiseren
	this->positionX = positionX;
	this->positionY = positionY;
	this->dead = false; // sneeuwvlok begint levend

	// Restdeling om maximaal 10px te genereren
	this->size = rand() % 10; // initialiseer de size met een random grootte
}

// Tekent een SneeuwVlok
void SneeuwVlok::draw()
{
	// Stel de kleur in op wit #ffffff
	maSetColor(0xffffff);

	// Teken de sneeuwvlok
	maFillRect(this->positionX, this->positionY, this->size, this->size);
}

// Verandert de positionY van de SneeuwVlok
void SneeuwVlok::fall( int groundLevel )
{
	// Laat de sneeuwvlok 5 px vallen
	this->positionY += 5;

	// Als de sneeuwvlok de grond raakt, zet de dead-status op true
	if(this->positionY >= groundLevel)
		this->dead = true;
}

// Return de dead-status
bool SneeuwVlok::isDead()
{
	return dead;
}
