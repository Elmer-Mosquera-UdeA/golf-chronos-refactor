#pragma once

#include <QWidget>
#include <QGraphicsView>
#include <QStackedWidget>

class TopBarWidget;
class EventLogWidget;
class LevelManager;

class GameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GameWidget(QWidget *parent);

    void initUI();
    void changeHUD();
    void showScene(QGraphicsScene *scene);
    void startGame();
    void endGame();

private:
    TopBarWidget *topBar;
    QGraphicsView *view;
    QStackedWidget *hudStack;
    EventLogWidget *eventLog;
    LevelManager *levelManager;
};