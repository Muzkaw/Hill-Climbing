#include "Comparator.h"


Comparator::Comparator(Image *_model,Image *_current)
{
	model=_model;
	current=_current;
}

float Comparator::compare()
{
	float fitness = 0 ;

	for(int i(0) ; i < model->getSize().x ; i++)
	{
		for(int j(0) ; j < model->getSize().y ; j++)
		{
			fitness += abs(model->getPixel(i,j).r - current->getPixel(i,j).r) ;
			fitness += abs(model->getPixel(i,j).g - current->getPixel(i,j).g) ;
			fitness += abs(model->getPixel(i,j).b - current->getPixel(i,j).b) ;
		}
	}

	fitness /= (model->getSize().x*model->getSize().y*3) ;
	return fitness ;
}