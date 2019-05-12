#pragma once
#include "cordinates.h"

class Player
{
	int lives;
	int score;
	ALLEGRO_BITMAP *image;

public:
	Cordinates cord;

	Player();

	void Init(ALLEGRO_BITMAP *i);
	void Update();
	void Draw();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void resetDir();

	void scoreUp() { score++; };
	void livesDown() { lives--; };
	void reset_score() { score = 0; };
	void set_lives(int l) { lives = l; };
	int get_lives() { return lives; };
	int get_score() { return score; };
};