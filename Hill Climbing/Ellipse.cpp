#include "Ellipse.h"

Ellipse::Ellipse()
{

}
Ellipse::Ellipse(Vector2f const& _position,Vector2f const& _size,float const& _angle,Color const& _color)
{
	position=_position;
	size=_size/2.f;
	angle=_angle;
	color=_color;

	computeFocus() ;
}
void Ellipse::computeFocus()
{
	a = max(size.x,size.y) ;
	float c = sqrt(size.x*size.x - size.y*size.y) ;
	F1 = position + Vector2f(c*cos(rad(angle)),c*sin(rad(angle))) ;
	F2 = position - Vector2f(c*cos(rad(angle)),c*sin(rad(angle))) ;
}

void Ellipse::move(Vector2f _translation)
{
	position += _translation ;
}
void Ellipse::rotate(float _angle)
{
	angle += _angle ;
}
void Ellipse::scale(Vector2f _factor)
{
	size += _factor ;
}


void Ellipse::addToImage(Image &image)
{
	for(int i(max(0.f,position.x-a)) ; i < min((float)image.getSize().x,position.x+a) ; i++)
	{
		for(int j(max(0.f,position.y-a)) ; j < min((float)image.getSize().y,position.y+a) ; j++)
		{
			if(Distance(F1,Vector2f(i,j))+Distance(F2,Vector2f(i,j))<2*size.x)
			{
				image.setPixel(i,j,Color::Color( color.a/255.f*color.r + (1-color.a/255.f)*image.getPixel(i,j).r, 
												color.a/255.f*color.g + (1-color.a/255.f)*image.getPixel(i,j).g,
												color.a/255.f*color.b + (1-color.a/255.f)*image.getPixel(i,j).b,
												255)) ;
			}
		}
	}
}


