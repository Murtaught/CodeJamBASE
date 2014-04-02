#ifndef DISPATCHER_HPP
#define DISPATCHER_HPP

#include "case.hpp"
#include "casemanager.hpp"

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QThreadPool>

class Dispatcher : public QObject
{
    Q_OBJECT

public:
    Dispatcher()
        : QObject(0)
    {
    }

public slots:
    void dispatchCase(Case *cs)
    {
        //qDebug() << "Dispatching" << cs << "now";

        // Maybe in the future this class will do
        // something more intellectual than
        // invoking a QThreadPool method

        // Multi-thread mode
        QThreadPool::globalInstance()->start( cs );

        // Single-thread mode
        //cs->run();
    }

};

#endif // DISPATCHER_HPP
