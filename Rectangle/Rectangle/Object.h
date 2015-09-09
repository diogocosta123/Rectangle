//Guards should be like this for compatibility and cross-platform.
//Rectangle.h
//#ifndef Rectangl_H
//#define Rectangl_H

//my Class

//#endif


#pragma once
#include <string>
using std::string;


class Object
{
public:

	// pure virtual function
	//virtual double getPerimeter() = 0;
	//virtual function
	virtual double getPerimeter() {
		return 0;
	}
};




class Rectangle : Object
{
public:
	
	double getArea();
	double getPerimeter();
	void setHeight(double height);
	void setWidth(double width);

protected:

	double rec_height;
	double rec_width;

	//protected can be assessed by child classes, but NOT outside classes!
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



// Inheritance

class namedRectangle : public Rectangle // if the access-specifier is not specified it will be private by default. 
										// Should be PUBLIC if it is to be accessed by outside (most of the cases), 
										// otherwise it will only be accessible by child classes.
										// See: http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
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
