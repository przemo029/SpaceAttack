#pragma once
#include "Weapon.h"

class Bullet :public Weapon
{

public:
	Bullet(double x_, double y_);
	void Update();
	void Draw();
};