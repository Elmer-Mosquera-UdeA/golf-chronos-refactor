#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

class TopBarWidget : public QWidget
{
    Q_OBJECT

public:
    TopBarWidget(QWidget *parent = nullptr);

    void setLevelName(const QString &name);

    QPushButton *btnVolver;
    QLabel *lblNivel;

private:
    QLabel *nombreJuego;
};
