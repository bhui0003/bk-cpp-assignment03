/*****************************************************************************
Filename:				Pair.cpp
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
Purpose:				Represents a coordinate on a 2d plain
*****************************************************************************/

#include "Pair.h"
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name:				Pair::operator+
Purpose:					Reports the x and y coordinate
Function In Parameters:		p - pair to add to this pair
Function Out Parameters:	Pair - result of the addition in a new pair object
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
Pair Pair::operator+(Pair& p){
	return Pair(x + p.x, y + p.y);
}

/*****************************************************************************
Function Name:				Pair::operator/
Purpose:					Divides this pair by the denomenator
Function In Parameters:		d - denomenator to divide by 
Function Out Parameters:	Pair - result of the division in a new pair object
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
Pair Pair::operator/(double d){
	return Pair(x / d, y / d);
}

/*****************************************************************************
Function Name:				Pair::Report
Purpose:					Reports the x and y coordinate
Function In Parameters:		void
Function Out Parameters:	void
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
void Pair::Report(){
	cout << "x = " << x << "; y = " << y;
}