#include <string>
#include <cstdlib>

#include "GetGlut.h"
#include "Sleep.h"
#include "Square.h"
#include "ObjLibrary/Vector2.h"

using namespace std;
using namespace ObjLibrary;

//Vector2 pos(0.0, 0.0); //The default constructor will initialize the position to be at the origin.
//Vector2 vel(5.0, 1.0);
//double age = 0.0;

void Square::init()
{
	pos.set(0.0, 0.0);
	//vel.set(5.0, 1.0);
	age = 0;
	vel = Vector2::getRandomUnitVector() * 5.0; //The particles should now move in random directions
	size = 20;
}

Square::Square()
{
	init();
	//fancier partical
	age = 999999;
	red = random0to1();
	green = random0to1();
	blue = random0to1();
}

void Square::update()
{
	pos += vel; //to move the square according to its current velocity

	//If the age of the square is more than 60, move it to the origin and set its age to zero
	age++;
	//if (age > 60)
	//{
		// restart square movement
		//age = 0.0;
		//pos.set(0.0, 0.0);
	//}
}

bool Square::isAlive()
{
	if (age <= 60)
		return true;
	else
		return false;
}

void Square::draw()
{
	if (isAlive())
	{
		//draw square
		glPushMatrix();    // saves existing top matrix

		glTranslated(pos.x, pos.y, 0.0f);
		// draw a white square
		//Make the squares partially transparent.
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(red, green, blue, 0.4f);
		glBegin(GL_POLYGON);
		glVertex2f(-50.0, -50.0);
		glVertex2f(-50.0, 50.0);
		glVertex2f(50.0, 50.0);
		glVertex2f(50.0, -50.0);
		glDisable(GL_BLEND); //to disable transparency
		glEnd();
		glPopMatrix(); // restores matrix from glPushMatrix
	}
}


float Square::random0to1()
{
	return (float)(rand()) / ((float)RAND_MAX + 1.0f);
}