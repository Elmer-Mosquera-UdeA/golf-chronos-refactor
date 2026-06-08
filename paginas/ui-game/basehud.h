#pragma once

#include <QWidget>

class BaseHUD : public QWidget
{
    Q_OBJECT
public:
    explicit BaseHUD(QWidget *parent = nullptr);

signals:
};
