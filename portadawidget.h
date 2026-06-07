#pragma once

#include <QWidget>

class QPushButton;

class PortadaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PortadaWidget(QWidget *parent = nullptr);

    QPushButton *btnLogin;
    QPushButton *btnRegistro;
};