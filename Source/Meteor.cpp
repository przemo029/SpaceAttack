#include "Meteor.h"

Meteor::Meteor(double x_, double y_, double s, ALLEGRO_BITMAP *m)
{
	Enemy::Enemy();
	Enemy::Init("METEOR", m, x_, y_, s, 0, al_get_bitmap_width(m), al_get_bitmap_height(m), 1);
}

void Meteor::Update()
{
	Enemy::Update();
}

void Meteor::Draw()
{
	Enemy::Draw();
}