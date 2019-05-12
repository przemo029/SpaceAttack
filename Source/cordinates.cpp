#include "cordinates.h"

Cordinates::Cordinates()
{
	x = y = movX = movY = boundX = boundY = dirX = dirY = 0;
}

void Cordinates::Init(double x, double y, double movX, double movY, int boundX, int boundY, int dirX, int dirY)
{
	try
	{
		Cordinates::x = x;
		Cordinates::y = y;
		Cordinates::movX = movX;
		Cordinates::movY = movY;
		Cordinates::boundX = boundX;
		Cordinates::boundY = boundY;
		Cordinates::dirX = dirX;
		Cordinates::dirY = dirY;
	}
	catch (...)
	{
		throw;
	}

}

void Cordinates::Update()
{
	x += movX * dirX;
	y += movY * dirY;
}

