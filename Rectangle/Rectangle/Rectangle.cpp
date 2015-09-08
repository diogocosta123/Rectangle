// Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Object.h"
#include <string> //string.h c header.  string c++ header!

using std::string; //standard implementation. should use std::string, so people no it's the standard library.


void swap(int& a, int&b)
{
	int aux = {};
	aux = a;
	a = b;
	b = aux;

}


// Template: Can be function template or class template.

template <typename T>  // Should use typename, class is for backwards compatibility.
	T Add(T t1, T t2)
	{
		return t1 + t2;
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
	
	// Polymorphism: C++ polymorphism means that a call  to a member function 
	//               will cause a different function to be executed depending on the type of object that invokes the function. 
	//               You have different classes with a function of the same name, and even the same parameters, but with different implementations.
	//				
	//				 Create virtual function in base class:

						// virtual int area()
						// {
						//	return 0;                              -> USE THIS. DERIVED CLASSES CAN OVERIDE IMPLEMENTATION
						// }
	//				Or pure virtual function - MUST redefine it in the child classes (or derived classes will become abstract). 

						// virtual double getPerimeter() = 0;      -> MAKES CLASSES ABSTRACT


	double perimeter{};
	rect2.setHeight(10.0);
	rect2.setWidth(15.0);
	perimeter = rect2.getPerimeter();
	std::cout << "Perimeter: " << perimeter << "\n" << std::endl;
	

	//template
	std::cout << "Template test: "<< Add(1, 2) << std::endl;

	return 0;
}


// things to see: exceptions, RAII and smart pointers. data structures(vectors), templates, lambdas.

