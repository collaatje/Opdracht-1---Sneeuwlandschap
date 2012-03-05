/*
 * SneeuwLandschap.cpp
 *
 *  Created on: 8 feb. 2012
 *      Author: acer
 */

#include "SneeuwLandschap.hpp"


//globale variabelen voor breedte en hoogte van het scherm
int screenWidth;
int screenHeight;


//constructor
SneeuwLandschap::SneeuwLandschap()
{
	//sla schermgrootte op in globale variabelen
	MAExtent screenSize = maGetScrSize();
	screenWidth = EXTENT_X( screenSize );
	screenHeight = EXTENT_Y( screenSize );

	//stel sneeuwhoogte in (vanaf bodem)
	this->sneeuwHoogte = 30;

	//maak een nieuwe sneeuwman
	this->sneeuwMan = new SneeuwMan( screenWidth / 2, screenHeight - this->sneeuwHoogte );
}

SneeuwLandschap::~SneeuwLandschap()
{
	delete sneeuwMan;

	for(int i=0; i < sneeuwVlokArray.size(); i++)
	{
		delete sneeuwVlokArray[i];
		sneeuwVlokArray.remove(i);
	}
}


//wordt aangeroepen als er input is (druk op de toets, touch van scherm)
void SneeuwLandschap::run( MAEvent event )
{
	//als er een key is ingetoetst
	if( event.type == EVENT_TYPE_KEY_PRESSED )
	{
		//pak de key code
		int key = maGetKeys();

		//kijk voor linkertoets
		if( key == MAKB_LEFT )
			this->sneeuwMan->move( -6 );	//beweeg sneeuwman -6 pixels

		//kijk voor rechtertoets
		if( key == MAKB_RIGHT )
			this->sneeuwMan->move( 6 );		//beweeg sneeuwman 6 pixels
	}

	// Restdeling doen om maximaal (screenWidth-10)px te genereren
	int randX = rand() % (screenWidth-10);

	//voeg een sneeuwvlok toe
	sneeuwVlokArray.add(new SneeuwVlok(randX, 0));

	//laat alle sneeuwvlokken vallen
	for(int i=0; i < sneeuwVlokArray.size(); i++)
	{
		// roep de fall-methode aan met als parameter de yPositie van de grond/sneeuw
		sneeuwVlokArray[i]->fall(screenHeight - this->sneeuwHoogte);

		// Als de sneeuwvlok dood is, verwijder hem dan uit de array
		if(sneeuwVlokArray[i]->isDead())
		{
			delete sneeuwVlokArray[i];
			sneeuwVlokArray.remove(i);
		}
	}
}


//wordt elke "tick" aangeroepen om het winterlandschap, sneeuwman en sneeuwvlokken te tekenen
void SneeuwLandschap::draw()
{
	//kleur de lucht blauw
	maSetColor( 0x0055ff );
	maFillRect( 0, 0, screenWidth, screenHeight );

	//maak sneeuw op de grond, a.d.h.v. sneeuwHoogte
	maSetColor( 0xffffff );
	maFillRect( 0, screenHeight - this->sneeuwHoogte, screenWidth, this->sneeuwHoogte );

	this->sneeuwMan->draw();

	//teken alle sneeuwvlokken
	for(int i=0; i < sneeuwVlokArray.size(); i++)
	{
		sneeuwVlokArray[i]->draw();
	}
}


