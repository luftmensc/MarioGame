#include "ScoreBoard.h"
#include <format>
#include "Common.h"

void ScoreBoard::setScore(int score) { //sets the score
	this->score = score;

}

int ScoreBoard::getScore() { //gets the score
	return this->score;

}

int ScoreBoard::getlives() { //gets the remaining lives
	return this->lives;

}

void ScoreBoard::setlives(int lives) { //sets the remaining lives
	this->lives = lives;

}

ScoreBoard::ScoreBoard() { //constructor of the scoreboard
	this->score = 0;
	this->lives = MAX_HEALTH;
}

void ScoreBoard::updatelives(int update) { //updates the remaining lives if mario is dead
	lives = lives + update;

}
void ScoreBoard::updateScore(int update) { //updates the score if mario beats turtle
	score = score + update;

}

void ScoreBoard::printscore(Text& text, int score) { //prints the score to the screen
	string sscore = "POINTS: "+to_string(score);
	text.setString(sscore);
}