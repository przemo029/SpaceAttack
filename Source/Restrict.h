#pragma once
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Weapon.h"
#include <list>
#include <typeinfo>
#include <allegro5\allegro.h>

class Restrict
{
	list <GameObject*>::iterator it;
public:
	void player_restrict(Player *p, list<GameObject *> game_obj);
	void object_restrict(Player *p, list<GameObject *> game_obj);
};