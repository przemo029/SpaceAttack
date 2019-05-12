#include "GameObject.h"

GameObject::GameObject() 
{
	object_type = "";
	alive = true;
	image = NULL;
}
void GameObject::Init(string t, bool a, ALLEGRO_BITMAP *i, double x, double y, double movX, double movY, int boundX, int boundY, int dirX, int dirY)
{
	cord.Init(x, y, movX, movY, boundX, boundY, dirX, dirY);
	object_type = t;
	alive = a;
	image = i;

}
void GameObject::Update()
{
	cord.Update();
}
void GameObject::Draw()
{
	if(alive)
	al_draw_bitmap(image, cord.get_x() , cord.get_y() , 0);
}
//ustawienie zmiennej alive na false, oznaczenie obiektu do usuniecia
void GameObject::kill_object()
{
	if (alive)
		alive = false;
}