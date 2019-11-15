#include "stdafx.h"
#include "Maincharacter.h"


Maincharacter::Maincharacter()
{
	this->x = 500;
	this->y = 880;
}


Maincharacter::~Maincharacter()
{
}

void Maincharacter::bewege()
{
	y += v_y;
	if (y > 880)
	{
		y = 880;
	}
	if (jump==false)
	{
		if (y < 880)
		{
			v_y += a_down * 0.3;
			a_down++;
		}
		else
		{
			a_down = 0;
			jump = true;
			if (richtung==true)
			{
				animation = 0;
			}
			else
			{
				animation = 60;
			}
		}
	}
}

void Maincharacter::right(double speed, double& scroll, double& scroll2)
{
	richtung = true;
	animation++;
	if (animation == 40||animation>=60)
	{
		animation = 0;
	}
	if (x+speed>=1200)
	{
		scroll = scroll - speed;
		if (scroll <= -2990)
		{
			scroll = 2990;
		}
		scroll2 = scroll2 - speed;
		if (scroll2 <= -2990)
		{
			scroll2 = 2990;
		}
	}
	else
	{
		x += speed;
		
	}
}

void Maincharacter::left(double speed, double& scroll, double& scroll2)
{
	richtung = false;
	animation++;
	if (animation < 60 || animation == 100 || animation>=110)
	{
		animation = 60;
	}
	if (x - speed <= 480)
	{
		scroll = scroll + speed;
		if (scroll>= 2990)
		{
			scroll = -2990;
		}
		scroll2 = scroll2 + speed;
		if (scroll2 >= 2990)
		{
			scroll2 = -2990;
		}
	}
	else
	{
		x -= speed;
	}
}

void Maincharacter::sprung()
{
	if (jump == true)
	{
		v_y = -30;
		jump = false;
		if (richtung==true)
		{
			animation = 50;
		}
		else
		{
			animation = 100;
		}
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

int Maincharacter::get_animation()
{
	return this->animation/10;
}


