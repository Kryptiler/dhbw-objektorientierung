#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>
//#include <Gosu/Bitmap.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"
#include "Maincharacter.h"
#include "Hindernisse.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Maincharacter Helferlein;
	Hindernisse Box;
	int scroll = 0; // 0 = nicht scrollen, 1 = rechts scrollen, -1 = links scrollen
	double hintergrund = 0;
	double hintergrund2 = 1910;
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
	Gosu::Font font;
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
		, font(24)
	{
		set_caption("Cooles E-Techniker Spiel");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		//graphics().draw_rect(0, 0, 1980, 1000, Gosu::Color::WHITE, 0.0);
		Hintergrund.draw_rot(hintergrund, 540.0, 0.0, 0.0, 0.0);
		Hintergrund_umg.draw_rot(hintergrund2, 540.0, 0.0, 0.0, 0.0);
		//graphics().draw_rect(Box.get_x()+hintergrund, Box.get_y(), 100, 100, Gosu::Color::BLACK, 0.0);
		/*graphics().draw_triangle(
			Helferlein.get_x(), Helferlein.get_y(), Gosu::Color::WHITE,
			Helferlein.get_x() + 20, Helferlein.get_y()+10, Gosu::Color::WHITE,
			Helferlein.get_x(), Helferlein.get_y()+20, Gosu::Color::WHITE,
			0.0
		);*/
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
	}

	// Wird 60x pro Sekunde aufgerufen

	void update() override
	{

		Helferlein.bewege();
		if (input().down(Gosu::KB_LEFT))
		{
			Helferlein.left(15, hintergrund, hintergrund2);
		}
		else if (input().down(Gosu::KB_RIGHT))
		{
			Helferlein.right(14, hintergrund, hintergrund2);
		}
		if (input().down(Gosu::KB_UP))
		{
			Helferlein.sprung();
		}
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
