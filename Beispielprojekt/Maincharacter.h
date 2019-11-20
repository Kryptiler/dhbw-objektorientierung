#pragma once
class Maincharacter
{
public:
	Maincharacter();
	~Maincharacter();
	void bewege();
	void right(double speed, double& scroll, double& scroll2);
	void left(double speed, double& scroll, double& scroll2);
	void sprung();
	double get_x();
	double get_y();
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

