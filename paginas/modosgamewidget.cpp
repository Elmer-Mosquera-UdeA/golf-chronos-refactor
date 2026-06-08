#include "modosgamewidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>

ModosGameWidget::ModosGameWidget(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet(R"(
        /* ModosGameWidget{
            border-image: url(:/resources/imgs/fondo_oscuro.png)
                          0 0 0 0 stretch stretch;
        } */

        QLabel {
            color: white;
            background: transparent;
        }

        #profileIcon {
            background-color: rgba(255, 255, 255, 40);
            border-radius: 35px;
            border: 1px solid rgba(255, 255, 255, 70);
        }

        #logoutBtn {
            background-color: #b53333;
            color: white;
            border-radius: 8px;
            padding: 8px;
        }

        #logoutBtn:hover {
            background-color: #d84848;
        }

        #modeButton {
            border: none;
            border-radius: 15px;
        }

        #modeButton:hover {
            border: 3px solid rgb(80, 170, 255);
        }
    )");


    // Layout principal

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 20, 30, 20);
    mainLayout->setSpacing(40);

    // Header

    auto *headerLayout = new QHBoxLayout();

    headerLayout->addStretch();

    auto *profileIcon = new QLabel("👤");
    profileIcon->setObjectName("profileIcon");
    profileIcon->setFixedSize(70, 70);
    profileIcon->setAlignment(Qt::AlignCenter);

    QFont iconFont;
    iconFont.setPointSize(24);
    profileIcon->setFont(iconFont);

    auto *userLayout = new QVBoxLayout();

    userName = new QLabel("Nombre de usuario");

    QFont userFont;
    userFont.setPointSize(15);
    userFont.setBold(true);
    userName->setFont(userFont);

    btnExit = new QPushButton("Cerrar sesión");
    btnExit->setObjectName("logoutBtn");
    btnExit->setMaximumWidth(150);

    userLayout->addWidget(userName);
    userLayout->addWidget(btnExit);

    headerLayout->addWidget(profileIcon);
    headerLayout->addSpacing(15);
    headerLayout->addLayout(userLayout);

    mainLayout->addLayout(headerLayout);

    // Modos de juego

    auto *gamesLayout = new QHBoxLayout();
    gamesLayout->setSpacing(50);

    gamesLayout->addStretch();

    // ----- Modo 1 -----

    auto *modo1Layout = new QVBoxLayout();

    QLabel *lblModo1 = new QLabel("Modo juego 1");
    lblModo1->setAlignment(Qt::AlignCenter);
    lblModo1->setFont(userFont);

    btnJuegoUno = new QPushButton();
    btnJuegoUno->setObjectName("modeButton");
    btnJuegoUno->setMinimumSize(400, 400);

    btnJuegoUno->setStyleSheet(R"(
        border-image: url(:/imgs/preview-md-uno.png) 0 0 0 0 stretch stretch;
    )");

    modo1Layout->addWidget(lblModo1);
    modo1Layout->addSpacing(20);
    modo1Layout->addWidget(btnJuegoUno);

    // ----- Modo 2 -----

    auto *modo2Layout = new QVBoxLayout();

    QLabel *lblModo2 = new QLabel("Modo juego 2");
    lblModo2->setAlignment(Qt::AlignCenter);
    lblModo2->setFont(userFont);

    btnJuegoDos = new QPushButton();
    btnJuegoDos->setObjectName("modeButton");
    btnJuegoDos->setMinimumSize(400, 400);

    btnJuegoDos->setStyleSheet(R"(
        border-image: url(:/imgs/preview-md-dos.png) 0 0 0 0 stretch stretch;
    )");

    modo2Layout->addWidget(lblModo2);
    modo2Layout->addSpacing(20);
    modo2Layout->addWidget(btnJuegoDos);

    gamesLayout->addLayout(modo1Layout);
    gamesLayout->addLayout(modo2Layout);

    gamesLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(gamesLayout);
    mainLayout->addStretch();
}