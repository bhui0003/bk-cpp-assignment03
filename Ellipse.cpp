/*****************************************************************************
Filename:				Ellipse.cpp
Version:				v1.0
Author/Student Name:	Brandon Keohane
Student Number:			040719123
Course Name & Number:	C++ Programming CST8219
Lab Section:			302
Assignment Number:		Assignment 3
Assignment Name:		Vector Graphic with Polymorphism Inheritance & Templates
Due Date:				December 03, 2016
Submission Date:		December 01, 2016
Professor Name:			A. Tyler
Purpose:				Represents a ellipse shape
*****************************************************************************/

#include "Ellipse.h"
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name:				Ellipse::CalculateCenter
Purpose:					Calculates center of this ellipse
Function In Parameters:		void
Function Out Parameters:	Pair - coordinate to the center
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
Pair Ellipse::CalculateCentre(){
	return this->p1;
}

/*****************************************************************************
Function Name:				Ellipse::Report
Purpose:					Reports this ellipses coordinates
Function In Parameters:		void
Function Out Parameters:	void
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
void Ellipse::Report(){
	cout << "Shape ELLIPSE " << this->name << endl;
	cout << "center coordinates: ";
	this->p1.Report();
	cout << endl;
	cout << "axes dimensions: ";
	this->p2.Report();
	cout << endl;
}