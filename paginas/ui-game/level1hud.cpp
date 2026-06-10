#include "level1hud.h"

Level1HUD::Level1HUD()
{
    lblObjetivo = new QLabel("Objetivo: --", this);
    contenedorhud->addWidget(lblObjetivo);

    // --- cardInvocarHabilidad ---

    cardInvocarHabilidad = new QFrame(this);
    cardInvocarHabilidad->setFrameStyle(QFrame::StyledPanel);
    QVBoxLayout *layInv = new QVBoxLayout(cardInvocarHabilidad);

    lblEstadoHabilidad = new QLabel("Estado: --", cardInvocarHabilidad);
    btnInvocar = new QPushButton("Invocar habilidad", cardInvocarHabilidad);

    layInv->addWidget(lblEstadoHabilidad);
    layInv->addWidget(btnInvocar);

    connect(btnInvocar, &QPushButton::clicked, this, &Level1HUD::invocarHabilidadMarkov);

    // --- cardTablaEstados ---

    cardTablaEstados = new QFrame(this);
    cardTablaEstados->setFrameStyle(QFrame::StyledPanel);
    QVBoxLayout *layTab = new QVBoxLayout(cardTablaEstados);

    lblEstadoActual = new QLabel("Actual: --", cardTablaEstados);
    lblSiguienteEstado = new QLabel("Siguiente: --", cardTablaEstados);

    layTab->addWidget(lblEstadoActual);
    layTab->addWidget(lblSiguienteEstado);

    // --- cardRelojEnfriamiento ---

    cardRelojEnfriamiento = new QFrame(this);
    cardRelojEnfriamiento->setFrameStyle(QFrame::StyledPanel);
    QVBoxLayout *layEnf = new QVBoxLayout(cardRelojEnfriamiento);

    lblEnfriamiento = new QLabel("Enfriamiento: --", cardRelojEnfriamiento);

    layEnf->addWidget(lblEnfriamiento);

    timerEnfriamiento = new QTimer(this);
    timerEnfriamiento->setInterval(1000);
    connect(timerEnfriamiento, &QTimer::timeout, this, &Level1HUD::onTickEnfriamiento);

    // --- cardRelojSobrevivir ---

    cardRelojSobrevivir = new QFrame(this);
    cardRelojSobrevivir->setFrameStyle(QFrame::StyledPanel);
    QVBoxLayout *layCue = new QVBoxLayout(cardRelojSobrevivir);

    lblCuentaRegresiva = new QLabel("Tiempo restante: --", cardRelojSobrevivir);

    layCue->addWidget(lblCuentaRegresiva);

    timerCuentaRegresiva = new QTimer(this);
    timerCuentaRegresiva->setInterval(1000);
    connect(timerCuentaRegresiva, &QTimer::timeout, this, &Level1HUD::onTickCuentaRegresiva);

    // --- agregar cards al hud ---

    contenedorhud->addWidget(cardInvocarHabilidad);
    contenedorhud->addWidget(cardTablaEstados);
    contenedorhud->addWidget(cardRelojEnfriamiento);
    contenedorhud->addWidget(cardRelojSobrevivir);
    contenedorhud->addStretch();

    aplicarEstilos();
}

void Level1HUD::updateObjective(const QString &text)
{
    lblObjetivo->setText(text);
}

void Level1HUD::clearHUD()
{
    lblObjetivo->setText("Objetivo: --");
    lblEstadoHabilidad->setText("Estado: --");
    lblEstadoActual->setText("Actual: --");
    lblSiguienteEstado->setText("Siguiente: --");
    lblEnfriamiento->setText("Enfriamiento: --");
    lblCuentaRegresiva->setText("Tiempo restante: --");

    detenerEnfriamiento();
    detenerCuentaRegresiva();
}

void Level1HUD::actualizarTransicion(const QString &estadoActual, const QString &siguienteEstado)
{
    lblEstadoActual->setText(QString("Actual: %1").arg(estadoActual));
    lblSiguienteEstado->setText(QString("Siguiente: %1").arg(siguienteEstado));
}

