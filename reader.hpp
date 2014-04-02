#ifndef READER_H
#define READER_H

#include "case.hpp"
#include "casemanager.hpp"

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QByteArray>

#include <QDebug>

class Reader : public QObject
{
    Q_OBJECT

public:
    explicit Reader(QString const& filename)
        : QObject( 0 ),
          file( filename )
    {
        bool opened = file.open(QFile::Text | QFile::ReadOnly);
        Q_ASSERT_X(opened,
                   "Reader ctor",
                   tr("Couldn't open file \"%1\"!").arg(filename).toUtf8().data()
        );

        in.setDevice( &file );
    }

signals:
    void readCase(Case *cs);
    void readAllCases();

public slots:
    void readInput()
    {
        qDebug() << this << ": Begin reading input file" << file.fileName();

        int case_amount;
        in >> case_amount;
        in.readLine(); // to skip to '\n' after reading case_amount

        CaseManager *manager = CaseManager::instance();
        manager->setTotalAmountOfCases(case_amount);

        for (int case_no = 1; case_no <= case_amount; ++case_no)
        {
            Case *cs = manager->getCase(case_no);

            cs->readInput( in );

            emit readCase( cs );
        }

        qDebug() << this << ": Read all cases";
        emit readAllCases();
    }

private:
    QFile       file;
    QTextStream in;

};

#endif // READER_H
