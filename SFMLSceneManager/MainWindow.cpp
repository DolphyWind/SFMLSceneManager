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
}

void MainWindow::draw()
{
	m_window.clear(sf::Color::Black);

	m_window.display();
}

MainWindow::MainWindow()
{
	m_window.create(sf::VideoMode(m_windowWidth, m_windowHeight), "Window", sf::Style::Close);
	m_window.setFramerateLimit(FPS);
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
