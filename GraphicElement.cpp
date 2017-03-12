/*****************************************************************************
Filename:				GraphicElement.cpp
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
Purpose:				Graphic element that has a shape
*****************************************************************************/

#include "GraphicElement.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "Shape.h"
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name:				GraphicElement constructor
Purpose:					Constructs graphic elements from parameters
Function In Parameters:		shape - shape to make graphic element from
							name - name of graphic element
							quantity - how many shapes there are
Function Out Parameters:	
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
GraphicElement::GraphicElement(Shape** shape, char* name, unsigned int quantity){
	/* Copy name */
	strcpy(this->name, name);
	/* Copy all shapes into vector */
	for (unsigned int i = 0; i < quantity; ++i)
		push_back(shape[i]);
}

/*****************************************************************************
Function Name:				GraphicElement constructor
Purpose:					Constructs graphic elements from parameters
Function In Parameters:		ge - graphic element to copy
Function Out Parameters:	
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
GraphicElement::GraphicElement(const GraphicElement& ge){
	/* Copy name from graphic element */
	strcpy(name, ge.name);
	/* Copy all shapes over into this graphic element */
	for (GraphicElement::const_iterator i = ge.begin(); i < ge.end(); i++){
		push_back(*i);
	}
}

GraphicElement::~GraphicElement(){ 
	for (int i = 0; i < size(); i++) at(i) = nullptr;
}

/*****************************************************************************
Function Name:				GraphicElement::operator=
Purpose:					Copies the graphic element fields into this ge
Function In Parameters:		ge - graphic element to copy
Function Out Parameters:	Graphic element reference
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
GraphicElement& GraphicElement::operator=(GraphicElement& ge){
	/* Copy name from graphic element */
	strcpy(name, ge.name);
	/* Clear existing objects */
	clear();
	/* Copy all shapes over into this graphic element */
	for (GraphicElement::iterator i = ge.begin(); i < ge.end(); i++){
		push_back(*i);
	}
	return *this;
}

/*****************************************************************************
Function Name:				ostream::operator<<
Purpose:					Constructs a output stream
Function In Parameters:		os - output stream to append to 
							ge - graphic element to display
Function Out Parameters:	ostream reference constructed
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
ostream& operator<<(ostream& os, GraphicElement& ge){
	/* Center pair of coordinate */
	Pair center;
	/* Total shapes */
	/* Header to the graphic element output */
	cout << "Graphic Element " << ge.name << endl;

	/* Calculator center of the graphic elements */
	for (GraphicElement::iterator i = ge.begin(); i < ge.end(); i++){
		center = center + (*i)->CalculateCentre();
	}
	/* Average of all centers */
	center = center / ge.size();
	/* Append center pair output */
	cout << "The center = ";
	center.Report();
	cout << endl;

	/* Append output of each shape */
	cout << "List of Shapes in " << ge.name << endl;
	for (GraphicElement::iterator i = ge.begin(); i < ge.end(); i++)
		(*i)->Report();

	/* Return output stream */
	return os;
}