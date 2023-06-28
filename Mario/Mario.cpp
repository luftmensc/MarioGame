#include "Mario.h"

// Mario constructors usage for initializing the texts and sprites
Mario::Mario(RenderWindow* window): Object(window)
{

	textures[0].loadFromFile("../assets/mario1.png");
	textures[1].loadFromFile("../assets/mario2.png");
	textures[2].loadFromFile("../assets/mario3.png");
	textures[3].loadFromFile("../assets/mario4.png");
	textures[4].loadFromFile("../assets/mario4.png");
	textures[5].loadFromFile("../assets/mario5.png");
	textures[6].loadFromFile("../assets/mario6.png");


	Vector2u spriteSize = textures[0].getSize();
	sprite.setOrigin(spriteSize.x / 2, spriteSize.y/2);
	sprite.setTexture(textures[getState()]);

	
	sprite.setScale(-1.f, 1.f);

}
Mario::Mario() {
	textures[0].loadFromFile("../assets/mario1.png");
	textures[1].loadFromFile("../assets/mario2.png");
	textures[2].loadFromFile("../assets/mario3.png");
	textures[3].loadFromFile("../assets/mario4.png");
	textures[4].loadFromFile("../assets/mario4.png");
	textures[5].loadFromFile("../assets/mario5.png");
	textures[6].loadFromFile("../assets/mario6.png");
	textures[7].loadFromFile("../assets/mario7.png");


	Vector2u spriteSize = textures[0].getSize();
	sprite.setOrigin(spriteSize.x / 2, spriteSize.y);
	sprite.setTexture(textures[getState()]);
	sprite.setPosition(200, 1080 - 80);
	
	sprite.setScale(-1.f, 1.f);
	setHeading(1);
}

//functions descriptions
void Mario::setPosition(Vector2f pos) {
	sprite.setPosition(pos);
}

void Mario::draw(RenderWindow* window) {
	window->draw(sprite);
}

void Mario::move(int dir) { //states for animations
	switch (getState())
	{
	case 0:
		text = 0;
		if (dir == 1) {
			setState(1);
			sprite.setScale(-1.f, 1.f);
		}
		else if (dir == 0) {

			setState(4);
		}

		break;
	case 1:
		text = 1;
		sprite.setScale(-1.f, 1.f);
		sprite.move(getVx() * getDTime(), 0.f);
		screenCheck();
		setState(2);
		if (dir == 0) { setState(4); }
		break;

	case 2:
		text = 2;
		sprite.move(getVx() * getDTime(), 0.f);
		screenCheck();
		setState(3);
		if (dir == 0) { setState(4);; }
		break;
	case 3:
		text = 3;
		sprite.move(getVx() * getDTime(), 0.f);
		screenCheck();
		setState(1);
		if (dir == 0) { setState(4); }

		break;
	case 4:
		text = 1;
		sprite.setScale(1.f, 1.f);
		sprite.move(-getVx() * getDTime(), 0.f);
		screenCheck();
		setState(5);
		if (dir == 1) { setState(1); }

		break;
	case 5:
		text = 2;
		sprite.move(-getVx() * getDTime(), 0.f);
		screenCheck();
		setState(6);
		if (dir == 1) { setState(1); }
		break;
	case 6:
		text = 3;
		sprite.move(-getVx() * getDTime(), 0.f);
		screenCheck();
		setState(4);
		if (dir == 1) { setState(1); }
		break;


	}
	setpos(); //setting position
	sprite.setTexture(textures[text]);//setting the correct texture for different states
	setHeading(signum(getVx()));
	if (jumpText) { sprite.setTexture(textures[6]); } //jump text



}

void Mario::gravity(void) {

	if (!groundTouched)  //Gravity effect for mario
	{
		setVy(getVy() - 0.2f); 

	}
}

void Mario::groundCondition(void) { //Checking if mario touched ground or not. If yes, vy sets to zero

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
	if ((sprite.getPosition().y < 500 && sprite.getPosition().y > 480) && (sprite.getPosition().x > 480 && sprite.getPosition().x < 480 +960)) {
		groundTouched = true;
		setVy(0);
	}
	if ((sprite.getPosition().y < 260 && sprite.getPosition().y > 240) && !(sprite.getPosition().x > 840 && sprite.getPosition().x < 1080)) {
		groundTouched = true;
		setVy(0);
	}
	if (groundTouched) {
		groundRepeat = true;
	}

}

void Mario::screenCheck(void) { //screen checking for the borders of the screen.

	if (sprite.getPosition().x < 30) {
		sprite.setPosition(31.f, sprite.getPosition().y);
		
	}

	else if (sprite.getPosition().x > 1920 - 30) {
		sprite.setPosition(1891.f, sprite.getPosition().y);
		
	}

}

void Mario::fall(void) { //falling animation
	sprite.setTexture(textures[7]);
	//setVx(0);
	setVy(-3);
	//sprite.move(0, getVy());
}

void Mario::reset(void) { //reset the mario to the starting position
	getSprite().setPosition(200, 1080 - 88);
	getSprite().setScale(-1.f, 1.f);
	setisFalled(false);
}
bool Mario::getIsJumping(void) {
	return isJumping;
}
bool Mario::getGroundRepeat(void) {
	return groundRepeat;
}
int Mario::getText(void) {
	return text;
}
bool Mario::getGroundTouched(void) {
	return groundTouched;
}
bool Mario::getJumpText(void) {
	return jumpText;
}
void Mario::setIsJumping(bool isJumping) {
	this->isJumping = isJumping;
}
void Mario::setSpace(bool space) {
	this->space=space;
}
void Mario::setGroundRepeat(bool groundRepeat) {
	this->groundRepeat = groundRepeat;
}
void Mario::setText(int text) {
	this -> text = text;
}
void Mario::setGroundTouched(bool groundTouched) {
	this->groundTouched = groundTouched;
}
void Mario::setJumpText(bool jumpText) {
	this->jumpText = jumpText;
}
