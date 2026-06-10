#pragma once

#include "basehud.h"
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QTimer>

class Level1HUD : public BaseHUD
{
    Q_OBJECT

public:
    Level1HUD();

    void updateObjective(const QString &text) override;
    void clearHUD() override;

    void actualizarTransicion(const QString &estadoActual, const QString &siguienteEstado);
    void iniciarEnfriamiento(int segundos);
    void detenerEnfriamiento();
    void iniciarCuentaRegresiva(int segundos);
    void detenerCuentaRegresiva();

signals:
    void invocarHabilidadMarkov();
    void enfriamientoCompletado();
    void tiempoAgotado();

private slots:
    void onTickEnfriamiento();
    void onTickCuentaRegresiva();

private:
    QFrame *cardInvocarHabilidad;
    QFrame *cardTablaEstados;
    QFrame *cardRelojEnfriamiento;
    QFrame *cardRelojSobrevivir;

    QLabel *lblObjetivo;
    QLabel *lblEstadoHabilidad;
    QLabel *lblEstadoActual;
    QLabel *lblSiguienteEstado;
    QLabel *lblEnfriamiento;
    QLabel *lblCuentaRegresiva;

    QPushButton *btnInvocar;

    QTimer *timerEnfriamiento;
    int segundosRestantesEnfriamiento;

    QTimer *timerCuentaRegresiva;
    int segundosRestantesCuenta;

    void aplicarEstilos();
};
