#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
//#include <Gosu/Bitmap.hpp>

#include <vector>
#include <string>
#include <iostream>
#include <cstdint>

#include "Vektor2d.h"
#include "Maincharacter.h"
#include "Hindernisse.h"
#include <time.h>
using namespace std;

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Maincharacter Helferlein;	//Spielcharakter
	Hindernisse Box;			//erstes Hindernis
	double hintergrund = 0;
	double hintergrund2 = 1900;
	double scroll = 0;
	bool run = true;
	int intervall = 120;
	int wand = -696;
	double speed = 10;
	int modus = 0;				// 0 = Menü, 1 = Spiel, 2 = GameOver, 3 = Variablen zurücksetzen
	double maus_x;
	double maus_y;
	int highscore = 0;
	vector<Hindernisse> boxen;
	
	Gosu::Image Hintergrund;
	Gosu::Image Hintergrund_umg;
	Gosu::Image Helferlein_l;
	Gosu::Image Helferlein_r;
	Gosu::Image Helferlein_m;
	Gosu::Image Helferlein_s;
	Gosu::Image Helferlein_l_umg;
	Gosu::Image Helferlein_r_umg;
	Gosu::Image Helferlein_m_umg;
	Gosu::Image Helferlein_s_umg;
	Gosu::Image Helferlein_steh;
	Gosu::Image Helferlein_steh_umg;
	Gosu::Image Tonne;
	Gosu::Image Zaun;
	Gosu::Image Blitz;
	Gosu::Font font;
	Gosu::Font gameover;
	GameWindow()
		: Window(1920, 1080)
		, Hintergrund("Haeuser_Hintergrund.png")
		, Hintergrund_umg("Haeuser_Hintergrund_umg.png")
		, Helferlein_l("Helferlein_Mittelpos.png")
		, Helferlein_r("Helferlein_rechts.png")
		, Helferlein_m("r_l_mittig.png")
		, Helferlein_s("Helferlein_Sprung.png")
		, Helferlein_l_umg("Helferlein_Mittelpos_umg.png")
		, Helferlein_r_umg("Helferlein_rechts_umg.png")
		, Helferlein_m_umg("r_l_mittig_umg.png")
		, Helferlein_s_umg("Helferlein_Sprung_umg.png")
		,Helferlein_steh("Helferlein_stehend.png")
		,Helferlein_steh_umg("Helferlein_stehend_umg.png")
		, Tonne("muelltonne2.png")
		, Zaun("weidezaun1.png")
		, Blitz("Blitz1.png")
		, font(24)
		, gameover(72)
	{
		set_caption("Cooles E-Techniker Spiel");
		boxen.push_back(Box);
		srand(time(NULL));					//Random Seed generieren
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Hintergrund.draw_rot(hintergrund, 540.0, 0.0, 0.0, 0.0);
		Hintergrund_umg.draw_rot(hintergrund2, 540.0, 0.0, 0.0, 0.0);
		switch (modus)
		{
		case 0:					// Menü
			graphics().draw_rect(200, 200, 200, 100, Gosu::Color::WHITE, 0.0);
			font.draw("Start", 270, 240.0, 0.0, 1.0, 1.0, Gosu::Color::BLUE);
			Blitz.draw_rot(maus_x, maus_y, 0.0, 300, 0.0,0.0,0.1,0.1);
			break;
		case 1:					//Spiel
			for (auto i = boxen.begin(); i != boxen.end(); i++)			//Hindernisse zeichnen
			{
				switch (i->get_deadly())
				{
				case 0:
					Tonne.draw_rot(i->get_x(), i->get_y(), 0.0, 0.0, 0.0);
					break;
				case 1:
					Zaun.draw_rot(i->get_x(), i->get_y(), 0.0, 0.0, 0.0);
					break;
				case 2:
					Blitz.draw_rot(i->get_x(), i->get_y() - 50, 0.0, 90, 0.0, 0.0, 0.2, 0.2);
				}
			}

			switch (Helferlein.get_animation())			//Laufanimation
			{
			case 0:										//nach rechts laufen
				Helferlein_steh.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 1:
				Helferlein_m.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 2:
				Helferlein_r.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 3:
				Helferlein_m.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 4:										//Sprung nach rechts
				Helferlein_s.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 5:										
				Helferlein_s.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 6:										//nach links laufen
				Helferlein_steh_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 7:
				Helferlein_m_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 8:
				Helferlein_r_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 9:
				Helferlein_m_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 10:									//Sprung nach links
				Helferlein_s_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			default:
				break;
			}

			font.draw("SCORE: " + std::to_string(Helferlein.get_score()), 1690.0, 90.0, 0.0, 1.0, 1.0, Gosu::Color::WHITE);
			font.draw("Rand: " + std::to_string(wand), 1400, 90.0, 0.0, 1.0, 1.0, Gosu::Color::WHITE);
			break;
		case 2:			//Gameoverscreen
			gameover.draw("Game Over", 900, 500.0, 0.0, 1.0, 1.0, Gosu::Color::RED);
			graphics().draw_rect(500, 200, 200, 100, Gosu::Color::WHITE, 0.0);
			graphics().draw_rect(500, 400, 200, 100, Gosu::Color::WHITE, 0.0);
			font.draw("SCORE: " + std::to_string(Helferlein.get_score()), 1690.0, 90.0, 0.0, 1.0, 1.0, Gosu::Color::WHITE);
			font.draw("Menu", 570, 240.0, 0.0, 1.0, 1.0, Gosu::Color::BLUE);
			font.draw("Beenden", 560.0, 440.0, 0.0, 1.0, 1.0, Gosu::Color::BLUE);
			font.draw("HIGHSCORE: " + std::to_string(highscore), 1690.0, 200.0, 0.0, 1.0, 1.0, Gosu::Color::WHITE);
			Blitz.draw_rot(maus_x, maus_y, 0.0, 300, 0.0, 0.0, 0.1, 0.1);
		}
	}

	// Wird 60x pro Sekunde aufgerufen
	
	void update() override
	{
		switch (modus)
		{
		case 0:					//Menü
			maus_x = input().mouse_x();
			maus_y = input().mouse_y();
			if (input().down(Gosu::MS_LEFT) && maus_x < 400 && maus_x>200 && maus_y < 300 && maus_y>200)
			{
				modus = 1;
			}
			break;
		case 1:					//Spiel
			Helferlein.bewege();
			wand += speed - 2;
			if (input().down(Gosu::KB_LEFT))
			{
				intervall++;
				scroll = Helferlein.left(speed - 2);
				hintergrund -= scroll;
				if (hintergrund >= 1900)
				{
					hintergrund = -1900;
				}
				hintergrund2 -= scroll;
				if (hintergrund2 >= 1900)
				{
					hintergrund2 = -1900;
				}
			}
			else if (input().down(Gosu::KB_RIGHT) && run == true)
			{
				intervall--;
				scroll = Helferlein.right(speed);
				hintergrund -= scroll;
				if (hintergrund <= -1900)
				{
					hintergrund = 1900;
				}
				hintergrund2 -= scroll;
				if (hintergrund2 <= -1900)
				{
					hintergrund2 = 1900;
				}
			}
			if (input().down(Gosu::KB_UP))
			{
				Helferlein.sprung();
			}
			run = true;
			if (intervall == 0)				//Hindernis erzeugen
			{
				intervall = 80 + (rand() % 80) - speed;
				speed += 0.8;
				Hindernisse neu;
				neu.set_deadly(rand() % 3);
				boxen.push_back(neu);
			}
			for (auto i = boxen.begin(); i != boxen.end(); i++)
			{
				i->scrollen(scroll);
				switch (i->get_deadly())
				{
				case 0:					//Mülltonne
					if ((Helferlein.get_x() + 150 >= i->get_x()) && (Helferlein.get_x() <= i->get_x()) && Helferlein.get_y() >= 775)
					{
						run = false;
					}
					break;
				case 1:					//Zaun
					if ((Helferlein.get_x() + 75 >= i->get_x()) && (Helferlein.get_x() <= i->get_x()) && Helferlein.get_y() >= 775)
					{
						modus = 2;
					}
					break;
				case 2:					//Blitz
					i->scrollen(5);
					if ((Helferlein.get_x() + 75 >= i->get_x()) && (Helferlein.get_x() <= i->get_x()) && Helferlein.get_y() >= 775)
					{
						modus = 2;
					}
					break;
				}
			}
			scroll = 0;
			if (wand >= Helferlein.get_score())
			{
				modus = 2;

			}
			break;
		case 2:			//Gameover
			if (highscore < Helferlein.get_score())
			{
				highscore = Helferlein.get_score();
			}
			maus_x = input().mouse_x();
			maus_y = input().mouse_y();
			if (input().down(Gosu::MS_LEFT) && maus_x < 700 && maus_x>500 && maus_y < 300 && maus_y>200)
			{
				modus = 3;
			}
			if (input().down(Gosu::MS_LEFT) && maus_x < 700 && maus_x>500 && maus_y < 500 && maus_y>300)
			{
				exit(0);
			}
			break;
		case 3:			//Variablen resetten
			boxen.clear();
			intervall = 120;
			wand = -696;
			speed = 10;
			Helferlein.reset();
			modus = 0;
		}
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
