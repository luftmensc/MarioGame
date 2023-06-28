#include "Common.h"
class ScoreBoard {
	int score;
	int lives;
public:
	void setScore(int); 
	int getScore(void);
	int getlives(void);
	void setlives(int);
	void updatelives(int);
	void updateScore(int);
	void printscore(Text&,int);
	ScoreBoard();
	
};
