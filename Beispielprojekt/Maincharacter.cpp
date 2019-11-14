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
			animation = 0;
		}
	}
}

void Maincharacter::right(double speed, double& scroll, double& scroll2)
{
	animation++;
	if (animation == 40||animation>=60)
	{
		animation = 0;
	}
	if (x+speed>=1440)
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
		animation = 50;
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


