#include "stdafx.h"
#include "Maincharacter.h"


Maincharacter::Maincharacter()
{
	this->x = 20;
	this->y = 1060;
}


Maincharacter::~Maincharacter()
{
}

void Maincharacter::bewege()
{
	y += v_y;
	if (y > 1060)
	{
		y = 1060;
	}
	animation = animation + 1 % 6;
	if (y < 1060)
	{
		v_y += a_down * 0.3;
		a_down++;
	}
	else
	{
		a_down = 0;
		jump = true;
	}
}

void Maincharacter::right(double speed)
{
	x += speed;
}

void Maincharacter::left(double speed)
{
	x -= speed;
}

void Maincharacter::sprung()
{
	if (jump == true)
	{
		v_y = -30;
		jump = false;
	}
}

double Maincharacter::get_x()
{
	return x;
}

double Maincharacter::get_y()
{
	return y;
}


