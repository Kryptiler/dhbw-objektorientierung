#include "stdafx.h"
#include "Hindernisse.h"


Hindernisse::Hindernisse()
{
	this->x = 1980;
	this->y = 775;
}


Hindernisse::~Hindernisse()
{
}

double Hindernisse::get_x()
{
	if (da==true)
	{
		return this->x;
	}
	else
	{
		return -100;
	}
}

double Hindernisse::get_y()
{
	return this->y;
}

void Hindernisse::scrollen(double scroll)
{
	x -= scroll;
}

void Hindernisse::set_deadly(bool d)
{
	this->deadly = d;
}

bool Hindernisse::get_deadly()
{
	return this->deadly;
}
