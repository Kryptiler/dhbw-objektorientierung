#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"
#include "Maincharacter.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Maincharacter Helferlein;
	int scroll = 0; // 0 = nicht scrollen, 1 = rechts scrollen, -1 = links scrollen
	double hintergrund = 0;
	double hintergrund2 = 2990;
	Gosu::Image Boden;
	Gosu::Image Helferlein_l;
	Gosu::Image Helferlein_r;
	Gosu::Image Helferlein_m;
	Gosu::Image Helferlein_s;
	GameWindow()
		: Window(1920, 1080,true)
		, Boden("Sand1.png")
		, Helferlein_l("Helferlein_links.png")
		, Helferlein_r("Helferlein_rechts.png")
		, Helferlein_m("Helferlein_Mittelposition.png")
		, Helferlein_s("Helferlein_Sprung.png")
	{
		set_caption("Cooles E-Techniker Spiel");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Boden.draw_rot(hintergrund, 1250.0, 0.0, 0.0, 0.0);
		Boden.draw_rot(hintergrund2, 1250.0, 0.0, 0.0, 0.0);
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
		default:
			break;
		}
	}

	// Wird 60x pro Sekunde aufgerufen

	void update() override
	{

		Helferlein.bewege();
		if (input().down(Gosu::KB_LEFT))
		{
			Helferlein.left(15, hintergrund, hintergrund2);
		}
		if (input().down(Gosu::KB_RIGHT))
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
