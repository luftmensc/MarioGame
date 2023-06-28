#include "Game.h"

Game::Game(int speed) {

	this->speed = speed;
	this->objects = nullptr;
	window = new RenderWindow(sf::VideoMode(W_WIDTH, W_HEIGHT), "MARIO");

	healthTexture.loadFromFile("../assets/mariohead.png");
	healthSprite.setTexture(healthTexture);

	//font loading
	font.loadFromFile("../assets/font.ttf");
	
	// setting the fonts
	text.setFont(font);
	text.setString("MARIO");
	text.setCharacterSize(250);
	text.setFillColor(sf::Color::Red); 
	text.setPosition(500, 0); 
	text.setScale(1, 2);

	text2.setFont(font);
	text2.setString("-Press Enter to Start a New Game");
	text2.setCharacterSize(40);
	text2.setFillColor(sf::Color::Yellow); 
	text2.setPosition(550, 700); 

	text3.setFont(font);
	text3.setString("GAME OVER");
	text3.setCharacterSize(130); 
	text3.setFillColor(sf::Color::Red); 
	text3.setPosition(500, 100); 
	text3.setScale(1, 2);

	text4.setFont(font);
	text4.setString("- Press Enter to Quit");
	text4.setCharacterSize(40); 
	text4.setFillColor(sf::Color::Yellow);
	text4.setPosition(670, 700); 

	text5.setFont(font);
	text5.setString("- Press ESC to Return to Main Menu");
	text5.setCharacterSize(40); 
	text5.setFillColor(sf::Color::Yellow);
	text5.setPosition(600, 800); 

	text7.setFont(font);
	text7.setString("POINTS: 0");
	text7.setCharacterSize(40);
	text7.setFillColor(sf::Color::Yellow); 
	text7.setPosition(1920/2-100, 0);

	text8.setFont(font);
	text8.setString("YOU WIN");
	text8.setCharacterSize(130); 
	text8.setFillColor(sf::Color::Red); 
	text8.setPosition(690, 100); 
	text8.setScale(1, 2);

	//background texture loading
	bgTexture.loadFromFile("../assets/bg.jpg ");
	bgTexture.setRepeated(true);
	bgSprite.setTexture(bgTexture);
	bgSprite.setTextureRect(IntRect(0, 0, window->getSize().x, window->getSize().y));
	//floor texture loading
	flTexture.loadFromFile("../assets/floor.png ");
	flTexture.setRepeated(true);
	flSprite.setTexture(flTexture);
	flSprite.setTextureRect(IntRect(0, 1000, 1920, 66));
	flSprite.setPosition(0, 1000);

	//bricks texture loadings
	brickTexture1.loadFromFile("../assets/brick.png");
	brickTexture1.setRepeated(true);
	brickSprite1.setTexture(brickTexture1);
	brickSprite1.setTextureRect(IntRect(0, 0, 690, 34));
	brickSprite1.setPosition(0, 770);

	brickTexture2.loadFromFile("../assets/brick.png");
	brickTexture2.setRepeated(true);
	brickSprite2.setTexture(brickTexture2);
	brickSprite2.setTextureRect(IntRect(0, 0, 690, 34));
	brickSprite2.setPosition(1920 - 690, 770);

	brickTexture3.loadFromFile("../assets/brick.png");
	brickTexture3.setRepeated(true);
	brickSprite3.setTexture(brickTexture3);
	brickSprite3.setTextureRect(IntRect(0, 0, 30 * 8, 34));
	brickSprite3.setPosition(0, 570);

	brickTexture4.loadFromFile("../assets/brick.png");
	brickTexture4.setRepeated(true);
	brickSprite4.setTexture(brickTexture4);
	brickSprite4.setTextureRect(IntRect(0, 0, 30 * 8, 34));
	brickSprite4.setPosition(1920 - 30 * 8, 570);

	brickTexture5.loadFromFile("../assets/brick.png");
	brickTexture5.setRepeated(true);
	brickSprite5.setTexture(brickTexture5);
	brickSprite5.setTextureRect(IntRect(0, 0, 30 * 32, 34));
	brickSprite5.setPosition(30 * 16, 570 - 80);

	brickTexture6.loadFromFile("../assets/brick.png");
	brickTexture6.setRepeated(true);
	brickSprite6.setTexture(brickTexture6);
	brickSprite6.setTextureRect(IntRect(0, 0, 30 * 28, 34));
	brickSprite6.setPosition(0, 250);

	brickTexture7.loadFromFile("../assets/brick.png");
	brickTexture7.setRepeated(true);
	brickSprite7.setTexture(brickTexture7);
	brickSprite7.setTextureRect(IntRect(0, 0, 30 * 28, 34));
	brickSprite7.setPosition(30 * 36, 250);

	//pipe textures loadings
	pipeTexture1.loadFromFile("../assets/pipe.png ");
	pipeTexture1.setRepeated(true);
	pipeSprite1.setTexture(pipeTexture1);
	pipeSprite1.setTextureRect(IntRect(0, 0, 130, 74));
	pipeSprite1.setPosition(130, 1000 - 80);
	pipeSprite1.setScale(-1.f, 1.f);

	pipeTexture2.loadFromFile("../assets/pipe.png ");
	pipeTexture2.setRepeated(true);
	pipeSprite2.setTexture(pipeTexture1);
	pipeSprite2.setTextureRect(IntRect(0, 0, 130, 74));
	pipeSprite2.setPosition(1920 - 130, 1000 - 80);

	pipeSTexture1.loadFromFile("../assets/pipeS.png ");
	pipeSSprite1.setTexture(pipeSTexture1);
	pipeSSprite1.setPosition(0, 250 - 130);

	pipeSTexture2.loadFromFile("../assets/pipeS.png ");
	pipeSSprite2.setTexture(pipeSTexture2);
	pipeSSprite2.setPosition(1920, 250 - 130);
	pipeSSprite2.setScale(-1.f, 1.f);



}
void Game::update(void) {
	ScoreBoard scoreboard;
	int counter = 0;
	int side = 0;
	int collision_side = 0;
	float increase = 0.f;
	
	int speed_counter = 1;
	int livingturtle = 5;
	
	while (window->isOpen())

	{
		
		
		Event event;
		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		while (screen) {

			while (window->pollEvent(event))
			{
				if (event.type == Event::Closed)
					window->close();
			}

			window->clear();
			//draws main menu
			window->draw(bgSprite);
			window->draw(text);
			window->draw(text2);
			window->draw(text6);
			window->display();
			sf::sleep(milliseconds(200 / speed));
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				screen = false;
			}
			
		}

		 
		window->clear();
		run(); // Mario running animation
		//adds turtle after a certain number of iterations but also limits the number of turtles 
		if (counter % 100 == 0 && turtle_count<5) {
			
			addturtle(side);
			turtle_count++;

			if (side == 0) {
				side = 1; //next turtle that will be born is going to be placed on the opposite side of the screen
			}
			else  {
				side = 0;//next turtle that will be born is going to be placed on the opposite side of the screen
			}
			counter = 0;
		}
		//moves the object
		moveobjects();
		Object* current = objects;  

		if (!collisionOccurred) { // !checkcollision is added to prevent constant collision between 2 collided objects
			while (current) {
				if (current->getisLiving() == false) { //do not check dead turtle for collision
					current = current->next;
					if (current == nullptr) {
						break;
					}
				}
				collision = checkCollusion(current, mario_ptr, collision_side);
				//if collision happened
				if (collision) {

					if (collision_side == 1) { //horizontal collision
						scoreboard.updatelives(-1);
						collisionOccurred = true;
						mario_ptr->fall();
							
					}
					else if (collision_side == 2) { //vertical collision
						scoreboard.updateScore(100);
						livingturtle--;
						scoreboard.printscore(text7, scoreboard.getScore());
						
						current->setisLiving(false);
						current->fall();
						
						
					}
					if(scoreboard.getlives()<=0)
					{
						isGameOver = true;
					}
					break;
				}
				current = current->next;
			}
		}

		if (isGameOver) {
			//game over screen
			window->clear();
			window->draw(bgSprite);
			window->draw(text3);
			window->draw(text4);
			window->draw(text5);
			window->display();
			//if user presses enter 
			if (Keyboard::isKeyPressed(Keyboard::Enter))
			{
				window->close();
				return;
			}
			//if user presses escape
			else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				window->close();
				delete this; //deletes the current game object
				Game* game = new Game(SPEED); //create a new game object
				game->update();
				return;
			}	
		}
		else {
			//drawing everything to the screen 

			window->draw(bgSprite);
			window->draw(flSprite);
			window->draw(brickSprite1);
			window->draw(brickSprite2);
			window->draw(brickSprite3);
			window->draw(brickSprite4);
			window->draw(brickSprite5);
			window->draw(brickSprite6);
			window->draw(brickSprite7);
			window->draw(pipeSprite1);
			window->draw(pipeSprite2);
			window->draw(pipeSSprite1);
			window->draw(pipeSSprite2);
			window->draw(mario.sprite);
			window->draw(text7);

			//printing marioheads as the indicator of the remaining lives
			for (int i = 0; i < scoreboard.getlives(); ++i)
			{
				healthSprite.setPosition(window->getSize().x - (i + 1) * 34, 0); // Sa� �st k��ede yan yana yerle�tir
				marioHeads.push_back(healthSprite);
				window->draw(marioHeads[i]);
			}
			//incrementing the variable increase after a specific number of iterations to increase the speed of turtle
			if (speed_counter % 1000 == 0) {
				
				
				increase +=1;
				if (increase >= 10) {
					increase = 10;
				}
			}
			current = objects; 
			
			while (current) {
				if (!current->isLiving) {
					current = current->next;
					if (current == nullptr) {
						break;
					}
				}
				else {
					current->updateTurtleSpeed(increase); //turtle speed increase if turtle is living
				}
				
				
				current = current->next;
				}
			current = objects;
			//drawing the objects to the screen 
			drawobjects();
			//deleting object if it is dead
			deleteobject();
			
			// Game won quit scene
			if (livingturtle == 0) {
				while (true) {
					window->clear();
					window->draw(bgSprite);
					window->draw(text8);
					window->draw(text5);
					window->display();
					if (Keyboard::isKeyPressed(Keyboard::Escape)) {
						window->close();
						delete this;
						Game* game = new Game(SPEED);
						game->update();
					}
				}
			}
			//draws objects to the screen
			
			window->display(); //displaying the screen

			sf::sleep(milliseconds(200 / speed));

			//turtle speed increase
			counter += 1;
			speed_counter += 1;
		}
		

	}
}
void Game::run(void)
{
	
	if (collisionOccurred == false) { 
		mario.sprite.setTexture(mario.textures[0]); // standing texture
	}
	mario.sprite.move(0.f, -mario.getVy());

	if (collisionOccurred==true) {
		
		mario.setisFalled(mario.isFalled());
		
		if (mario.getisFalled()) {
			collisionOccurred = false;
			mario.sprite.setPosition(200,1080-88); // setting mario to starting position
		}
	}
	if (collisionOccurred == false) {
		handleInput(); //if turtle is dead, no keyboard input should be read

	}
	
	
}
void Game::handleInput(void)
{
	mario.groundCondition(); //checking the ground condition initally to set Y axis speed correct

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{

		if (mario.getGroundTouched() && mario.sprite.getPosition().y < 992) {
			mario.sprite.move(0.f, 3.f);
		}
	}
	mario.gravity();//gravity effect
	
	if (mario.getIsJumping()) //to apply jumping texture correctly
	{	
		mario.sprite.setTexture(mario.textures[6]);
		mario.setJumpText(true);

		if (mario.getGroundTouched())
		{
			mario.sprite.setTexture(mario.textures[1]);//standing text
			mario.setIsJumping(false);
			mario.setJumpText(false);
		}
	}
	

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		mario.move(0);

	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		mario.move(1);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		mario.setIsJumping(true);
		mario.setGroundTouched(false);

		if (mario.getGroundRepeat()) {
			mario.setVy(10);
			mario.setGroundRepeat(false);
		}
	}
}

