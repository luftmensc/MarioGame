#include "Object.h"

FloatRect Object::getBounds()  {
	return sprite.getGlobalBounds();
}

float Object::getVy(void) { //gets the Y component of the velocity

	return vy;

}

void Object::setVy(float incVy) { //sets the Y component of the velocity

	vy = incVy;

}

float Object::getVx(void) { //gets the X component of the velocity

	return vx;

}

void Object::setVx(float incVy) { //gets the X component of the velocity

	vx = incVy;

}

int Object::getState(void) { //gets the state of the object

	return state;

}
void Object::setState(int state) { //sets the state of the object

	this->state = state;

}
float Object::getDTime(void) { //gets the delta time

	return deltaTime;

}
void Object::setPos(Vector2f pos) { //updates the position of the object

	this->pos = pos;

}
Vector2f Object::getPos(void) { //gets the position of the object

	return pos;
	
}
void Object::draw(RenderWindow* window)
{
	window->draw(sprite);
}

void Object::move() {

}

Object::Object(RenderWindow* window) {
	this->window = window;
	
}

Sprite Object::getSprite() { //gets the sprite of the turtle
	return this->sprite;
}


Texture Object::getTexture() { //gets the texture of the object
	Texture texture = *(this->textures);
	return texture;
}

void Object::setpos(void) { //sets the Y component of the velocity
	pos = sprite.getPosition();
}


int Object::getHeading() { //gets the heading of the object
	return this->heading;
}

int Object::signum(float velocity) { //returns the sign of the argument
	if (velocity >= 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void Object::setHeading(int heading) { //sets the heading of the object
	this->heading = heading;


}

void Object::fall() {

}


void Object::setisLiving(bool isliving) { //sets the isliving marker which checks whether object is alive 
	this->isLiving = isliving;
}

bool Object::getisLiving() { //gets the isliving marker
	return this->isLiving;
}

bool Object::isFalled() { //checks whether object fell from screen
	if (getSprite().getPosition().y > 1080.f) {
		return true;
	}
	else {
		return false;
	}
}

bool Object::getisFalled() { //gets isfalled marker
	return this-> isfalled;
}


void Object::setisFalled(bool isfalled) { //sets isfalled marker
	this->isfalled = isfalled;
}

void Object::updateTurtleSpeed(float increase) {

}