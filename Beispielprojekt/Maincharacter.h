#pragma once
class Maincharacter
{
public:
	Maincharacter();
	~Maincharacter();
	void bewege();
	void right();
	void left();
	void draw();
private:
	double x;
	double y;
	double v_x;
	double v_y;
	int animation;
};

