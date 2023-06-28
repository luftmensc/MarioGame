#include "Common.h"
#include "Object.h"
#ifndef MARIO_H
#define MARIO_H
class Mario:public Object{
private:
	//necessary private variables 
	bool jumped = false;
	bool space = false;
	bool groundRepeat = true;
	int text = 0;
	bool groundTouched = true;
	bool isJumping = false;
	bool jumpText = false;
public:
	Mario(RenderWindow* window);
	Mario();
	// private variable getter and setters
	bool getIsJumping(void);			void setIsJumping(bool);
	bool getSpace(void);				void setSpace(bool);
	bool getGroundRepeat(void);			void setGroundRepeat(bool);
	int getText(void);					void setText(int);
	bool getGroundTouched(void);		void setGroundTouched(bool);
	bool getJumpText();					void setJumpText(bool);

	//necessary functions
	void setPosition(Vector2f);
	void draw(RenderWindow*);
	virtual void move(int);
	void groundCondition(void);
	void gravity(void);
	void screenCheck(void);
	virtual void fall();
	void reset();
	void run(void);
};
#endif

