//This file is part of Hill Climbing(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Ellipse.h" ;
#include "Utility.h"

using namespace std ;
using namespace sf ;

class Picture
{
public:
	Picture(string path, int _ellipse_nb, RenderWindow *_window);

	void computeFitness() ;
	void mutate() ;
	void render() ;

	void draw() ;

	Image model ;
	Image current ;
	Image currentEvolved ;


private:
	int ellipse_nb ;
	float fitness1 ;
	float fitness2 ;
	int no_evolution ;
	bool used ;

	Vector2f translation ;
	Vector2f scale ;
	float rotation ;
	Color color ;

	Vector2f size ;
	vector<Ellipse> ellipse;
	Ellipse buffer ;

	Texture texture ;
	Sprite sprite ;
	Texture texture2 ;
	Sprite sprite2 ;
	RenderWindow *window ;
};

