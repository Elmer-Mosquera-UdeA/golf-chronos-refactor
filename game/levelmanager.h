#pragma once

#include <QObject>

class Scene;

class LevelManager : public QObject
{
    Q_OBJECT

public:
    explicit LevelManager(QObject *parent = nullptr);
    ~LevelManager() override;

    void loadLevel(int levelNumber);
    void startGame();
    void endGame();

    Scene *currentScene() const;

signals:
    void sceneChanged();

private:
    void clearScene();

    Scene *m_currentScene = nullptr;
};
