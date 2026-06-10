#include "topbarwidget.h"

#include <QHBoxLayout>
#include <QFont>

TopBarWidget::TopBarWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(60);

    auto *layout = new QHBoxLayout(this);
    layout->setContentsMargins(16, 8, 16, 8);
    layout->setSpacing(12);

    btnVolver = new QPushButton(QStringLiteral("← Volver"), this);
    btnVolver->setCursor(Qt::PointingHandCursor);
    btnVolver->setFixedWidth(110);

    nombreJuego = new QLabel(
        QStringLiteral("Chronos: Fragmentos del Tiempo"), this);

    QFont tituloFont;
    tituloFont.setPointSize(14);
    tituloFont.setBold(true);

    nombreJuego->setFont(tituloFont);
    nombreJuego->setAlignment(Qt::AlignCenter);

    lblNivel = new QLabel(QStringLiteral("Nivel: --"), this);
    lblNivel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    QFont nivelFont;
    nivelFont.setPointSize(11);

    lblNivel->setFont(nivelFont);

    layout->addWidget(btnVolver);
    layout->addStretch();

    layout->addWidget(nombreJuego);

    layout->addStretch();
    layout->addWidget(lblNivel);

    setStyleSheet(R"(
        TopBarWidget {
            background-color: #222831;
            border-bottom: 1px solid #393E46;
        }

        QPushButton {
            background-color: #00ADB5;
            color: white;
            border: none;
            border-radius: 6px;
            padding: 6px 12px;
            font-weight: bold;
        }

        QPushButton:hover {
            background-color: #00C5CF;
        }

        QLabel {
            color: white;
        }
    )");
}

void TopBarWidget::setLevelName(const QString &name)
{
    lblNivel->setText(QStringLiteral("Nivel: %1").arg(name));
}