#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class MainWindow
{
private:
	sf::RenderWindow m_window;
	const unsigned int FPS = 60;
	const sf::Time m_timePerFrame = sf::seconds(1.f / (float)FPS);
	unsigned int m_windowWidth = 800;
	unsigned int m_windowHeight = 600;

	void processEvents();
	void update(sf::Time deltaTime);
	void draw();

public:
	MainWindow();
	void mainLoop();
};
