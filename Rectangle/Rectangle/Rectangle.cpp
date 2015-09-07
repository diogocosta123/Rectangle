// Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Rectangle.h"



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

//protected can be assessed by child classes.


double area(double width, double height)
{
	return width*height;

}

int main()
{


	Rectangle rect1{};
	double x_width{ 10 }, y_height{ 25 }; // assign - unitalicized variable // copy - previously initialized variable
	double rectangle_area{}, rectangle_perimeter{};
	rect1.setHeight(4.0),
		rect1.setWidth(10.0);
	rectangle_area = rect1.getArea();
	rectangle_perimeter = rect1.getPerimeter();

	std::cout << "Area: " << +rectangle_area << "\nPerimeter: " << +rectangle_perimeter << "\n" << std::endl;
	
	//Hello!
	return 0;
}


