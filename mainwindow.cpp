#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStackedWidget>

// Alertas
#include <QMessageBox>
#include <QPushButton>

//subVistas
#include "paginas/portadawidget.h"
#include "paginas/authwidget.h"
#include "paginas/modosgamewidget.h"
#include "paginas/gamewidget.h"
#include "paginas/ui-game/topbarwidget.h"

// Base Datos
#include "persistencia/gestorbasedatos.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setMinimumSize(1000, 800);
    resize(1200, 900);

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

    GameWidget *contenedorJuego = new GameWidget(this);

    vistaActual->addWidget(portada);
    vistaActual->addWidget(login);
    vistaActual->addWidget(registro);
    vistaActual->addWidget(modosJuego);
    vistaActual->addWidget(contenedorJuego);


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
        [=,this]()
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

    // Jugar modo 1

    connect(modosJuego->btnJuegoUno,&QPushButton::clicked,this,
        [=, this]()
            {
                contenedorJuego->loadLevel(1);
                vistaActual->setCurrentIndex(page(Pagina::GameWidget));
                juegoActivo = true;
            });


    // Jugar modo 2

    connect(modosJuego->btnJuegoDos,&QPushButton::clicked,this,
            [=, this]()
            {
                contenedorJuego->loadLevel(2);
                vistaActual->setCurrentIndex(page(Pagina::GameWidget));
                juegoActivo = true;
            });

    // Volver desde el juego al menú de modos

    connect(contenedorJuego->topBar->btnVolver, &QPushButton::clicked, this,
            [=, this]()
            {
                contenedorJuego->endGame();
                vistaActual->setCurrentIndex(page(Pagina::ModosJuego));
            });

    // Limpieza automática al salir de GameWidget por cualquier ruta

    connect(vistaActual, &QStackedWidget::currentChanged, this,
            [=, this](int index)
            {
                if (vistaActual->widget(index) != contenedorJuego && juegoActivo) {
                    contenedorJuego->endGame();
                    juegoActivo = false;
                }
            });

}

MainWindow::~MainWindow()
{
    delete ui;
}
