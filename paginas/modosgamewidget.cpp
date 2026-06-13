#include "modosgamewidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>

ModosGameWidget::ModosGameWidget(QWidget *parent)
    : QWidget(parent)
{
    // --- 1. HOJA DE ESTILOS (QSS) MEJORADA ---
    setStyleSheet(R"(
        /* ModosGameWidget {
            border-image: url(:/resources/imgs/fondo_oscuro.png) 0 0 0 0 stretch stretch;
        } */

        QLabel {
            color: white;
            background: transparent;
        }

        #titleLabel {
            font-size: 28px;
            font-weight: bold;
            color: #E0E0E0;
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
            padding: 8px 15px;
            font-weight: bold;
        }

        #logoutBtn:hover {
            background-color: #d84848;
        }

        #modeButton {
            /* El borde transparente evita que el botón cambie de tamaño al hacer hover */
            border: 3px solid transparent;
            border-radius: 15px;
            background-color: rgba(255, 255, 255, 10);
        }

        #modeButton:hover {
            border: 3px solid rgb(80, 170, 255);
            background-color: rgba(255, 255, 255, 20);
        }
    )");

    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(30, 20, 30, 20);
    mainLayout->setSpacing(40);

    // --- 2. CABECERA (HEADER) ---
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
    userLayout->setSpacing(5);

    userName = new QLabel("Nombre de usuario");
    QFont userFont;
    userFont.setPointSize(15);
    userFont.setBold(true);
    userName->setFont(userFont);

    btnExit = new QPushButton("Cerrar sesión");
    btnExit->setObjectName("logoutBtn");
    btnExit->setCursor(Qt::PointingHandCursor); // Mejor UX

    userLayout->addWidget(userName);
    userLayout->addWidget(btnExit);

    headerLayout->addWidget(profileIcon);
    headerLayout->addSpacing(15);
    headerLayout->addLayout(userLayout);

    mainLayout->addLayout(headerLayout);

    // --- 3. TÍTULO PRINCIPAL ---
    QLabel *titleLabel = new QLabel("Selecciona un modo de juego");
    titleLabel->setObjectName("titleLabel");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    // --- 4. MODOS DE JUEGO (REFACTORIZADO CON DRY) ---
    auto *gamesLayout = new QHBoxLayout();
    gamesLayout->setSpacing(50);
    gamesLayout->addStretch();

    // Función Lambda para no repetir código al crear modos de juego
    auto createGameMode = [userFont](const QString& title, const QString& imagePath, QPushButton*& btnRef) {
        auto *layout = new QVBoxLayout();

        QLabel *lblModo = new QLabel(title);
        lblModo->setAlignment(Qt::AlignCenter);
        lblModo->setFont(userFont);

        btnRef = new QPushButton();
        btnRef->setObjectName("modeButton");
        btnRef->setMinimumSize(400, 400);
        btnRef->setCursor(Qt::PointingHandCursor); // Mejor UX

        // Asignar la imagen específica
        btnRef->setStyleSheet(QString("border-image: url(%1) 0 0 0 0 stretch stretch;").arg(imagePath));

        layout->addWidget(lblModo);
        layout->addSpacing(20);
        layout->addWidget(btnRef);

        return layout;
    };

    // Crear modos usando la lambda
    gamesLayout->addLayout(createGameMode("Modo juego 1", ":/imgs/preview-md-uno.png", btnJuegoUno));
    gamesLayout->addLayout(createGameMode("Modo juego 2", ":/imgs/preview-md-dos.png", btnJuegoDos));

    gamesLayout->addStretch();

    mainLayout->addStretch();
    mainLayout->addLayout(gamesLayout);
    mainLayout->addStretch();
}