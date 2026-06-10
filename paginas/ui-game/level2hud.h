#pragma once

#include "basehud.h"
#include <QProgressBar>
#include <QLabel>

class Level2HUD : public BaseHUD
{
    Q_OBJECT

public:
    Level2HUD();

    void updateObjective(const QString &text) override;
    void clearHUD() override;

private:
    QProgressBar *barraProgreso;
    QLabel *lblObjetivo;
};
