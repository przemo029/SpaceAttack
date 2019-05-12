#pragma once
#include "constants.h"
#include "Gameobject.h"
#include "cordinates.h"

class Background 
{
	double bitmap_width;
	ALLEGRO_BITMAP *image;
public:
	Cordinates cord;
	Background(ALLEGRO_BITMAP *background_bitmap);
	void Init(ALLEGRO_BITMAP *i, double x, double y, double movX, double movY, int boundX, int boundY, int dirX, int dirY);
	void Update();
	void Draw();
};