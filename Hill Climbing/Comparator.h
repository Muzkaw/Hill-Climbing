//This file is part of Hill Climbing(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include "Picture.h" ;
#include "Utility.h"

using namespace std ;
using namespace sf ;

class Comparator
{
public:
	Comparator(Image *_model, Image *_current);

	float compare() ;

private:
	Image *model ;
	Image *current ;
};

