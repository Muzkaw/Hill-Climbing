//This file is part of Hill Climbing(GNU GPL) - https://www.youtube.com/user/Muzkaw.

#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std ;
using namespace sf ;

Vector2f randVector2f(Vector2f const& among) ;
Vector2f randVector2f(Vector2f const& min,Vector2f const& max) ;
float randfloat(float const& among) ;
float randfloat(float const& min,float const& max) ;
Color randColor() ;
Color randColor(Color base,float const& max,float const& min) ;

void coutVector2f(Vector2f const& u) ;

float rad(float deg) ;
float Distance(Vector2f const& u,Vector2f const& v) ;

void drawPoint(Vector2f const& p,float const& radius,RenderWindow &window,Color const& color);