#pragma once
#include "Enemy.h"

class Obstacle :public Enemy
{

public:
	Obstacle(double x_, double y_, double bx, double by);
	void Update();
	void Draw();
};