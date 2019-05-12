#include "Background.h"

Background::Background(ALLEGRO_BITMAP *background_bitmap)
{
	Background::Init(background_bitmap, 0, 0, 1.5, 0, 0, 0, -1, 0);
	bitmap_width = al_get_bitmap_width(background_bitmap);
	image = background_bitmap;
}

void Background::Init( ALLEGRO_BITMAP *i, double x, double y, double movX, double movY, int boundX, int boundY, int dirX, int dirY)
{
	cord.Init(x, y, movX, movY, boundX, boundY, dirX, dirY);
}

void Background::Update()
{
	//gdy bitmapa znika z okna ustawiamy wartosc poczatkowa
	cord.Update();
	if (cord.get_x() + bitmap_width < 0)
	{
		cord.set_x(0);
	}
}

void Background::Draw()
{
	al_draw_bitmap(image, cord.get_x(), cord.get_y(), 0);
	//doklejanie jednej bitmapy do drugiej, efekt przesuwania
	if (cord.get_x() + bitmap_width < WIDTH)
	{
		al_draw_bitmap(image, cord.get_x() + bitmap_width, cord.get_y(), 0);
	}
}