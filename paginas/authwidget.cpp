#include "authwidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <QFont>

AuthWidget::AuthWidget(const QString &titulo, QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet(R"(

        /* AuthWidget{
             border-image: url(:/resources/imgs/fondo_oscuro.png)
                           0 0 0 0 stretch stretch;
        } */

        QLabel{
            color: white;
            background: transparent;
        }

        QLineEdit{
            min-height: 42px;
            padding-left: 12px;

            background: rgba(20,20,20,180);

            color: white;

            border: 2px solid rgba(255,255,255,40);
            border-radius: 10px;

            font-size: 14px;
        }

        QLineEdit:focus{
            border: 2px solid rgb(70,170,255);
        }

        QPushButton{
            min-height: 42px;

            border: none;
            border-radius: 10px;

            font-weight: bold;
        }

        QPushButton:hover{
            border: 2px solid rgb(70,170,255);
        }

    )");

    // Layout principal

    auto *mainLayout = new QVBoxLayout(this);

    mainLayout->addStretch();

    // Tarjeta central

    QWidget *card = new QWidget;

    card->setMaximumWidth(420);

    card->setStyleSheet(R"(
        background: rgba(15,15,15,180);
        border-radius: 18px;
    )");

    auto *cardLayout = new QVBoxLayout(card);

    cardLayout->setContentsMargins(35,35,35,35);
    cardLayout->setSpacing(15);

    // Logo

    QLabel *logo = new QLabel;

    logo->setPixmap(
        QPixmap(":/imgs/logo-lema.png")
            .scaled(
                220,
                120,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
                )
        );

    logo->setAlignment(Qt::AlignCenter);

    // Título

    lblTitulo = new QLabel(titulo);

    QFont titleFont;
    titleFont.setPointSize(22);
    titleFont.setBold(true);

    lblTitulo->setFont(titleFont);
    lblTitulo->setAlignment(Qt::AlignCenter);

    // Usuario

    QLabel *lblUser = new QLabel("Usuario");

    txtUsuario = new QLineEdit;
    txtUsuario->setPlaceholderText("Ingrese su usuario");

    // PIN

    QLabel *lblPin = new QLabel("PIN");

    txtPin = new QLineEdit;
    txtPin->setPlaceholderText("Ingrese su PIN");
    txtPin->setEchoMode(QLineEdit::Password);

    // Botones

    auto *buttons = new QHBoxLayout();

    btnAtras = new QPushButton("Atrás");
    btnContinuar = new QPushButton("Continuar");

    btnAtras->setStyleSheet(R"(
        background: rgb(90,90,90);
        color: white;
    )");

    btnContinuar->setStyleSheet(R"(
        background: rgb(35,120,220);
        color: white;
    )");

    buttons->addWidget(btnAtras);
    buttons->addWidget(btnContinuar);


    cardLayout->addWidget(logo);
    cardLayout->addSpacing(10);

    cardLayout->addWidget(lblTitulo);

    cardLayout->addSpacing(20);

    cardLayout->addWidget(lblUser);
    cardLayout->addWidget(txtUsuario);

    cardLayout->addWidget(lblPin);
    cardLayout->addWidget(txtPin);

    cardLayout->addSpacing(20);

    cardLayout->addLayout(buttons);


    mainLayout->addWidget(card, 0, Qt::AlignCenter);
    mainLayout->addStretch();
}

QString AuthWidget::usuario() const
{
    return txtUsuario->text();
}

QString AuthWidget::pin() const
{
    return txtPin->text();
}