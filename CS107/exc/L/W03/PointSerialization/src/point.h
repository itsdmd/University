#pragma once

#include <vector>

using std::vector;

class Point {
private:
	int _x;
	int _y;
public:
	Point();
	Point(int const &x, int const &y);
	Point(Point const &other);
	
	int getX();
	int getY();
	
	void setX(int const &x);
	void setY(int const &y);
	
	void print();
};


class PointVct {
private:
	vector<Point> _vt;
	
public:
	PointVct();
	PointVct(PointVct const &other);
	PointVct(vector<int> const &vt1, vector<int> const &vt2);
	~PointVct();
	
	Point getData(int const &index);
	int getSize();
	
	void setData(int const &index, int const &data);
	void addData(int const &index, int const &data);
	
	void print();
};