#include "gestorbasedatos.h"
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>


GestorBaseDatos::GestorBaseDatos() = default;

bool GestorBaseDatos::conectarBD() {
    // Si ya existe la conexión, no hacemos nada duplicate
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        return true;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    QString rutaCarpeta = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(rutaCarpeta);
    QString rutaDb = rutaCarpeta + "/cronos_data.sqlite";
    db.setDatabaseName(rutaDb);

    if (!db.open()) {
        qDebug() << "Error crítico: No se pudo conectar a la BD:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("PRAGMA foreign_keys = ON;");

    qDebug() << "Conexión a SQLite exitosa en:" << rutaDb;
    return inicializarTablas();
}

bool GestorBaseDatos::inicializarTablas() {
    QSqlQuery query;

    QString sqlJugador = R"(
        CREATE TABLE IF NOT EXISTS Jugador(
            id_jugador TEXT PRIMARY KEY,
            pin_secreto TEXT NOT NULL,
            vidas INTEGER DEFAULT 5,
            puntuacion_total INTEGER DEFAULT 0
        );
    )";

    QString sqlModoUno = R"(
        CREATE TABLE IF NOT EXISTS ProgresoModoUno(
            id_jugador TEXT,
            id_nivel INTEGER,
            golpes INTEGER DEFAULT 0,
            tiempo_segundos INTEGER DEFAULT 0,
            completado INTEGER DEFAULT 0,

            PRIMARY KEY(id_jugador, id_nivel),

            FOREIGN KEY(id_jugador)
            REFERENCES Jugador(id_jugador)
            ON DELETE CASCADE
        );
    )";

    QString sqlModoDos = R"(
        CREATE TABLE IF NOT EXISTS ProgresoModoDos(
            id_jugador TEXT,
            id_nivel INTEGER,
            documentos_recogidos INTEGER DEFAULT 0,
            tiempo_segundos INTEGER DEFAULT 0,
            completado INTEGER DEFAULT 0,

            PRIMARY KEY(id_jugador, id_nivel),

            FOREIGN KEY(id_jugador)
            REFERENCES Jugador(id_jugador)
            ON DELETE CASCADE
        );
    )";


    if (!query.exec(sqlJugador)) {
        qDebug() << "Error creando tabla Jugador:" << query.lastError().text();
        return false;
    }

    if (!query.exec(sqlModoUno)) {
        qDebug() << "Error creando tabla Jugador:" << query.lastError().text();
        return false;
    }

    if (!query.exec(sqlModoDos)) {
        qDebug() << "Error creando tabla Jugador:" << query.lastError().text();
        return false;
    }

    return true;
}


ResultadoAuth GestorBaseDatos::registrarJugador(
    const QString &idJugador,
    const QString &pin)
{
    ResultadoAuth r;

    if (idJugador.isEmpty() || pin.isEmpty()) {
        r.mensaje = "No se pueden dejar campos vacíos.";
        r.tipo = TipoRespuesta::Validacion;
        return r;
    }

    if (existeJugador(idJugador)) {
        r.mensaje = "El jugador ya existe.";
        r.tipo = TipoRespuesta::Validacion;
        return r;
    }

    QSqlQuery query;

    query.prepare(
        "INSERT INTO Jugador(id_jugador, pin_secreto) "
        "VALUES(:id, :pin)"
        );

    query.bindValue(":id", idJugador);
    query.bindValue(":pin", pin);

    if (!query.exec()) {
        r.mensaje = query.lastError().text();
        r.tipo = TipoRespuesta::BaseDatos;
        return r;
    }

    m_jugadorActivo = idJugador;

    r.exito = true;
    r.tipo = TipoRespuesta::Ok;
    r.mensaje = "Jugador registrado correctamente.";
    r.jugador = idJugador;

    return r;
}

ResultadoAuth GestorBaseDatos::login(
    const QString &idJugador,
    const QString &pin)
{
    ResultadoAuth r;

    if (idJugador.isEmpty() || pin.isEmpty()) {
        r.mensaje = "No se pueden dejar campos vacíos.";
        r.tipo = TipoRespuesta::Validacion;
        return r;
    }

    if (!existeJugador(idJugador)) {
        r.mensaje = "El jugador no existe.";
        r.tipo = TipoRespuesta::Validacion;
        return r;
    }

    if (!validarCredenciales(idJugador, pin)) {
        r.mensaje = "PIN incorrecto.";
        r.tipo = TipoRespuesta::Validacion;
        return r;
    }

    m_jugadorActivo = idJugador;

    r.exito = true;
    r.tipo = TipoRespuesta::Ok;
    r.mensaje = "Acceso concedido.";
    r.jugador = idJugador;

    return r;
}

ResultadoAuth GestorBaseDatos::cerrarSesion()
{
    ResultadoAuth r;

    m_jugadorActivo.clear();

    r.exito = true;
    r.mensaje = "Sesión cerrada.";
    r.jugador = "";

    return r;
}

bool GestorBaseDatos::existeJugador(const QString &idJugador)
{
    QSqlQuery query;

    query.prepare(
        "SELECT 1 "
        "FROM Jugador "
        "WHERE id_jugador = :id"
        );

    query.bindValue(":id", idJugador);

    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }

    return query.next();
}

bool GestorBaseDatos::validarCredenciales(
    const QString &idJugador,
    const QString &pin)
{
    QSqlQuery query;

    query.prepare(
        "SELECT 1 "
        "FROM Jugador "
        "WHERE id_jugador = :id "
        "AND pin_secreto = :pin"
        );

    query.bindValue(":id", idJugador);
    query.bindValue(":pin", pin);

    if (!query.exec()) {
        qDebug() << query.lastError().text();
        return false;
    }

    return query.next();
}




QString GestorBaseDatos::obtenerJugadorActivo() const
{
    return m_jugadorActivo;
}

bool GestorBaseDatos::haySesionActiva()
{
    return !m_jugadorActivo.isEmpty();
}

