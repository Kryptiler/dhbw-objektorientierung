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
	double x = 0;
	double y = 0;
	double v_x = 0;
	double v_y = 0;
	int animation = 0;
};

