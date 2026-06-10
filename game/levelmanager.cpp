#include "levelmanager.h"
#include "scene.h"
#include <QDebug>

LevelManager::LevelManager(QObject *parent) : QObject(parent) {}

LevelManager::~LevelManager()
{
    clearScene();
}

void LevelManager::loadLevel(int levelNumber)
{
    clearScene();

    Q_UNUSED(levelNumber);

    emit sceneChanged();
}

void LevelManager::startGame()
{
    if (m_currentScene) {
        m_currentScene->initialize();
    }
}

void LevelManager::endGame()
{
    clearScene();
}

Scene *LevelManager::currentScene() const
{
    return m_currentScene;
}

void LevelManager::clearScene()
{
    if (m_currentScene) {
        qDebug() << "Scene eliminada:" << m_currentScene;
        delete m_currentScene;
        m_currentScene = nullptr;
    }
}
