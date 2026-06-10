#pragma once

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>


class BaseHUD : public QWidget
{
    Q_OBJECT

public:
    explicit BaseHUD(QWidget *parent = nullptr);
    void setPerfil(const QString &n);

    virtual void updateObjective(const QString &text) = 0;
    virtual void clearHUD() = 0;

    QVBoxLayout *contenedorhud;

private:
    QLabel *perfil;
    QLabel *nombre;
};
