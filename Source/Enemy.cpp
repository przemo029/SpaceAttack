#include "Enemy.h"

Enemy::Enemy()
{
	GameObject::GameObject();
}

void Enemy::Init(string t, ALLEGRO_BITMAP *i, double x_, double y_, double mx, double my, double bx, double by, int l)
{
	GameObject::Init(t, true, i, x_, y_, mx, my, bx, by, -1, 0);
	lives = l;
}

void Enemy::Update()
{
	GameObject::Update();
}

void Enemy::Draw()
{
	GameObject::Draw();
}