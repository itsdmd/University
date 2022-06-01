#pragma once

class Point2D {
private:
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
	
	double distance(Point2D const &p) const;
	
	void print() const;
};

class Point3D: private Point2D {
private:
	Point2D _p2;
	double _z;

public:
	Point3D();
	Point3D(double const &x, double const &y, double const &z);
	Point3D(int const &min, int const &max);		// RNG
	~Point3D();
	
	Point2D get2D() const;
	double getZ() const;
	void setZ(double const &z);
	void setXYZ(double const &x, double const &y, double const &z);
	
	double distance(Point3D const &p) const;
	
	void print() const;
};