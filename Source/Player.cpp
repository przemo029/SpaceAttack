#include "Player.h"


Player::Player()
{
	lives = 3;
	score = 0;
	image = NULL;
}

void Player::Init(ALLEGRO_BITMAP *i)
{
	try {
		cord.Init(30, 200, 10, 10, al_get_bitmap_width(i), al_get_bitmap_height(i), 0, 0);
		image = i;
	}
	catch (...)
	{
		throw;
	}
}
void Player::Update()
{
	cord.update_x(cord.get_dirX() * cord.get_movX());
	cord.update_y(cord.get_dirY() * cord.get_movY());
}
void Player::Draw()
{
	al_draw_bitmap(image, cord.get_x(), cord.get_y(), 0);
}
void Player::moveUp()
{
	cord.set_dirY(-1);
}
void Player::moveDown()
{
	cord.set_dirY(1);
}
void Player::moveLeft()
{
	cord.set_dirX(-1);
}
void Player::moveRight()
{
	cord.set_dirX(1);
}
void Player::resetDir()
{
	cord.set_dirX(0);
	cord.set_dirY(0);
}