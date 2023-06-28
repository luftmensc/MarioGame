#include "Common.h"
#ifndef OBJECT_H
#define OBJECT_H

	class Object {
		float vx = 5.f; //Object's speeds
		float vy = 0;
		float deltaTime = 1.0f;
		int state = 0; //State for animation
		int heading;
		Vector2f pos; 
		Object* next = nullptr;
		friend class Game;
		RenderWindow* window;
		bool isLiving = true; //Necessary variables to implement satate changes
		bool isfalled = false;
	protected:
		Texture textures[8];
		Sprite sprite;
	public:
		FloatRect getBounds(void); //To get boundary 
		Object() {};
		Object(RenderWindow*);
		//Typical setters and getters
		float getVy(void);			void setVy(float);
		float getVx(void);			void setVx(float);
		float getDTime(void);
		int getState(void);			void setState(int);
		void setPos(Vector2f);		Vector2f getPos(void);
		void draw(RenderWindow*);
		virtual void move();
		Sprite getSprite();			Texture getTexture();
		virtual void setpos(void);
		virtual void updateTurtleSpeed(float coef);
		int getHeading();			void setHeading(int);
		int signum(float);
		virtual void fall(void);
		void setSprite();
		void setisLiving(bool);		bool getisLiving();
		bool isFalled();
		void setisFalled(bool);		bool getisFalled();
		virtual void move(int) {

		}
		~Object() {
			
		}
		
	};

#endif