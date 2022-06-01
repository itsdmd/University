#pragma once

class Point2D {
protected:
	double _x;
	double _y;
	
public:
	Point2D();
	Point2D(double const &x, double const &y);
	Point2D(int const &min, int const &max);		// RNG
	~Point2D();
	
	double getX() const;
	double getY() const;
	
	void setX(double const &x);
	void setY(double const &y);
	void setXY(double const &x, double const &y);
	
	void print() const;
};

class Point3D: public Point2D {
protected:
	double _z;

public:
	Point3D();
	Point3D(double const &x, double const &y, double const &z);
	Point3D(int const &min, int const &max);		// RNG
	~Point3D();
	
	double getZ() const;
	void setZ(double const &z);
	void setXYZ(double const &x, double const &y, double const &z);
	
	void print() const;
};