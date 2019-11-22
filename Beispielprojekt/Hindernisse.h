#pragma once
class Hindernisse
{
public:
	Hindernisse();
	~Hindernisse();
	double get_x();
	double get_y();
	void scrollen(double scroll);
	void set_deadly(bool d);
	bool get_deadly();
private:
	bool da = true;
	bool deadly;
	double x;
	double y;
};

