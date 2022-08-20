#pragma once
#include "Scene.h"
#include <iostream>
#include <vector>
#include <algorithm>

class SceneManager
{
private:
	std::vector<Scene*> m_scenes;
	Scene* m_activeScene = nullptr;
	sf::RenderWindow* m_parentWindow = nullptr;
public:
	SceneManager(sf::RenderWindow* parentWindow);
	SceneManager();
	void addScene(Scene *scene);
	void removeScene(Scene* scene);
	Scene* getScene(std::string name);
	void setActiveScene(std::string name);
	void setParentWindow(sf::RenderWindow* parentWindow);
	sf::RenderWindow* getParentWindow();
	void draw();
};

