#include "Common.h"
#include "Mario.h"
#include "turtle.h"
#include "ScoreBoard.h"

class Game {
private:
	RenderWindow* window;
	Mario mario;
	Mario* mario_ptr = &mario;
	Texture bgTexture;
	Sprite bgSprite;
	//mario texture and sprites
	Texture marioTexture;	Texture marioTexture2; 	Texture marioTexture3;	Texture marioTexture4;
	Sprite marioSprite;		Sprite marioSprite2;	Sprite marioSprite3;	Sprite marioSprite4;

	Texture marioJumpTexture;	Texture flTexture;
	Sprite marioJumpSprite;		Sprite flSprite;
	//brick texture and sprites
	Texture brickTexture1;	Texture brickTexture2;	Texture brickTexture3;	Texture brickTexture4;
	Sprite brickSprite1;	Sprite brickSprite2;	Sprite brickSprite3;	Sprite brickSprite4;

	Texture brickTexture5;	Texture brickTexture6;	Texture brickTexture7;
	Sprite brickSprite5;	Sprite brickSprite6;	Sprite brickSprite7;
	//pipe texture and sprites
	Texture pipeTexture1;	Texture pipeTexture2;
	Sprite pipeSprite1;		Sprite pipeSprite2;

	Texture pipeSTexture1;	Texture pipeSTexture2;
	Sprite pipeSSprite1;	Sprite pipeSSprite2;

	Object* objects;
	//font texture and sprites
	Font font;
	Text text;	Text text2;	Text text3;	Text text4;

	Text text5;	Text text6;	Text text7;	Text text8;

	Texture healthTexture;	Sprite healthSprite;

public:
	turtle* addturtle(int);
	void deleteobject();
	bool checkCollusion(Object* , Mario*,int& );
	void handleInput(void);
	int speed;
	Game(int);
	void update(void);
	void run(void);
	void drawobjects();
	void moveobjects();
	double abs(double);
	
	bool screen = true;
	int turtle_count = 0;
	const int maxHealth = 3;
	int health = maxHealth;  //constructorla yapalım
	vector<Sprite> marioHeads;
	bool collisionOccurred = false; 
	int collNum = 0;
	bool collision = false;
	bool dying_animate = false;
	bool isGameOver = false;

};

