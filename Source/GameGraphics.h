#pragma once
#include "constants.h"
#include "Player.h"
#include "GameObject.h"
#include "Bullet.h"
#include "Meteor.h"
#include "Collision.h"
#include "Obstacle.h"
#include "Background.h"
#include "Restrict.h"
#include <list>
#include <typeinfo>
#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

#include "include.h"

class GameGraphics
{
	list <GameObject*> game_obj;
public:
	GameGraphics(list <GameObject*> game_obj);

	void Draw();
};