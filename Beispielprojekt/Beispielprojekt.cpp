#include "stdafx.h"

#include <Gosu/Gosu.hpp>
#include <Gosu/AutoLink.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "Vektor2d.h"

// Simulationsgeschwindigkeit
const double DT = 100.0;

class GameWindow : public Gosu::Window
{
public:
	Gosu::Image Boden;
	GameWindow()
		: Window(3000, 2000)
		, Boden("Sand1.png")
	{
		set_caption("Cooles E-Techniker Spiel");
	}

	// wird bis zu 60x pro Sekunde aufgerufen.
	// Wenn die Grafikkarte oder der Prozessor nicht mehr hinterherkommen,
	// dann werden `draw` Aufrufe ausgelassen und die Framerate sinkt
	void draw() override
	{
		Boden.draw_rot(0.0, 1250.0, 0.0, 0.0, 0.0);
	}

	// Wird 60x pro Sekunde aufgerufen
	void update() override
	{
		//hallo welt, hab dich lieb
	}
};

// C++ Hauptprogramm
int main()
{
	GameWindow window;
	window.show();
}
