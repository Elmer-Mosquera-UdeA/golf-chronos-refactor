#ifndef GESTORBASEDATOS_H
#define GESTORBASEDATOS_H

#include <QString>

enum class TipoRespuesta
{
    Ok,
    Validacion,
    BaseDatos
};

struct ResultadoAuth
{
    bool exito = false;
    TipoRespuesta tipo = TipoRespuesta::Validacion;
    QString mensaje = "";
    QString jugador = "";
};


class GestorBaseDatos
{
public:
    explicit GestorBaseDatos();

    bool conectarBD();

    bool inicializarTablas();

    ResultadoAuth registrarJugador(const QString &idJugador,const QString &pin);

    ResultadoAuth login(const QString &idJugador,const QString &pin);

    ResultadoAuth cerrarSesion();

    QString obtenerJugadorActivo() const;

    bool haySesionActiva();

private:
    QString m_jugadorActivo;

    bool existeJugador(const QString &idJugador);
    bool validarCredenciales(const QString &idJugador,const QString &pin);
};

#endif // GESTORBASEDATOS_H
