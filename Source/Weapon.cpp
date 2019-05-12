#include "Weapon.h"

Weapon::Weapon()
{
	GameObject::GameObject();
}
void Weapon::Init(string t, ALLEGRO_BITMAP *i, double x_, double y_, double mx, double my, double bx, double by)
{
	GameObject::Init(t, true, i, x_, y_, mx, my, bx, by, 1, 0);
}
void Weapon::Update()
{
	GameObject::Update();
}
void Weapon::Draw()
{
	GameObject::Draw();
}