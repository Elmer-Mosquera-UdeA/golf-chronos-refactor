#ifndef MODOSGAMEWIDGET_H
#define MODOSGAMEWIDGET_H

#include <QWidget>
#include <QLabel>

class QPushButton;

class ModosGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ModosGameWidget(QWidget *parent = nullptr);

    QLabel *userName;

    QPushButton *btnExit;
    QPushButton *btnJuegoUno;
    QPushButton *btnJuegoDos;

private:
};

#endif