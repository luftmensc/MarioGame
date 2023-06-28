#include "turtle.h"
int op = 0;
turtle::turtle(RenderWindow* window): Object(window){  
	 
	this->isNewborn = true; //checks if turtle is newborn
	this->groundTouched = true; //marker for if turtle touches ground
	//sets the initial velocity of the turtle
	setVx(4.f);
	setVy( 0.f);
	setState(0); //initial state of the turtle
	 
	//loading textures from files
	textures[0].loadFromFile("../assets/turtle1.png");
	textures[1].loadFromFile("../assets/turtle2.png");
	textures[2].loadFromFile("../assets/turtle3.png");
	textures[3].loadFromFile("../assets/turtle5.png");
	spriteSize = textures[0].getSize();
	//changes the origin of the turtle
	sprite.setOrigin(spriteSize.x / 2, spriteSize.y/2);
	sprite.setTexture(textures[getState()]);
	 
}
void turtle::move() {
	if (getisLiving()) {
		switch (getState())
		{
		case 0: //state 0

			if (isNewborn) {

				if (side == 0) {
					sprite.setPosition(220, 200 - spriteSize.y / 2); //sets the position of the newborn turtle if it is born on the left side of the screen 

					isNewborn = false;

				}
				else {

					sprite.setPosition(1920 - 220, 200 - spriteSize.y / 2); //sets the position of the newborn turtle if it is born on the right side of the screen
					sprite.scale(-1.f, 1.f);
					setVx(-getVx());
					isNewborn = false;
				}

			}
			else {
				sprite.move( getVx() * getDTime(), getVy());
				
				check_jump(); //checks if turtle should jump 
				jump(!groundTouched); //if it should, turtle jumps
				teleport(); //if necessary, turtle is teleported to the topmost of the screen

			}

			setState(1); //updates the state
			//checks whether turtle touches the boundary of the screen
			if (touched_boundary()) {
				sprite.scale(-1.f, 1.f);
				setVx(-getVx());
				sprite.move( getVx() * getDTime(), getVy());

			}


			break;

		case 1:
			sprite.move( getVx() * getDTime(), getVy());
			check_jump();
			jump(!groundTouched);
			teleport();

			setState(2);

			if (touched_boundary()) {

				sprite.scale(-1.f, 1.f);
				setVx(-getVx());
				sprite.move( getVx() * getDTime(), getVy());
			}
			break;
		case 2:
			sprite.move( getVx() * getDTime(), getVy());

			check_jump();
			jump(!groundTouched);
			teleport();

			setState(0);

			if (touched_boundary()) {
				sprite.scale(-1.f, 1.f);
				setVx(-getVx());
				sprite.move( getVx() * getDTime(), getVy());
			}
			break;
		}
		//updtaes the attributes of the turtle object accordingly
		setpos();
		sprite.setTexture(textures[getState()]);
		setHeading(signum(getVx()));
	}
	//if turtle dies, falling texture is set for dying animation
	else {
		sprite.move(getVx(), getVy());
		sprite.setTexture(textures[3]);
	}
}
//it checks whether turtle touches the boundary of the screen
bool turtle::touched_boundary() {
	Vector2f pos= sprite.getPosition();
	if (pos.x > W_WIDTH - spriteSize.x || pos.x<spriteSize.x || pos.y > W_HEIGHT - spriteSize.y || pos.y < spriteSize.y) {

		return true;
	}
	else {
		return false;
	}
	
	
	
	
	
}


/*bool turtle::check_jump(float* boundaries) {
	Vector2f pos = sprite.getPosition();
	if (compare(*(boundaries + 1), pos.x, *boundaries) && compare(490-spriteSize.y/2,pos.y,250-spriteSize.y/2-1 )) {

		return true;

	}

	else if (compare(*(boundaries + 3), pos.x, *(boundaries+2)) && compare(770 - spriteSize.y / 2, pos.y, 490 - spriteSize.y / 2 - 1)) {

		return true;

	}

	else if (compare(*(boundaries + 5), pos.x, *(boundaries+4)) && compare(770 - spriteSize.y / 2, pos.y, 490 - spriteSize.y / 2 - 1)) {

		return true;

	}

	else if (compare(*(boundaries + 7), pos.x, *(boundaries+6)) && compare(1000 - spriteSize.y / 2, pos.y, 770 - spriteSize.y / 2 - 1)) {

		return true;

	}
	else {
		setVy(0);
		return false;
	}
	
	
	



}
*/
//it sets the velocity of the turtle if it should jump
void turtle::jump(bool down) {
	if (down) {
		setVy(getVy() + 0.2);
		
		
		
	}
	else {
		setVy(0.f);
	}

}
//function compares three values respectively
bool turtle::compare(float a, float b, float c) {
	if ((a > b) && (b > c) ) {
		return true;
	}
	else {
		return false;
	}
}


//function teleports the turtle if it enters into a pipe 
void turtle::teleport() {
	Vector2f pos = sprite.getPosition();
	if ((pos.x - spriteSize.x / 2) < 130 && (pos.y+spriteSize.y/2)>=1000) {
		if (side == 0) {
			sprite.setPosition(194 + spriteSize.x / 2, 130 + spriteSize.y / 2);
			sprite.scale(-1.f, 1.f);
			setVx(-getVx());
			setState(0);
			isNewborn = true;
		}
		else {
			sprite.setPosition(1920 - 194 - spriteSize.x / 2, 130 + spriteSize.y / 2);
			sprite.scale(-1.f, 1.f);
			setVx(-getVx());
			setState(0);
			isNewborn = true;
		}
	}
	else if ((pos.x + spriteSize.x / 2) > (1920-130) && (pos.y + spriteSize.y / 2) >= 1000) {
		if (side == 0) {
			sprite.setPosition(194 + spriteSize.x / 2, 130 + spriteSize.y / 2);
			setState(0);
			isNewborn = true;
		}
		else {
			sprite.setPosition(1920 - 194 - spriteSize.x / 2, 130 + spriteSize.y / 2);
			setState(0);
			isNewborn = true;
		}
	}
}
//sets the side where turtle will be born on
void turtle::setside(int side){
	this->side = side;
}
//increases the turtle speed 
void turtle::updateTurtleSpeed(float increase) {
	float initial = 5;
	
	if (getVx() < 0) {
		increase = -increase;
		initial = -initial;
	}
	setVx(initial+increase);



}
//function is called if turtle is beaten and set speeds for falling animation
void turtle::fall() {

	setVx(0.f);
	setVy(3.f);
}


//function checks whether turtle is on a brick or not

void turtle::check_jump() {

	if ((sprite.getPosition().y < 780 && sprite.getPosition().y > 760) && !(sprite.getPosition().x > 690 && sprite.getPosition().x < 1230)) {
		groundTouched = true;
		setVy(0);
	}



	else if (sprite.getPosition().y >= 992)
	{
		groundTouched = true; setVy(0);

	}


	else {
		
		groundTouched = false;
	}



	if ((sprite.getPosition().y < 580 && sprite.getPosition().y > 560) && !(sprite.getPosition().x > 240 && sprite.getPosition().x < 1680)) {
		groundTouched = true;
		setVy(0);
	}

	if ((sprite.getPosition().y < 500 && sprite.getPosition().y > 480) && (sprite.getPosition().x > 480 && sprite.getPosition().x < 480 + 960)) {
		groundTouched = true;
		setVy(0);
	}

	if ((sprite.getPosition().y < 260 && sprite.getPosition().y > 240) && !(sprite.getPosition().x > 840 && sprite.getPosition().x < 1080)) {
		groundTouched = true;
		setVy(0);
	}
		

	}
