//Guards should be like this for compatibility and cross-platform.
//Rectangle.h
//#ifndef Rectangl_H
//#define Rectangl_H

//my Class

//#endif


//#pragma once

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:


	double getArea();
	double getPerimeter();
	void setHeight(double height);
	void setWidth(double width);

private:
	double rec_height;
	double rec_width;

};

#endif
