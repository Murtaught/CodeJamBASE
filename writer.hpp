#ifndef WRITER_HPP
#define WRITER_HPP

#include "case.hpp"
#include "casemanager.hpp"

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>

#include <QDebug>

class Writer : public QObject
{
    Q_OBJECT

public:
    explicit Writer(QString const& filename)
        : QObject( 0 ),
          file( filename ),
          next_case_idx( 0 )
    {
        bool opened = file.open(QFile::Text | QFile::WriteOnly);
        Q_ASSERT_X(opened,
                   "Writer ctor",
                   tr("Couldn't open file \"%1\"!").arg(filename).toUtf8().data()
        );

        out.setDevice( &file );
    }

signals:
    void wroteCase(Case *cs);
    void wroteAllCases();

public slots:
    void writeCase(Case *cs)
    {
        cs->writeResults(out);  
        emit wroteCase(cs);
    }

    void writeAllCases()
    {
        CaseManager *manager = CaseManager::instance();
        int amount = manager->getTotalAmountOfCases();

        for (int i = 1; i <= amount; ++i)
            writeCase( manager->getCase(i) );
        out.flush();

        qDebug() << "Successfully (?) wrote all results to " << file.fileName();
        emit wroteAllCases();
    }

private:
    QFile       file;
    QTextStream out;

    int next_case_idx;
};

#endif // WRITER_HPP
