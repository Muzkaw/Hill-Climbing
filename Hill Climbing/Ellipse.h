//This file is part of Hill Climbing(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include "Utility.h"

using namespace std ;
using namespace sf ;

class Ellipse
{
public:
	Ellipse() ;
	Ellipse(Vector2f const& _position, Vector2f const& _size,float const& _angle,Color const& _color);
	void computeFocus() ;

	void move(Vector2f _translation) ;
	void rotate(float _angle) ;
	void scale(Vector2f _factor) ;
	Color color ;

	void addToImage(Image &image) ;
	void removeFromImage(Image &image) ;

private :
	Vector2f position ;
	Vector2f size ;
	float angle ;

	Vector2f F1 ;
	Vector2f F2 ;

	float a ;
};

