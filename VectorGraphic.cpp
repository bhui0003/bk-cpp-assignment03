/*****************************************************************************
Filename:				VectorGraphic.cpp
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
Purpose:				Represents a vector graphic that consists of 
						vector graphics
*****************************************************************************/

#include "VectorGraphic.h"
#include "Line.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include <string>
#include <iostream>
using namespace std;

/*****************************************************************************
Function Name:				VectorGraphic::AddGraphicElement
Purpose:					Allows user to add graphic elements to the vg
Function In Parameters:		void
Function Out Parameters:	void
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
void VectorGraphic::AddGraphicElement(){
	/* Name of new graphic */
	char nameGE[256], nameShape[256];
	/* Variables for num shapes and coordinates */
	int nShapes;
	/* Hold coordinates */
	float sX, sY, eX, eY;
	/* Type of shape */
	char shapeType;
	/* Shape pointer to pointers */
	Shape** shapes;

	/* Print header to adding graphic elements */
	cout << "Adding a Graphic Element" << endl;
	/* Name of graphic element */
	cout << "Please enter the name of the new Graphic Element (<256 characters): ";
	cin.ignore();
	cin.getline(nameGE, 256);

	/* Number of shapes it contains */
	cout << "Please enter the number of Shapes it contains: ";
	cin >> nShapes;
	/* Temporary shape pointer array */
	shapes = new Shape*[nShapes];

	/* Loop and add shapes */
	for (int i = 0; i < nShapes; ++i){
		/* Get type of shape */
		cout << "Please enter the type (L for line, R for rectangle, E for eclipse) for Shape #" << i << endl;
		cin >> shapeType;
		switch (shapeType){
			/* Line picked */
			case 'L':
				cout << "Please enter the name of the new line(<256 characters): ";
				cin.ignore();
				cin.getline(nameShape, 256);
				cout << "Please enter the coordinates of the start point: (x,y) ";
				cin >> sX >> sY;
				cout << "Please enter the coordinates of the end point: (x,y) ";
				cin >> eX >> eY;

				/* Add shape to temporary shape array */
				shapes[i] = new Line(nameShape, Pair(sX, sY), Pair(eX, eY));
				break;
			/* Rectangle picked */
			case 'R':
				cout << "Please enter the name of the new Rectangle(<256 characters): ";
				cin.ignore();
				cin.getline(nameShape, 256);
				cout << "Please enter the coordinates of the top-left: (x,y) ";
				cin >> sX >> sY;
				cout << "Please enter the coordinates of the bottom-right: (x,y) ";
				cin >> eX >> eY;

				/* Add shape to temporary shape array */
				shapes[i] = new Rectangle(nameShape, Pair(sX, sY), Pair(eX, eY));
				break;
			/* Ellipse picked */
			case 'E':
				cout << "Please enter the name of the new Ellipse(<256 characters): ";
				cin.ignore();
				cin.getline(nameShape, 256);
				cout << "Please enter the coordinates of the center: (x,y) ";
				cin >> sX >> sY;
				cout << "Please enter the width and height: (width,height) ";
				cin >> eX >> eY;

				/* Add shape to temporary shape array */
				shapes[i] = new Ellipse(nameShape, Pair(sX, sY), Pair(eX, eY));
				break;
			/* Error: wrong shape type picked */
			default:
				cout << "Error wrong selection: Pick again." << endl;
				i--; /* Stay on the same shape */
				break;
		} // END SWITCH 
	} // END FOR
	/* Add new graphic element */
	push_back(GraphicElement(shapes, nameGE, nShapes));
	/* Clean up double pointer to shapes */
	delete[] shapes;
}

/*****************************************************************************
Function Name:				VectorGraphic::DeleteGraphicElement
Purpose:					Allows user to delete graphic elements from the vg
Function In Parameters:		void
Function Out Parameters:	void
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
void VectorGraphic::DeleteGraphicElement(){
	/* Index user chose to delete */
	int index, i = 0;
	/* No elements to delete */
	if (size() == 0){
		cout << "No elements to delete." << endl;
		return;
	}

	/* Header for deleting elements */
	cout << "Deleting a Graphic Element" << endl;
	/* Error check loop */
	do {
		cout << "Please enter the index to delete in the range 0 to " << size() - 1 << endl;
		cin >> index;
		/* Incorrect index */
		if (index < 0 && index < size() - 1){
			cout << "Error incorrect index, try again." << endl;
		}
	} while (index < 0 && index < size()-1);

	/* Delete element from index */
	for (VectorGraphic::iterator iter = begin(); iter < end(); iter++, i++){
		/* If index to delete */
		if (i == index){
			/* Delete shapes array */
			for (int y = 0; y < iter->size(); ++y)
				delete iter->at(y);
			/* Remove item from this list */
			erase(iter);
			cout << "erase index = " << index << endl;
			return;
		}
	}
	
}

VectorGraphic::VectorGraphic(){ }

VectorGraphic::~VectorGraphic(){
	/* Loop though all graphic elements */
	for (VectorGraphic::iterator iter = begin(); iter < end(); iter++)
		for (int y = 0; y < iter->size(); ++y) /* Delete each shape individually */
			delete iter->at(y);
}

/*****************************************************************************
Function Name:				ostream::operator<<
Purpose:					Appends vector graphic to the output stream
Function In Parameters:		os - output stream to append to
							vg - vector graphic to append to output stream
Function Out Parameters:	ostream reference with vector graphic appended
Version:					v1.0
Author/Student Name:		Brandon Keohane
*****************************************************************************/
ostream& operator<<(ostream& os, VectorGraphic& vg){
	/* Index indicator */
	int i = 0;
	/* Append header for printing */
	cout << "VectorGraphic Report" << endl << endl;
	/* Loop and append the graphic elements to the output stream */
	for (VectorGraphic::iterator GE = vg.begin(); GE < vg.end(); ++GE, i++){
		cout << "Reporting Graphic Element " << i << endl;
		cout << *GE << endl;
	}
	/* Return the output stream */
	return os;
}