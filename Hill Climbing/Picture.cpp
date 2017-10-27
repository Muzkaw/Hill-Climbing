#include "Picture.h"

Picture::Picture(string path, int _ellipse_nb,RenderWindow *_window)
{
	srand(time(NULL)) ;

	model.loadFromFile(path) ;
	
	ellipse_nb = _ellipse_nb ;
	size = Vector2f(model.getSize().x,model.getSize().y) ;
	current.create(size.x,size.y,Color::White) ;
	currentEvolved.create(size.x,size.y,Color::White) ;
	
	window=_window ;

	ellipse.push_back(Ellipse(randVector2f(size),randVector2f(size/2.f),randfloat(360),randColor())) ;

	fitness2=255 ;
	fitness1=255;
	no_evolution = 0 ;

	sprite.setScale(Vector2f(4,4)) ;
	sprite2.setScale(Vector2f(4,4));
	sprite2.setPosition(0,400) ;
	texture2.loadFromImage(model) ;
	sprite2.setTexture(texture2) ;
}

void Picture::computeFitness()
{
	fitness1=fitness2 ;
	fitness2 = 0 ;

	for(int i(0) ; i < model.getSize().x ; i++)
	{
		for(int j(0) ; j < model.getSize().y ; j++)
		{
			fitness2 += abs((float)model.getPixel(i,j).r - (float)currentEvolved.getPixel(i,j).r) ;
			fitness2 += abs((float)model.getPixel(i,j).g - (float)currentEvolved.getPixel(i,j).g) ;
			fitness2 += abs((float)model.getPixel(i,j).b - (float)currentEvolved.getPixel(i,j).b) ;
		}
	}

	fitness2 /= (model.getSize().x*model.getSize().y*3*2.55) ;
}

void Picture::mutate()
{
	int i = ellipse.size()-1 ;
	
	buffer = ellipse[i] ;
	
	ellipse[i].move(randVector2f(Vector2f(-5,-5),Vector2f(5,5)));
	ellipse[i].scale(randVector2f(Vector2f(-5,-5),Vector2f(5,5)));
	ellipse[i].rotate(randfloat(-5,5));
	ellipse[i].computeFocus() ;

	ellipse[i].color.r += randfloat(-10,10) ;
	ellipse[i].color.g += randfloat(-10,10) ;
	ellipse[i].color.b += randfloat(-10,10) ;
	ellipse[i].color.a += randfloat(-10,10) ;

	currentEvolved = current ;
	ellipse[i].addToImage(currentEvolved) ;

	computeFitness() ;
	
	if(fitness2 >= fitness1) //worse fitness
	{
		fitness2 = fitness1;
		no_evolution++ ;
		if(!used) { ellipse[i] = Ellipse(randVector2f(size),randVector2f(size/2.f),randfloat(360),randColor()) ; no_evolution=0 ; }
		else ellipse[i] = buffer ;
	}
	else //better fitness
	{
		cout<<"fitness = "<<fitness2<<" %"<<endl ;
		used = true ;
		no_evolution=0;
		draw() ;
	}
	if(no_evolution > 500) //finished evolving
	{
		if(!used) 
		{
			ellipse.pop_back() ; currentEvolved = current ;
		}
		else
		{
			currentEvolved = current ;
			buffer.addToImage(currentEvolved) ;
			current = currentEvolved ;
		}
		ellipse.push_back(Ellipse(randVector2f(size),randVector2f(size/2.f),randfloat(360),randColor())) ;
		cout<<"ellipse nb = "<<ellipse.size()<<endl;
		no_evolution=0;
		used = false ;
	}
}

void Picture::draw()
{
	texture.loadFromImage(currentEvolved) ;
	sprite.setTexture(texture) ;
	
	window->clear(Color::Black) ;

	window->draw(sprite) ;
	window->draw(sprite2) ;

	window->display() ;
}