void Level1HUD::iniciarEnfriamiento(int segundos)
{
    segundosRestantesEnfriamiento = segundos;
    lblEnfriamiento->setText(QString("Enfriamiento: %1s").arg(segundos));
    timerEnfriamiento->start();
}

void Level1HUD::detenerEnfriamiento()
{
    timerEnfriamiento->stop();
    lblEnfriamiento->setText("Enfriamiento: --");
}

void Level1HUD::iniciarCuentaRegresiva(int segundos)
{
    segundosRestantesCuenta = segundos;
    lblCuentaRegresiva->setText(QString("Tiempo restante: %1s").arg(segundos));
    timerCuentaRegresiva->start();
}

void Level1HUD::detenerCuentaRegresiva()
{
    timerCuentaRegresiva->stop();
    lblCuentaRegresiva->setText("Tiempo restante: --");
}

void Level1HUD::onTickEnfriamiento()
{
    segundosRestantesEnfriamiento--;
    lblEnfriamiento->setText(QString("Enfriamiento: %1s").arg(segundosRestantesEnfriamiento));

    if (segundosRestantesEnfriamiento <= 0) {
        detenerEnfriamiento();
        emit enfriamientoCompletado();
    }
}

void Level1HUD::onTickCuentaRegresiva()
{
    segundosRestantesCuenta--;
    lblCuentaRegresiva->setText(QString("Tiempo restante: %1s").arg(segundosRestantesCuenta));

    if (segundosRestantesCuenta <= 0) {
        detenerCuentaRegresiva();
        emit tiempoAgotado();
    }
}

void Level1HUD::aplicarEstilos()
{
    cardInvocarHabilidad->setObjectName("cardHabilidad");
    cardTablaEstados->setObjectName("cardMarkov");
    cardRelojEnfriamiento->setObjectName("cardEnfriamiento");
    cardRelojSobrevivir->setObjectName("cardTiempo");

    lblObjetivo->setObjectName("lblObjetivo");
    lblEnfriamiento->setObjectName("lblEnfriamiento");
    lblCuentaRegresiva->setObjectName("lblCuentaRegresiva");

    lblObjetivo->setWordWrap(true);

    lblEnfriamiento->setAlignment(Qt::AlignCenter);
    lblCuentaRegresiva->setAlignment(Qt::AlignCenter);

    cardInvocarHabilidad->setMinimumHeight(140);
    cardTablaEstados->setMinimumHeight(120);
    cardRelojEnfriamiento->setMinimumHeight(100);
    cardRelojSobrevivir->setMinimumHeight(110);

    setStyleSheet(R"(

    QFrame {
        background-color: #2A313C;
        border: 1px solid #3A4452;
        border-radius: 12px;
    }

    #cardHabilidad {
        border-left: 4px solid #00D1B2;
    }

    #cardMarkov {
        border-left: 4px solid #4D96FF;
    }

    #cardEnfriamiento {
        border-left: 4px solid #FF6B6B;
    }

    #cardTiempo {
        border-left: 4px solid #FFD93D;
    }

    QLabel {
        color: #E8EDF2;
        font-size: 13px;
    }

    #lblObjetivo {
        background-color: #243447;
        border: 1px solid #355070;
        border-radius: 10px;
        padding: 12px;
        font-size: 14px;
        font-weight: bold;
    }

    #lblEnfriamiento {
        font-size: 22px;
        font-weight: bold;
        color: #FF6B6B;
    }

    #lblCuentaRegresiva {
        font-size: 26px;
        font-weight: bold;
        color: #FFD93D;
    }

    QPushButton {
        background-color: #00D1B2;
        color: #111827;
        border: none;
        border-radius: 8px;
        padding: 8px;
        font-weight: bold;
    }

    QPushButton:hover {
        background-color: #14E6C6;
    }

    QPushButton:pressed {
        background-color: #00B89D;
    }

    )");
}
