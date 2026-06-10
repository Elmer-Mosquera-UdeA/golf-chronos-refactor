#pragma once

#include <QWidget>
#include <QLabel>
#include <QString>

class EventLogWidget : public QWidget
{
    Q_OBJECT

public:
    EventLogWidget(QWidget *parent = nullptr);
    void enviarNotificacion(QString m);
    void enviarAlerta(QString m);

private:
    QLabel *mensajeCinta;
};
