#include "level2hud.h"

Level2HUD::Level2HUD()
{
    lblObjetivo = new QLabel("Objetivo: --", this);
    contenedorhud->addWidget(lblObjetivo);

    barraProgreso = new QProgressBar(this);
    barraProgreso->setRange(0, 100);
    barraProgreso->setValue(0);

    contenedorhud->addWidget(barraProgreso);
}

void Level2HUD::updateObjective(const QString &text)
{
    lblObjetivo->setText(text);
}

void Level2HUD::clearHUD()
{
    lblObjetivo->setText("Objetivo: --");
    barraProgreso->setValue(0);
}
