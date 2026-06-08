#pragma once


#include <QMainWindow>

//Base de datos
#include "persistencia/gestorbasedatos.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;

    GestorBaseDatos gestorBD;

    enum class Pagina
    {
        Portada = 0,
        Login,
        Registro,
        ModosJuego,
        GameWidget
    };

    constexpr int page(Pagina p) const
    {
        return static_cast<int>(p);
    }
};
