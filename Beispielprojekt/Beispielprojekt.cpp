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
			Helferlein.x, Helferlein.y, Gosu::Color::WHITE,
			Helferlein.x + 20, Helferlein.y+10, Gosu::Color::WHITE,
			Helferlein.x, Helferlein.y+20, Gosu::Color::WHITE,
			0.0
		);
	}

	// Wird 60x pro Sekunde aufgerufen

	void update() override
	{
		Helferlein.bewege();
		if (input().down(Gosu::KB_LEFT))
		{
			Helferlein.left();
		}
		if (input().down(Gosu::KB_RIGHT))
		{
			Helferlein.right();
		}
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
