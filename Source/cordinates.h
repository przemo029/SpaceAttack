#pragma once
#include <iostream>
#include <allegro5\allegro.h>
#include <string>

class Cordinates
{
	double x, y;
	double movX, movY;
	int boundX, boundY;
	int dirX, dirY;

public:

	Cordinates();

	void Init(double x, double y, double movX, double movY, int boundX, int boundY, int dirX, int dirY);
	void Update();

	const double get_x() { return x; };
	void set_x(double a) { x = a; };
	const double get_y() { return y; };
	void set_y(double a) { y = a; };
	const double get_movX() { return movX; };
	void set_movX(double a) { movX = a; };
	const double get_movY() { return movY; };
	void set_movY(double a) { movY = a; };
	const int get_boundX() { return boundX; };
	void set_boundX(int a) { boundX = a; };
	const int get_boundY() { return boundY; };
	void set_boundY(int a) { boundY = a; };
	const int get_dirX() { return dirX; };
	void set_dirX(int a) { dirX = a; };
	const int get_dirY() { return dirY; };
	void set_dirY(int a) { dirY = a; };

	void update_x(double a) { x += a; };
	void update_y(double a) { y += a; };
};