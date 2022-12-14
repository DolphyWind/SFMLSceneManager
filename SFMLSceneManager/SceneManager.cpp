#include "SceneManager.h"

SceneManager::SceneManager(sf::RenderWindow* parentWindow)
{
	m_parentWindow = parentWindow;
}

SceneManager::SceneManager()
{
	m_parentWindow = nullptr;
}

void SceneManager::addScene(Scene* scene)
{
	if (m_scenes.size() == 0) m_activeScene = scene;
	m_scenes.push_back(scene);
}

void SceneManager::removeScene(Scene* scene)
{
	m_scenes.erase(std::remove(m_scenes.begin(), m_scenes.end(), scene), m_scenes.end());
}

Scene* SceneManager::getScene(std::string name)
{
	for (auto& i : m_scenes)
	{
		if (i->getName() == name) return i;
	}
	return nullptr;
}

void SceneManager::setActiveScene(std::string name)
{
	for (auto& i : m_scenes)
	{
		if (i->getName() == name)
			m_activeScene = i;
	}
}

void SceneManager::setActiveScene(Scene* scene)
{
	if (std::find(m_scenes.begin(), m_scenes.end(), scene) == m_scenes.end())
		throw std::exception("Scene Manager does not contain scene specified!");
	else
		m_activeScene = scene;
}

void SceneManager::setParentWindow(sf::RenderWindow* parentWindow)
{
	m_parentWindow = parentWindow;
}

sf::RenderWindow* SceneManager::getParentWindow()
{
	return m_parentWindow;
}

void SceneManager::draw()
{
	if (m_activeScene == nullptr || m_parentWindow == nullptr) return;
	m_activeScene->drawScene(m_parentWindow);
}
