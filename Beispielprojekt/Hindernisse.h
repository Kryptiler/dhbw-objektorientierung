#pragma once
class Hindernisse
{
public:
	Hindernisse();
	~Hindernisse();
	double get_x();
	double get_y();
	void scrollen(double scroll);
	void set_deadly(int d);
	int get_deadly();
private:
	bool da = true;
	int deadly;
	double x;
	double y;
};

