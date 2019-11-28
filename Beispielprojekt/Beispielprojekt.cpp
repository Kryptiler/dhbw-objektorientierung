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
	Maincharacter Helferlein;
	Hindernisse Box;
	//int scroll = 0; // 0 = nicht scrollen, 1 = rechts scrollen, -1 = links scrollen
	double hintergrund = 0;
	double hintergrund2 = 1900;
	double scroll=0;
	bool run = true;
	int intervall = 120;
	double lost = -200;
	int wand = -696;
	double speed = 10;
	int modus = 0;
	double maus_x;
	double maus_y;
	int highscore = 0;
	vector<Hindernisse> boxen;
	
	Gosu::Image Boden;
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
	Gosu::Image Hindernis;
	Gosu::Image Hindernis_dead;
	Gosu::Image Blitz;
	//Gosu::Image Kiste;
	Gosu::Font font;
	Gosu::Font gameover;
	GameWindow()
		: Window(1920, 1080)
		, Boden("Sand1.png")
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
		, Hindernis("muelltonne2.png")
		, Hindernis_dead("weidezaun1.png")
		, Blitz("Blitz1.png")
		//, Kiste("kiste.png")
		, font(24)
		, gameover(38)
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
		case 0:
			graphics().draw_rect(200, 200, 200, 100, Gosu::Color::WHITE, 0.0);
			Blitz.draw_rot(maus_x, maus_y, 0.0, 300, 0.0,0.0,0.1,0.1);
			break;
		case 1:
			for (auto i = boxen.begin(); i != boxen.end(); i++)
			{
				if (i->get_deadly() == false)
				{
					//graphics().draw_rect(i->get_x(), i->get_y(), 100, 100, Gosu::Color::BLACK, 0.0);
					Hindernis.draw_rot(i->get_x(), i->get_y(), 0.0, 0.0, 0.0);
				}
				else
				{
					//graphics().draw_rect(i->get_x(), i->get_y(), 50, 100, Gosu::Color::WHITE, 0.0);
					Hindernis_dead.draw_rot(i->get_x(), i->get_y(), 0.0, 0.0, 0.0);
				}

			}

			switch (Helferlein.get_animation())
			{
			case 0:
				Helferlein_m.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 1:
				Helferlein_r.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 2:
				Helferlein_m.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 3:
				Helferlein_l.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 5:
				Helferlein_s.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 6:
				Helferlein_m_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 7:
				Helferlein_r_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 8:
				Helferlein_m_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 9:
				Helferlein_l_umg.draw_rot(Helferlein.get_x(), Helferlein.get_y(), 0.0, 0.0, 0.0, 1.0);
				break;
			case 10:
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
		}
	}

	// Wird 60x pro Sekunde aufgerufen
	
	void update() override
	{
		switch (modus)
		{
		case 0:
			maus_x = input().mouse_x();
			maus_y = input().mouse_y();
			if (input().down(Gosu::MS_LEFT) && maus_x < 400 && maus_x>200 && maus_y < 300 && maus_y>200)
			{
				modus = 1;
			}
			break;
		case 1:
			Helferlein.bewege();
			lost += speed - 2;
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
				lost -= scroll;
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
			if (intervall == 0)
			{
				intervall = 80 + (rand() % 80);
				speed += 0.8;
				Hindernisse neu;
				neu.set_deadly(rand() % 2);
				boxen.push_back(neu);
			}
			for (auto i = boxen.begin(); i != boxen.end(); i++)
			{
				i->scrollen(scroll);
				if (Helferlein.get_y() >= 775)
				{
					if (i->get_deadly() == false)
					{
						if ((Helferlein.get_x() + 150 >= i->get_x()) && (Helferlein.get_x() <= i->get_x()))
						{
							run = false;
						}
					}
					else
					{
						if ((Helferlein.get_x() + 75 >= i->get_x()) && (Helferlein.get_x() <= i->get_x()))
						{
							modus = 2;
						}
					}
				}
			}
			scroll = 0;
			if (lost >= Helferlein.get_x())
			{
				modus = 2;

			}
			break;
		case 2:			//Gameover
			if (highscore < Helferlein.get_score())
			{
				highscore = Helferlein.get_score();
			}
			break;
		case 3:			//Variablen resetten
			boxen.clear();
			intervall = 120;
			lost = -200;
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
