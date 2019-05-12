#pragma once

#include <iostream>
#include <cstdlib>
#include <list>
#include <time.h>
#include <thread>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>

#include "constants.h"
#include "cordinates.h"
#include "GameObject.h"
#include "Player.h"
#include "GameLogic.h"
#include "GameGraphics.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Meteor.h"
#include "Collision.h"
#include "Obstacle.h"
#include "Background.h"

//---- zmienne biblioteczne allegro ----
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_FONT *font64 = NULL;
ALLEGRO_FONT *font32 = NULL;
ALLEGRO_FONT *font20 = NULL;
ALLEGRO_BITMAP *background_bitmap = NULL;
ALLEGRO_BITMAP *player_bitmap = NULL;
ALLEGRO_BITMAP *meteor = NULL;
ALLEGRO_BITMAP *lives = NULL;