#pragma once

#include <QWidget>

class QLabel;
class QLineEdit;
class QPushButton;

class AuthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthWidget(const QString& titulo, QWidget *parent = nullptr);

    QString usuario() const;
    QString pin() const;

    QPushButton* btnAtras;
    QPushButton* btnContinuar;

private:

    QLabel *lblTitulo;

    QLineEdit *txtUsuario;
    QLineEdit *txtPin;
};