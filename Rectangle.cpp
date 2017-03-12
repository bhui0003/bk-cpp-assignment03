/*****************************************************************************
Filename:				Rectangle.cpp
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
Purpose:				Represents a rectangle to add to a graphic element
*****************************************************************************/

#include "Rectangle.h"
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name:				Rectangle::CalculateCenter
Purpose:					Calculates center of the rectangle
Function In Parameters:		void
Function Out Parameters:	Pair - coordinate of the center of the rectangle
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
Pair Rectangle::CalculateCentre(){
	return (this->p1 / 2) + (this->p2 / 2);
}

/*****************************************************************************
Function Name:				Rectangle::Report
Purpose:					Reports the rectangle coordinates
Function In Parameters:		void
Function Out Parameters:	void
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
void Rectangle::Report(){
	cout << "Shape RECTANGLE " << this->name << endl;
	cout << "top left coordinates: ";
	this->p1.Report();
	cout << endl;
	cout << "bottom right coordinates: ";
	this->p2.Report();
	cout << endl;
}