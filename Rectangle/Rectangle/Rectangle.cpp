// Rectangle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory> // for smart pointers
#include <fstream> // read and write
#include "Object.h"
#include <string> //string.h c header.  string c++ header!
#include <vector>

#include <numeric>
#include <algorithm>

using std::string; //standard implementation. should use std::string, so people no it's the standard library.
using std::vector;

void swap(int& a, int& b)
{
	int aux = {};
	aux = a;
	a = b;
	b = aux;

}


// Template: Can be function template or class template. 
// More info and class templates: http://www.tutorialspoint.com/cplusplus/cpp_templates.htm
//			e.g: Vector is a template.
// Function template:

template <typename T>  // Should use typename, class is for backwards compatibility.
	T Add(T t1, T t2)
	{
		return t1 + t2;
	} 

	//Smart pointers - include <memory header>

	Rectangle smartTest(double width, double height)
	{
		std::unique_ptr<Rectangle> rect3(new Rectangle()); // Declare
		
		//(*rect3).setWidth(width);           // Use
		//(*rect3).setHeight(height);
											// Equivalent. Gets the member set...
											// rect3 points too.				
		rect3->setWidth(width);
		rect3->setHeight(height);
		
		return *rect3;
		//unique_ptr: only one object needs to access the pointer.
		//shared_ptr: several want to use the pointer (cleaned after last copy gets out of scope)
		//weak_ptr:

	}   //rect3 is deleted automatically here. 
		// NEVER use new or delete. Once there are no remaining references everything will be deleted for us.
	

	int main()
	{

		// Class
		Rectangle rect1{};
		double x_width{ 10.0 }, y_height{ 25.0 }; // assign - unitalicized variable // copy - previously initialized variable
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
		std::cout << "Rectangle name: " << name << "\n" << std::endl;

		// Reference - just declare the variables with & sign on the function header. 

		int a{ 0 }, b{ 1 };
		swap(a, b);
		if (a == 1 && b == 0)						// Passed variables also change
			std::cout << "Swap succeeded: " << +a << " " << +b << std::endl;
		else
			std::cout << "Swap failed.";

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


		//Template - Read above.
		std::cout << "Template test: " << Add(1, 2) << "\n" << std::endl;


		// Smart pointers (Part of RAII - More bellow).

		Rectangle rectPointer{};
		double pointerArea{};
		rectPointer = smartTest(x_width, y_height);
		pointerArea = rectPointer.getArea();
		std::cout << "Pointer test: " << pointerArea << "\n" << std::endl;


		// Casting:

		//(int)x_width; // Classic C cast - More powerful, but more unsafe - Should probably use this. 

		// Type conversion
		//static_cast<int>(x_width); // dynamic_cast - Check type conversion later.


		//Containers: Vectors. 
		// More info: http://www.cplusplus.com/reference/stl/

		vector<Rectangle> rectVector;                 // Initialization
		vector<double> doubleVector{ 1.1, 4.5, 3.6 }; // Assign
		vector <int> seriesVector(100);               // Size 100

		rectVector.push_back(rect1);  // Add elements to the end of the vector.
		rectVector.push_back(rect2);  // Vectors adjust their size automatically.

		rectVector[0];				// e.g: Access element 0 of vector.

		rectVector.size();			// returns vector size.

		//Loop through vectors:

		double total_sum{ 0 };
		double total_sum2{ 0 };

		std::cout << "Vector elements: " << std::endl;

		for (const auto& elem : doubleVector) // similar to matlab:
		{									  // starting in current elem until the end of doubleVector (elem == current element. There's no counter.) 
			total_sum += elem;
			std::cout << elem << std::endl;
		}

		//Using iterators, <numeric> and <algorithm> to quickly manipulate the vectors:

		total_sum2 = std::accumulate(begin(doubleVector), end(doubleVector), 0); // Same operation as above using accumulate from <numeric>.

		std::iota(begin(seriesVector), end(seriesVector), 0); // Fills with vector 0 - 99

		seriesVector.erase(begin(seriesVector) + 2);        // Deletes element at the position 2 (3)

		std::sort(begin(doubleVector), end(doubleVector));  // Sorts vector

		auto it = std::find(begin(seriesVector), end(seriesVector), 43); // Finds element 43 and returns its value to iterator it. 
																	    // Iterators should be initialized as auto.
		*it = 44;													   // Change value pointed by iterator.

		//Lambdas std::find_if

		//Lambdas are a convenient way of defining an anonymous 
		//function object right at the location where it is invoked 
		//or passed as an argument to a function.
		
		auto lambda = [] (auto a, auto b)  // Generic 
		{
			return a + b;
		};
		
		lambda(5, 3); //= 8 


		int numberOfOdds = std::count_if(begin(seriesVector), end(seriesVector), [](int i) {return i % 2 == 1; }); // Lambdas are useful for this - to encapsulate a 
																												  // few lines of code that are passed to algorithms or asynchronous methods.
		auto it2 = std::find_if(begin(seriesVector), end(seriesVector), 
			[](int i) { if ( i / 10 == 2) 
							return i;
						else																						// Returns iterator. Must be auto!
							return 0; });

		int numberFound = *it2;

		std::cout << "\nLambdas test\n" << "Number of odds: " << numberOfOdds <<std::endl << "Numbers found: "<<  numberFound << std::endl << std::endl;

	// Exceptions: When you want to access something (e.g: file, database) 
	//             that's not available (or don't have permission) anymore. 
	//			   More info: http://stackoverflow.com/questions/8480640/how-to-throw-a-c-exception

	try
	{

		//RAII 
		std::fstream file;
		file.open("C:/users/diogo/desktop/");
		if (file.is_open())
			std::cout << "File opened successfully.\n" << std::endl;
		else
			throw std::invalid_argument("Failed to open file.\n\n");

		// file.close(); - Do NOT close files/etc EVER! RAII takes care of it for us!; 
		//                 RAII exception-safe resource management. It prevents exceptions to be thrown and guarantees everything is released.
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what();
		return -1;
	}

	return 0;

}

