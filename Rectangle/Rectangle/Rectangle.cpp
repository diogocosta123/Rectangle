// Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Rectangle.h"
#include <string> //string.h c header.  string c++ header!

using std::string; //standard implementation. should use std::string, so people no it's the standard library.


void swap(int& a, int&b)
{
	int aux = {};
	aux = a;
	a = b;
	b = aux;

}


int main()
{

	// Class
	Rectangle rect1{};
	double x_width{ 10 }, y_height{ 25 }; // assign - unitalicized variable // copy - previously initialized variable
	double rectangle_area{}, rectangle_perimeter{};
	rect1.setHeight(4.0),
		rect1.setWidth(10.0);
	rectangle_area = rect1.getArea();
	rectangle_perimeter = rect1.getPerimeter();
	std::cout << "Area: " << +rectangle_area << "\nPerimeter: " << +rectangle_perimeter << "\n" << std::endl;

	// Inheritance
	namedRectangle rect2{};
	string name = "";
	rect2.setName("Cool rectangle");
	name = rect2.getName();
	std::cout <<"Rectangle name: "<< name <<"\n"<< std::endl;
	
	// Reference - just declare the variables with & sign on the function header. 
	
	int a{0}, b{1};
	swap(a, b);
	if (a == 1 && b == 0)
		std::cout << "swap succeeded: " << +a << " " << +b << std::endl;
	else
		std::cout << "swap failed";
	return 0;
}


// things to see: more on inheritance, polymorphism, exceptions, RAII and smart pointers. data structures(vectors), templates, lambdas.

