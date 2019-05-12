#pragma once
#include "Enemy.h"

class Meteor :public Enemy
{

public:
	Meteor(double x_, double y_, double s, ALLEGRO_BITMAP *m);
	void Update();
	void Draw();
};