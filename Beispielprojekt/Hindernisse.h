#pragma once
class Hindernisse
{
public:
	Hindernisse();
	~Hindernisse();
	double get_x();
	double get_y();
	void scrollen(double scroll);
private:
	bool da = true;
	double x;
	double y;
};

