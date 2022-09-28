#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "GetGlut.h"
#include "Sleep.h"
#include "ObjLibrary/Vector2.h"

using namespace std;
using namespace ObjLibrary;


class Square
{
public:
	// declare your constructor here
	Square();
	// declare your public member functions here
	void init();
	void update();
    bool isAlive();
	void draw();
	
private:
	// declare your private member functions here
	float random0to1();
	// declare your member variables here
	Vector2 pos; //The default constructor will initialize the position to be at the origin.
	Vector2 vel;
	double age;

	float red;
	float green;
	float blue;

	double size;
};

#endif