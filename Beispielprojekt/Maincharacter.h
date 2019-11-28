#pragma once
class Maincharacter
{
public:
	Maincharacter();
	~Maincharacter();
	void bewege();
	double right(double speed);
	double left(double speed);
	void sprung();
	double get_x();
	double get_y();
	void reset();
	int get_animation();
	int get_score();

private:
	double x;
	double y;
	double v_y = 0;
	double a_down = 0;
	int animation = 0;
	bool jump = true;
	bool richtung = true; //true=rechts, false=links
	int score = 0;
};

