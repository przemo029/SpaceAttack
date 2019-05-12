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

class GameLogic
{
	enum { LEFT, UP, RIGHT, DOWN, SPACE };
	bool key[5];
	bool draw;
	bool done;
	bool start;
	bool ended;
	int counter;
	double meteor_speed;
	bool flag;
	list <GameObject*> game_obj;
	list <GameObject*>::iterator it;
	Collision collision;
	Restrict restrict;
public:
	GameLogic();

	void checkEvents(ALLEGRO_EVENT  ev, ALLEGRO_EVENT_QUEUE *event_queue, Player *p, ALLEGRO_BITMAP *m, Background *bg);

	void create_enemy(ALLEGRO_BITMAP *m, Player *p);
	void change_speed(Player *p);
	void delete_not_alive();
	void check_player_lives(Player *p);
	void print_info(Player *p, ALLEGRO_FONT *font20, ALLEGRO_BITMAP *lives);

	bool get_done() { return done; };
	bool get_start() { return start; };
	bool get_draw() { return draw; };
	void set_draw(bool a) { draw = a; };
	bool get_ended() { return ended; };

	//gettery zwracajace wskazniki na liste obiektow
	list <GameObject*> get_list() { return game_obj; };
	list <GameObject*>::iterator get_begin() { return game_obj.begin(); };
	list <GameObject*>::iterator get_end() { return game_obj.end(); };
};