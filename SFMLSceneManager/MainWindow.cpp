#include "MainWindow.h"

void MainWindow::processEvents()
{
	sf::Event e;
	while (m_window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		default:
			break;
		}
	}
}

void MainWindow::update(sf::Time deltaTime)
{
	// Change scenes based on input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		m_sceneManager.setActiveScene(&m_scene1); // or m_sceneManager.setActiveScene(m_scene1.getName());
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		m_sceneManager.setActiveScene(&m_scene2); // or m_sceneManager.setActiveScene(m_scene2.getName());
}

void MainWindow::draw()
{
	m_window.clear(sf::Color::Black);

	m_sceneManager.draw();

	m_window.display();
}

MainWindow::MainWindow()
{
	m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), "Window", sf::Style::Close);
	m_window.setFramerateLimit(FPS);

	m_sceneManager.setParentWindow(&m_window);

	// Create Scenes
	m_redSquare.setSize(sf::Vector2f(50, 50));
	m_redSquare.setFillColor(sf::Color::Red);
	m_scene1.addSceneObject(&m_redSquare);
	m_scene1.setName("Red Square");

	m_blueSquare.setSize(sf::Vector2f(50, 50));
	m_blueSquare.setPosition(sf::Vector2f(50, 50));
	m_blueSquare.setFillColor(sf::Color::Blue);
	m_scene2.addSceneObject(&m_blueSquare);
	m_scene2.setName("Blue Square");

	// Add scenes to scene manager
	m_sceneManager.addScene(&m_scene1);
	m_sceneManager.addScene(&m_scene2);
	m_sceneManager.setActiveScene(&m_scene1); // or m_sceneManager.setActiveScene(m_scene1.getName());
}

void MainWindow::mainLoop()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (m_window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > m_timePerFrame)
		{
			timeSinceLastUpdate -= m_timePerFrame;
			processEvents();
			update(m_timePerFrame);
		}
		draw();
	}
}
