#include "Bullet.h"

Bullet::Bullet(double x_, double y_)
{
	Weapon::Init("BULLET", NULL, x_, y_, 10, 0, 0, 0);
}
void Bullet::Update()
{
	Weapon::Update();
}
void Bullet::Draw()
{
	al_draw_filled_circle(cord.get_x(), cord.get_y(), 3, al_map_rgb(255,255,255));
}