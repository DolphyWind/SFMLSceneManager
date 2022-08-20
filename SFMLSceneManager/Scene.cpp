#include "Scene.h"

Scene::Scene(std::string name)
{
	m_sceneName = name;
}

Scene::Scene()
{
	m_sceneName = "";
}

void Scene::addSceneObject(sf::Drawable* obj)
{
	m_SceneObject.push_back(obj);
}

void Scene::drawScene(sf::RenderWindow* renderWindow)
{
	for (int i = 0; i < m_SceneObject.size(); i++)
		renderWindow->draw(*m_SceneObject[i]);
}

void Scene::setName(std::string name)
{
	m_sceneName = name;
}

std::string Scene::getName()
{
	return m_sceneName;
}
