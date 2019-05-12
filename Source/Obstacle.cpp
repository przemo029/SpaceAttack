#include "Obstacle.h"

Obstacle::Obstacle(double x_, double y_, double bx, double by)
{
	Enemy::Enemy();
	Enemy::Init("OBSTACLE", NULL, x_, y_, 4, 0, bx, by, 1);
}

void Obstacle::Update()
{
	Enemy::Update();
}

void Obstacle::Draw()
{
	al_draw_filled_rectangle(cord.get_x(), cord.get_y(), cord.get_x() + cord.get_boundX(), cord.get_y() + cord.get_boundY(),al_map_rgb(0,96,160));
}