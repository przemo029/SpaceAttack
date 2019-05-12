#include "include.h"

using namespace std;

int main()
{
	srand(time(NULL));

	//---- zmienne lokalne ----
	bool done = false;	//uzywana do glownej petli programu
	int FPS = 60;	//uzywana do odswiezenia 60 razy na sekunde

	//proba inicjalizacji biblioteki
	try
	{
		if (!al_init())
			throw "Filed to initialize Allegro5 !";

		display = al_create_display(WIDTH, HEIGHT);	//tworzenie okna

		if (!display)
			throw "Filed to initialize display !";
	}
	//przechwycenie wyjatku
	catch(char *s)
	{
		al_show_native_message_box(0, 0, 0, s, 0, 0);
	}

	//---- inicjalizacja komponentów allegro ----
	try
	{
		if (!al_init_primitives_addon()
			|| !al_install_keyboard()
			|| !al_init_font_addon()
			|| !al_init_ttf_addon()
			|| !al_init_image_addon()
			) throw "Failed to initialize Allegro component";

	}
	catch (char *s)
	{
		al_show_native_message_box(0, 0, 0, s, 0, 0);
	}
	//---- ladowanie czcionek i bitmap ----
	try
	{
		if (!(font64 = al_load_font("Alabama.ttf", 64, 0)) ||
			!(font32 = al_load_font("Alabama.ttf", 32, 0)) ||
			!(font20 = al_load_font("Alabama.ttf", 20, 0)) ||
			!(player_bitmap = al_load_bitmap("free-blue-spaceship.png")) ||
			!(meteor = al_load_bitmap("m1.png")) ||
			!(lives = al_load_bitmap("free-blue-spaceship-min.png"))||
			!(background_bitmap = al_load_bitmap("back.png"))
			) throw "Failed to load bitmap or font";
	}
	catch (char *s)
	{
		al_show_native_message_box(0, 0, 0, s, 0, 0);
	}

	//---- Tworzenie obiektow ----
	Player p;
	GameLogic GL;
	GameGraphics GG(GL.get_list());
	Background bg(background_bitmap);
	list <GameObject*>::iterator it;

	//inicjowanie obiektu gracza
	try
	{
		p.Init(player_bitmap);
	}
	catch (...)
	{
		al_show_native_message_box(0, 0, 0, "Failed to initialize player object", 0, 0);
	}

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	//start timera
	al_start_timer(timer);

	//---- glowna petla programu ----
	while (!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		//===LOGIKA===
		//metoda sprawdzajaca pojawiajace sie eventy
		//obslugujaca cala logike gry
		GL.checkEvents(ev, event_queue, &p, meteor, &bg);
		//============

		//===GRAFIKA===

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

		//==========

		//wykonuj dopoki glowna petle done!=true
		done = GL.get_done();

	}

	//zniszczenie obiektow przed wyjsciem z programu
	al_destroy_display(display);
	al_destroy_bitmap(player_bitmap);
	al_destroy_bitmap(meteor);
	al_destroy_bitmap(lives);
	al_destroy_bitmap(background_bitmap);

	return 0;

}


