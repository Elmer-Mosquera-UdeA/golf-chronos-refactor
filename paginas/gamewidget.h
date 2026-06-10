#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QStackedWidget>

#include <QPushButton>
#include <QLabel>

class TopBarWidget;
class EventLogWidget;
class LevelManager;
class BaseHUD;
class Scene;

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent);

    void initUI();
    void loadLevel(int levelNumber);
    void changeHUD(BaseHUD *hud);
    void showScene();
    void startGame();
    void endGame();

    QVBoxLayout *layout;
    QHBoxLayout *subLayout;
    TopBarWidget *topBar;

private:
    QGraphicsView *view;
    QStackedWidget *hudStack;
    QWidget *eventLog;
    LevelManager *levelManager;
};
