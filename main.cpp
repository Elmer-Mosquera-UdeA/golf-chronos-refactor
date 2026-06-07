#include "mainwindow.h"
#include <QIcon>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setWindowIcon(QIcon(":/imgs/lab.ico"));

    MainWindow w;
    w.show();
    return QApplication::exec();
}
