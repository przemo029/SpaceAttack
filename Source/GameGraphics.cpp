#include "GameGraphics.h"

GameGraphics::GameGraphics(list <GameObject*> game_obj)
{
	this->game_obj = game_obj;
}

void GameGraphics::Draw()
{
	if (GL.get_draw() && al_event_queue_is_empty(event_queue))
	{
		//ekran startowy
		if (!GL.get_start()) al_draw_text(font64, al_map_rgb(255, 255, 0), WIDTH / 2 - 160, HEIGHT / 2 - 60, 0, "Start game");
		//ekran koncowy
		else if (GL.get_ended())
		{
			al_draw_text(font64, al_map_rgb(255, 255, 0), WIDTH / 2 - 230, HEIGHT / 2 - 70, 0, "End of the game");
			al_draw_textf(font32, al_map_rgb(255, 255, 0), WIDTH / 2 - 220, HEIGHT / 2, 0, "Your score: %i", p.get_score());
		}
		//rysowanie obiektow gry oraz gracza
		else
		{
			for (it = GL.get_begin(); it != GL.get_end(); it++)
			{
				(*it)->Draw();
			}
			p.Draw();
			//informacje o statystykach gry(punkty, liczba prob, predkosc)
			GL.print_info(&p, font20, lives);
		}

		al_flip_display();
		//rysowanie tla
		bg.Draw();

		GL.set_draw(false);
	}
}