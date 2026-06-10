#pragma once

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit Scene(QObject *parent = nullptr);
    virtual ~Scene() = default;

    virtual void initialize() = 0;
    virtual void update() = 0;
};
