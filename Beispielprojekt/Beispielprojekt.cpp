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
	Gosu::Image Boden;
	GameWindow()
		: Window(1920, 1080)
		, Boden("Sand1.png")		
	{
		set_caption("Cooles E-Techniker Spiel");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Boden.draw_rot(0.0, 1000.0, 0.0, 0.0, 0.0);
		graphics().draw_triangle(
			Helferlein.get_x(), Helferlein.get_y(), Gosu::Color::WHITE,
			Helferlein.get_x() + 20, Helferlein.get_y()+10, Gosu::Color::WHITE,
			Helferlein.get_x(), Helferlein.get_y()+20, Gosu::Color::WHITE,
			0.0
		);
	}

	// Wird 60x pro Sekunde aufgerufen

	void update() override
	{
		Helferlein.bewege();
		if (input().down(Gosu::KB_LEFT))
		{
			Helferlein.left(2);
		}
		if (input().down(Gosu::KB_RIGHT))
		{
			Helferlein.right(2);
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
