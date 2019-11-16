#include "stdafx.h"
#include "Hindernisse.h"


Hindernisse::Hindernisse()
{
	this->x = 1200;
	this->y = 775;
}


Hindernisse::~Hindernisse()
{
}

double Hindernisse::get_x()
{
	return this->x;
}

double Hindernisse::get_y()
{
	return this->y;
}
