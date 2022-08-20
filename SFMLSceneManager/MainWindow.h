#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SceneManager.h"
#include "Scene.h"

class MainWindow
{
private:
	sf::RenderWindow m_window;
	const unsigned int FPS = 60;
	const sf::Time m_timePerFrame = sf::seconds(1.f / (float)FPS);
	unsigned int m_windowWidth = 800;
	unsigned int m_windowHeight = 600;

	SceneManager m_sceneManager;

	Scene m_scene1;
	sf::RectangleShape m_redSquare;

	Scene m_scene2;
	sf::RectangleShape m_blueSquare;

	void processEvents();
	void update(sf::Time deltaTime);
	void draw();

public:
	MainWindow();
	void mainLoop();
};
