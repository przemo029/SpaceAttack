#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "constants.h"
#include "cordinates.h"

using namespace std;

class GameObject
{
	string object_type;
	bool alive;
	ALLEGRO_BITMAP *image;

public:
	Cordinates cord;

	GameObject();

	void Init(string, bool, ALLEGRO_BITMAP *, double x, double y, double movX, double movY, int boundX, int boundY, int dirX, int dirY);
	virtual void Update();
	virtual void Draw();
	void kill_object();

	string get_object_type() { return object_type; };
	void set_object_type(string o) { object_type = o; };
	bool get_alive() { return alive; };
	bool set_alive() { alive = true;; };
	bool disable_alive() { alive = false; };
	ALLEGRO_BITMAP * get_bitmap() { return image; };
};
