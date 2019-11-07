#include "stdafx.h"
#include "Maincharacter.h"


Maincharacter::Maincharacter()
{
	this->x = 20;
	this->y = 800;
}


Maincharacter::~Maincharacter()
{
}

void Maincharacter::bewege()
{
	x += v_x;
	y += v_y;
	animation = animation + 1 % 6;
}

void Maincharacter::right()
{
	v_x = 1;
}

void Maincharacter::left()
{
	v_x = -1;
}

void Maincharacter::draw()
{

}


