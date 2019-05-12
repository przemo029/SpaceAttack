#pragma once
#include "GameObject.h"

class Weapon :public GameObject
{

public:
	Weapon();
	void Init(string t, ALLEGRO_BITMAP *i, double x_, double y_, double mx, double my, double bx, double by);
	virtual void Update();
	virtual void Draw();
};