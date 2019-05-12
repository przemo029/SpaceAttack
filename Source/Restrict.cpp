#include "Restrict.h"

//ograniczenia dla obiektu player'a
void Restrict::player_restrict(Player *p, list<GameObject *> game_obj)
{
	if (p->cord.get_x() <= 0.0) p->cord.set_x(0.0);
	else if (p->cord.get_x() + p->cord.get_boundX() >= 400) p->cord.set_x(400 - p->cord.get_boundX());
	if (p->cord.get_y() + p->cord.get_boundY() / 3 <= 0.0) p->cord.set_y(0.0 - p->cord.get_boundY() / 3);
	else if (p->cord.get_y() + (p->cord.get_boundY() / 3) * 2 >= 600) p->cord.set_y(600 - (p->cord.get_boundY() / 3) * 2);
}

//ograniczenia dla uzbrojenia
void Restrict::object_restrict(Player *p, list<GameObject *> game_obj)
{
	for (it = game_obj.begin(); it != game_obj.end(); it++)
	{
		if (Weapon *w = dynamic_cast<Weapon *>(*it))
		{
			if ((*it)->cord.get_x() >= WIDTH)
			{
				(*it)->kill_object();
				cout << "Skasowano obiekt Weapon" << endl;
			}
		}
		else if (Enemy *e = dynamic_cast<Enemy *>(*it))
		{
			if ((*it)->cord.get_x() + (*it)->cord.get_boundX() <= 0)
			{
				if ((*it)->get_object_type() != "OBSTACLE")
					p->livesDown();
				(*it)->kill_object();
				cout << "Skasowano obiekt Enemy " << endl;
			}
		}
	}
}