turtle* Game::addturtle(int side) { //adding turtles
	
	turtle* Turtle = new turtle(window);
	Turtle->setside(side);
	Turtle->next = objects;
	objects = Turtle;
	return Turtle;
}


void Game::drawobjects() { //drawing the objects to the screen 
	Object* current = objects;
	while (current) {
		current->draw(window);
		current = current->next;
	}
}
void Game::moveobjects() { //moves the objects
	Object* current = objects;
	while (current) {
		current->move();
		current = current->next;
	}
}

//Function checks whether collision is happened and changes the value of the marker which determines the collision side.
//Whether collision is ocurred vertically or horizontally
bool Game::checkCollusion(Object* turtle_ptr, Mario* mario_ptr, int& collision_side) { //checking collisions to count points and game logics
	double tolerance = 100;

	FloatRect turtleBounds = turtle_ptr->getBounds();
	FloatRect marioBounds = mario_ptr->getBounds();
	double turtle_size = turtle_ptr->getTexture().getSize().y;
	double mario_size = mario_ptr->getTexture().getSize().y;
	Vector2f mario_pos = mario_ptr->getSprite().getPosition();
	Vector2f turtle_pos = turtle_ptr->getSprite().getPosition();
	double diff_x = turtle_pos.x - (mario_pos.x + mario_ptr->getTexture().getSize().x / 2);
	double mario_top = mario_ptr->getSprite().getPosition().y;
	double mario_bottom = mario_ptr->getSprite().getPosition().y + mario_size;
	double turtle_top = turtle_ptr->getSprite().getPosition().y - turtle_size / 2;
	double turtle_bottom = turtle_ptr->getSprite().getPosition().y + turtle_size / 2;
	double mario_origin = mario_ptr->getSprite().getPosition().y + mario_size / 2;
	double turtle_origin = turtle_ptr->getSprite().getPosition().y;
	


	if (turtleBounds.intersects(marioBounds)) {

		if(abs(turtle_bottom-mario_bottom)<tolerance) {
			if ((turtle_ptr->getHeading() == 1 && diff_x <= 0) || (turtle_ptr->getHeading() == 0 && diff_x > 0)) {
				if (mario_ptr->getVy() < 0) {
					collision_side = 2;
				}
				else {
					collision_side = 1;
				}
			}
			else {
				collision_side = 0;
				if (mario_ptr->getVy() < 0) {
					collision_side = 2;
				}
			}
		}
		else {	
			collision_side = 2;
			return true;
		}
}
	else {
		return false;
	}

		
}
//absolute value function
double Game::abs(double x) {
	if (x > 0) {
		return x;
	}
	else {
		return -x;
	}
}


void Game::deleteobject() { //deleting objects
	Object* current = objects;
	Object* prev = nullptr;
	while (current) {

		if (current->isFalled()) {
			if (prev) {
				prev->next = current->next;
			}
			else {
				objects = objects->next;
			}
			//turtle_count--;
			delete current;
			return;
		}
		prev = current;
		current = current->next;
	}
}
