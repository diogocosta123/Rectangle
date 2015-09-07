//Guards should be like this for compatibility and cross-platform.
//Rectangle.h
//#ifndef Rectangl_H
//#define Rectangl_H

//my Class

//#endif


#pragma once
#include <string>
using std::string;

class Rectangle
{
public:


	double getArea();
	double getPerimeter();
	void setHeight(double height);
	void setWidth(double width);

protected:
	double rec_height;
	double rec_width;

	//protected can be assessed by child classes.
};

double Rectangle::getArea()
{
	return rec_height*rec_width;

}

double Rectangle::getPerimeter()
{
	return 2 * (rec_height + rec_width);
}

void Rectangle::setWidth(double width)
{
	rec_width = width;

}

void Rectangle::setHeight(double height)
{
	rec_height = height;
}

double area(double width, double height)
{
	return width*height;

}

// Inheritance

class namedRectangle : Rectangle
{
public:
	string getName();
	void setName(string name);

private:
	string rec_name;

};

string namedRectangle::getName() {
	return rec_name;
}

void namedRectangle::setName(string name) {
	rec_name = name;
}
