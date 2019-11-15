#include "stdafx.h"
#include "Hindernisse.h"


Hindernisse::Hindernisse()
{
	this->x = 500;
	this->y = 1000;
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
