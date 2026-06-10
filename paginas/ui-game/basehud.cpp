#include "basehud.h"

BaseHUD::BaseHUD(QWidget *parent) : QWidget{parent}
{
    setStyleSheet(R"(
        QLabel {
            color: white;
            background: transparent;
        }

        #profileIcon {
            background-color: rgba(255, 255, 255, 40);
            border-radius: 35px;
            border: 1px solid rgba(255, 255, 255, 70);
        }
    )");

    contenedorhud = new QVBoxLayout(this);

    QHBoxLayout *headerLayout = new QHBoxLayout();

    perfil = new QLabel(QStringLiteral("\U0001F464"), this);
    perfil->setObjectName("profileIcon");
    perfil->setFixedSize(70, 70);
    perfil->setAlignment(Qt::AlignCenter);

    QFont iconFont;
    iconFont.setPointSize(24);
    perfil->setFont(iconFont);

    nombre = new QLabel("Invitado", this);
    QFont nameFont;
    nameFont.setPointSize(13);
    nameFont.setBold(true);
    nombre->setFont(nameFont);

    headerLayout->addWidget(perfil);
    headerLayout->addSpacing(10);
    headerLayout->addWidget(nombre, 1);

    contenedorhud->addLayout(headerLayout);
}

void BaseHUD::setPerfil(const QString &n)
{
    nombre->setText(n);
}
