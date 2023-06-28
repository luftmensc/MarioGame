#include "Common.h"
#include "Object.h"
#ifndef TURTLE_H
#define TURTLE_H
class turtle: public Object {
	int side;
	bool isNewborn;
	bool groundTouched;
public:
	
	
	
	Vector2u spriteSize = textures[0].getSize();
	turtle(RenderWindow*);
	virtual void move();
	void jump(bool down);
	bool touched_boundary();
	bool compare(float, float, float);
	void teleport();
	void setside(int);
	virtual void updateTurtleSpeed(float coef);
	virtual void fall(void);
	void check_jump(void);
	
	
};
#endif