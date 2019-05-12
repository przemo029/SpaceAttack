#pragma once
#include "GameObject.h"

class Enemy :public GameObject
{
	int lives;
public:
	Enemy();
	void Init(string t, ALLEGRO_BITMAP *i, double x_, double y_, double mx, double my, double bx, double by, int l);
	virtual void Update();
	virtual void Draw();

	int get_lives() { return lives; };
	void dec_lives() { lives--; };
};