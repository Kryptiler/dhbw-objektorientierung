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
	if (y > 880)			//Charakter auf dem Boden
	{
		y = 880;
		v_y = 0;
	}
	if (jump==false)
	{
		if (y < 880)
		{
			v_y += a_down * 0.3;		//linear beschleunigtes Fallen
			a_down++;
		}
		else
		{
			a_down = 0;
			jump = true;
			if (richtung==true)			//landet im Stehen
			{
				animation = 0;			//Stehen nach rechts
			}
			else
			{
				animation = 60;			//Stehen nach links
			}
		}
	}
}

double Maincharacter::right(double speed)
{
	richtung = true;
	score += speed;
	animation++;
	if (animation == 40||animation>=60)
	{
		animation = 0;
	}
	if (x+speed>=1200)			//Hintergrund scrollt
	{
		return speed;
	}
	else
	{
		x += speed;
		return 0;
	}
}

double Maincharacter::left(double speed)
{
	richtung = false;
	score -= speed;
	animation++;
	if (animation < 60 || animation == 100 || animation>=110)
	{
		animation = 60;
	}
	if (x - speed <= 480)		//Hintergrund scrollt
	{
		return -speed;
	}
	else
	{
		x -= speed;
		return 0;
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
			animation = 50;			//Sprung nach rechts
		}
		else
		{
			animation = 100;		//Sprung nach links
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

void Maincharacter::reset()
{
	this->x = 500;
	this->y = 880;
	this->score = 0;
	this->animation = 0;
}

int Maincharacter::get_animation()
{
	return this->animation/10;			//Neues Bild alle 10 Frames
}

int Maincharacter::get_score()
{
	return this->score;
}