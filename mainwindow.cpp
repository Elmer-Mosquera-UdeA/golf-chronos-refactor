#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>

// Alertas
#include <QMessageBox>

//subvistas
#include "portadawidget.h"
#include "authwidget.h"
#include <QPushButton>
#include "modosgamewidget.h"

#include "gestorbasedatos.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (!gestorBD.conectarBD()) {
        QMessageBox::critical(this,"Error","No fue posible inicializar la base de datos.");
    }

    QStackedWidget *vistaActual = ui->stackedWidget;

    PortadaWidget *portada = new PortadaWidget(this);

    AuthWidget *login = new AuthWidget("INICIAR SESIÓN",this);
    login->btnContinuar->setText("Iniciar");

    AuthWidget *registro = new AuthWidget("REGISTRARSE", this);
    registro->btnContinuar->setText("Registrarse");

    ModosGameWidget *modosJuego = new ModosGameWidget(this);


    vistaActual->addWidget(portada);
    vistaActual->addWidget(login);
    vistaActual->addWidget(registro);
    vistaActual->addWidget(modosJuego);


    // Portada -> Login
    connect(portada->btnLogin,&QPushButton::clicked,this,[=, this](){vistaActual->setCurrentIndex(page(Pagina::Login));});

    // Portada -> Registro
    connect(portada->btnRegistro,&QPushButton::clicked,this,[=, this](){vistaActual->setCurrentIndex(page(Pagina::Registro));});

    // Login -> Portada
    connect(login->btnAtras,&QPushButton::clicked,this,[=, this](){vistaActual->setCurrentIndex(page(Pagina::Portada));});

    // Registro -> Portada
    connect(registro->btnAtras,&QPushButton::clicked,this,[=, this](){vistaActual->setCurrentIndex(page(Pagina::Portada));});

    // Login -> Modos de juego
    connect(login->btnContinuar,&QPushButton::clicked,this,
        [=, this]()
            {
                ResultadoAuth res = gestorBD.login(
                    login->usuario(),
                    login->pin()
                    );

                if (!res.exito) {

                    QMessageBox::warning(
                        this,
                        "Iniciar sesión",
                        res.mensaje
                        );

                    return;
                }

                modosJuego->userName->setText(res.jugador);

                vistaActual->setCurrentIndex(
                    page(Pagina::ModosJuego)
                    );
            });

    // Registro -> Modos de juego
    connect(registro->btnContinuar, &QPushButton::clicked, this,
            [=, this]()
            {
                ResultadoAuth res = gestorBD.registrarJugador(
                    registro->usuario(),
                    registro->pin()
                    );

                if (!res.exito) {

                    QMessageBox::warning(
                        this,
                        "Registro",
                        res.mensaje
                        );

                    return;
                }

                QMessageBox::information(
                    this,
                    "Registro",
                    "¡Jugador registrado correctamente!"
                    );

                modosJuego->userName->setText(res.jugador);

                vistaActual->setCurrentIndex(
                    page(Pagina::ModosJuego)
                    );
            });

    // Modos -> Portada
    connect(modosJuego->btnExit,&QPushButton::clicked,this,
            [=, this]()
            {
                gestorBD.cerrarSesion();

                vistaActual->setCurrentIndex(
                    page(Pagina::Portada)
                    );
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}
