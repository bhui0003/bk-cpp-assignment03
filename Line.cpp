/*****************************************************************************
Filename:				Line.cpp
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
Purpose:				Represents a single line on a 2d plain
*****************************************************************************/

#include "Line.h"
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name:				Line::CalculateCenter
Purpose:					Calculates the center of this line
Function In Parameters:		void
Function Out Parameters:	Pair - center coordinate
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
Pair Line::CalculateCentre(){
	return (this->p1+this->p2) / 2;
}

/*****************************************************************************
Function Name:				Line::Report
Purpose:					Reports this lines coordinates
Function In Parameters:		void
Function Out Parameters:	void
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
void Line::Report(){
	cout << "Shape LINE " << this->name << endl;
	cout << "start coordinates: ";
	this->p1.Report();
	cout << endl; 
	cout << "end coordinates: "; 
	this->p2.Report();
	cout << endl;
}