#pragma once
class Maincharacter
{
public:
	Maincharacter();
	~Maincharacter();
	void bewege();
	void right(double speed);
	void left(double speed);
	void sprung();
	double get_x();
	double get_y();

private:
	double x;
	double y;
	double v_y = 0;
	double a_down = 0;
	int animation = 0;
	bool jump = true;
};

