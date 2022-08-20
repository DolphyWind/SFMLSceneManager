#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class Scene
{
private:
	std::vector<sf::Drawable*> m_SceneObject;
	std::string m_sceneName;

public:
	Scene(std::string name);
	Scene();
	void addSceneObject(sf::Drawable *obj);
	void drawScene(sf::RenderWindow *renderWindow);
	void setName(std::string name);
	std::string getName();
};

