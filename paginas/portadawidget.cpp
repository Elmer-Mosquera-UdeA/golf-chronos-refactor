#include "portadawidget.h"

#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include <QPixmap>
#include <QFont>

PortadaWidget::PortadaWidget(QWidget *parent)
    : QWidget(parent)
{

    setStyleSheet(R"(

        PortadaWidget{
            border-image: url(:/resources/imgs/fondo_oscuro.png)
                          0 0 0 0 stretch stretch;
        }

        QLabel{
            color: white;
            background: transparent;
        }

        QPushButton{
            min-height: 45px;
            border: none;
            border-radius: 10px;
            font-size: 15px;
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
    card->setMaximumWidth(450);

    card->setStyleSheet(R"(
        background: rgba(15,15,15,180);
        border-radius: 20px;
    )");

    auto *cardLayout = new QVBoxLayout(card);

    cardLayout->setContentsMargins(35, 35, 35, 35);
    cardLayout->setSpacing(18);

    // Logo

    QLabel *logo = new QLabel;

    logo->setPixmap(
        QPixmap(":/imgs/logo-lema.png")
            .scaled(
                260,
                160,
                Qt::KeepAspectRatio,
                Qt::SmoothTransformation
                )
        );

    logo->setAlignment(Qt::AlignCenter);

    // Título

    QLabel *titulo = new QLabel("MI JUEGO");

    QFont titleFont;
    titleFont.setPointSize(24);
    titleFont.setBold(true);

    titulo->setFont(titleFont);
    titulo->setAlignment(Qt::AlignCenter);

    // Subtítulo

    QLabel *subtitulo =
        new QLabel("Selecciona una opción para continuar");

    subtitulo->setAlignment(Qt::AlignCenter);
    subtitulo->setWordWrap(true);

    // Botones

    btnLogin = new QPushButton("Iniciar sesión");
    btnRegistro = new QPushButton("Registrarse");

    btnLogin->setStyleSheet(R"(
        background: rgb(35,120,220);
        color: white;
    )");

    btnRegistro->setStyleSheet(R"(
        background: rgb(70,70,70);
        color: white;
    )");


    cardLayout->addWidget(logo);

    cardLayout->addSpacing(10);

    cardLayout->addWidget(titulo);
    cardLayout->addWidget(subtitulo);

    cardLayout->addSpacing(25);

    cardLayout->addWidget(btnLogin);
    cardLayout->addWidget(btnRegistro);

    mainLayout->addWidget(card, 0, Qt::AlignCenter);
    mainLayout->addStretch();
}