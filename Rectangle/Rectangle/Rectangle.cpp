// Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Rectangle.h"
#include <string>

using std::string; //standard implementation


void swap(int& a, int&b)
{
	int aux = {};
	aux = a;
	a = b;
	b = aux;

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
	string name{};
	rect2.setName("FRED");
	name = rect2.getName();
	std::cout << name << std::endl;



	// Reference - just declare the variables with & sign on the function header. 
	
	int a{0}, b{1};
	swap(a, b);
	if (a == 1 && b == 0)
		std::cout << "swap succeeded: " << +a << " " << +b << std::endl;
	else
		std::cout << "swap failed";
	return 0;
}


