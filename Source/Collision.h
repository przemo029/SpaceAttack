#pragma once
#include "Player.h"
#include "GameObject.h"
#include "Enemy.h"
#include "Weapon.h"
#include <list>
#include <typeinfo>
#include <allegro5\allegro.h>

class Collision
{
	list <GameObject*>::iterator it, it_w, it_e;
public:

	void player_enemy(Player *p, list<GameObject *> game_obj);
	void weapon_enemy(Player *p, list<GameObject *> game_obj);

};
