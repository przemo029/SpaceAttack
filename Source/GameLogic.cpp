#include "GameLogic.h"

GameLogic::GameLogic() 
{
	for (int i = 0; i < 5; i++)
	{
		key[i] = false;
	}

	draw = false;
	done = false;
	start = false;
	ended = false;
	flag = true;
	meteor_speed = 4.0;
	counter = 0;
}

//sprawdzanie wszystkich eventow pojawiajacych sie w trakcie gry
void GameLogic::checkEvents(ALLEGRO_EVENT ev, ALLEGRO_EVENT_QUEUE *event_queue, Player *p, ALLEGRO_BITMAP *m, Background *bg)
{
	if (ev.type == ALLEGRO_EVENT_TIMER)
	{
		if (start && !ended)
		{
			//sterowanie obiektem gracza
			if (key[LEFT])
				p->moveLeft();
			else if (key[RIGHT])
				p->moveRight();
			if (key[UP])
				p->moveUp();
			else if (key[DOWN])
				p->moveDown();

			//update dla wszystkich obiektow gry
			for (it = game_obj.begin(); it != game_obj.end(); it++)
			{
				(*it)->Update();
			}
			p->Update();
			bg->Update();

			create_enemy(m, p);

			restrict.player_restrict(p, game_obj);
			restrict.object_restrict(p, game_obj);

			collision.player_enemy(p, game_obj);
			collision.weapon_enemy(p, game_obj);

			change_speed(p);
			delete_not_alive();
			check_player_lives(p);
		}

		draw = true;
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_ESCAPE:
		{
			done = true;
			break;
		}
		case ALLEGRO_KEY_LEFT:
		{
			key[LEFT] = true;
			break;
		}
		case ALLEGRO_KEY_UP:
		{
			key[UP] = true;
			break;
		}
		case ALLEGRO_KEY_RIGHT:
		{
			key[RIGHT] = true;
			break;
		}
		case ALLEGRO_KEY_DOWN:
		{
			key[DOWN] = true;
			break;
		}
		case ALLEGRO_KEY_SPACE:
		{
			if (start && !ended)
			{
				Bullet *bullet = new Bullet(p->cord.get_x() + 40, p->cord.get_y() + 55);
				game_obj.push_back(bullet);
				break;
			}
			else
				start = true;

			//reset gry
			if (ended)
			{
				p->reset_score();
				p->set_lives(3);
				meteor_speed = 4.0;
				game_obj.clear();
				ended = false;
			}

		}
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode)
		{
		case ALLEGRO_KEY_LEFT:
		{
			key[LEFT] = false;
			p->resetDir();
			break;
		}
		case ALLEGRO_KEY_UP:
		{
			key[UP] = false;
			p->resetDir();
			break;
		}
		case ALLEGRO_KEY_RIGHT:
		{
			key[RIGHT] = false;
			p->resetDir();
			break;
		}
		case ALLEGRO_KEY_DOWN:
		{
			key[DOWN] = false;
			p->resetDir();
			break;
		}
		}
	}

	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		done = true;
	}

}

//losowe tworzenie przeciwnikow
void GameLogic::create_enemy(ALLEGRO_BITMAP *m_, Player *p)
{
	if (counter > COUNTER)
	{
		if (rand() % 5 == 0)
		{
			Meteor *m = new Meteor(WIDTH, rand() % 500 + 20, meteor_speed, m_);
			game_obj.push_back(m);
			counter = 0;

		}
		else if (rand() % 20 == 0)
		{
			Obstacle *o = new Obstacle(WIDTH, rand() % 450, rand() % 20 + 15, rand() % 100 + 80);
			game_obj.push_back(o);
			counter = 0;
		}
	}
	counter++;
}
//zmiana predkosci obiektow przeciwnika(meteor)
void GameLogic::change_speed(Player *p)
{
	if (p->get_score() % 5 == 0 && p->get_score() != 0 && flag)
	{
		meteor_speed += 0.2;
		flag = false;
	}
	if (!flag && p->get_score() % 5 != 0)
		flag = true;

}

//usuwanie obiektow z pamieci, gdy sa juz niewidoczne alive==false
void GameLogic::delete_not_alive()
{
	for (it = game_obj.begin(); it != game_obj.end();)
	{
		if ((*it)->get_alive() == false)
		{
			delete (*it);
			it = game_obj.erase(it);
			cout << "Calkowite usuniecie obiektu " << endl;
		}
		else
			it++;
	}
}
//sprawdzanie ilosci prob jesli <=0 zakoncz gre
void GameLogic::check_player_lives(Player *p)
{
	if (p->get_lives() <= 0)
		ended = true;
}

//drukuje statystyki gry
void GameLogic::print_info(Player *p, ALLEGRO_FONT *font20, ALLEGRO_BITMAP *lives)
{
	al_draw_textf(font20, al_map_rgb(255, 0, 0), 10, 15, 0, "Score: %d,  lives:", p->get_score());
	al_draw_textf(font20, al_map_rgb(255, 0, 0), 890, 15, 0, "Speed: %.2f", meteor_speed);

	for (int i = 0; i < p->get_lives(); i++)
	{
		al_draw_bitmap(lives, (i * 40) + 160, 5, 0);
	}
}