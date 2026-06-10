#include "gamewidget.h"

#include <QVBoxLayout>

#include "ui-game/topbarwidget.h"
#include "ui-game/eventlogwidget.h"
#include "ui-game/basehud.h"
#include "ui-game/level1hud.h"
#include "ui-game/level2hud.h"
#include "../game/levelmanager.h"
#include "../game/scene.h"


GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    levelManager = new LevelManager(this);

    topBar = new TopBarWidget(this);
    view = new QGraphicsView(this);
    hudStack = new QStackedWidget(this);
    eventLog = new EventLogWidget(this);

    layout = new QVBoxLayout(this);
    subLayout = new QHBoxLayout();

    initUI();

    connect(levelManager, &LevelManager::sceneChanged,
            this, &GameWidget::showScene);
}

void GameWidget::initUI()
{
    layout->addWidget(topBar, 1);

    subLayout->addWidget(view, 9);
    subLayout->addWidget(hudStack, 1);

    layout->addLayout(subLayout, 8);

    layout->addWidget(eventLog, 1);
}

void GameWidget::changeHUD(BaseHUD *hud)
{
    if (hudStack->count() > 0) {
        QWidget *old = hudStack->widget(0);
        hudStack->removeWidget(old);
        old->deleteLater();
    }

    if (hud) {
        hudStack->addWidget(hud);
    }
}

void GameWidget::showScene()
{
    view->setScene(levelManager->currentScene());
}

void GameWidget::loadLevel(int levelNumber)
{
    levelManager->loadLevel(levelNumber);

    BaseHUD *hud = nullptr;
    topBar->setLevelName(QString::number(levelNumber));

    if (levelNumber == 1) {
        hud = new Level1HUD();
    } else if (levelNumber == 2) {
        hud = new Level2HUD();
    }

    changeHUD(hud);
}

void GameWidget::startGame()
{
    levelManager->startGame();
}

void GameWidget::endGame()
{
    levelManager->endGame();
}
