#include "Collision.h"

//kolizja obiektu gracza z przeciwnkiem
void Collision::player_enemy(Player *p, list<GameObject *> game_obj)
{
	for (it = game_obj.begin(); it != game_obj.end(); it++)
	{
		//jesli uda sie zrzutowac na klase Enemy to wykonaj sprawdzenie kolizji
		if (Enemy *e = dynamic_cast<Enemy *>(*it))
		{
			if (p->cord.get_x() + p->cord.get_boundX() > (*it)->cord.get_x() &&
				p->cord.get_x() < (*it)->cord.get_x() + (*it)->cord.get_boundX() &&
				p->cord.get_y() + p->cord.get_boundY() > (*it)->cord.get_y() &&
				p->cord.get_y() < (*it)->cord.get_y() + (*it)->cord.get_boundY())
			{
				p->livesDown();
				(*it)->kill_object();
				cout << "Kolizja" << endl;
			}
		}
	}
}
//kolizja pocisku z przeciwnikiem
void Collision::weapon_enemy(Player *p,list<GameObject *> game_obj)
{
	for (it_w = game_obj.begin(); it_w != game_obj.end(); it_w++)
	{
		if (Weapon *w = dynamic_cast<Weapon*> (*it_w))
		{
			for (it_e = game_obj.begin(); it_e != game_obj.end(); it_e++)
			{
				if ((*it_e)->get_object_type() == "METEOR")
				{
					if ((*it_w)->cord.get_x() > (*it_e)->cord.get_x() &&
						(*it_w)->cord.get_x() < (*it_e)->cord.get_x() + (*it_e)->cord.get_boundX() &&
						(*it_w)->cord.get_y() > (*it_e)->cord.get_y() &&
						(*it_w)->cord.get_y() < (*it_e)->cord.get_y() + (*it_e)->cord.get_boundY())
					{
						cout << "Kolizja Bullet Meteor" << endl;
						p->scoreUp();
						(*it_w)->kill_object();
						(*it_e)->kill_object();
					}

				}

			}
		}
	}
}