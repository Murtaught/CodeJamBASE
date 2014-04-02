#ifndef CASE_HPP
#define CASE_HPP

#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QTextStream>
#include <QDebug>

class Case : public QObject, public QRunnable
{
    Q_OBJECT

public:
    // ctor & dtor
    explicit Case() : QObject(0), solved(false) { setAutoDelete(false); }

    void run()
    {
        //...Your solution code here...
        {
            rings_amount = 0;

            for (;;)
            {
                qint64 next_paint = (r + 1)*(r + 1) - r*r;
                if (next_paint > t)
                    break;

                t -= next_paint;
                ++rings_amount;

                r += 2;
            }
        }

        //QThread::msleep(10);

        solved = true;
        emit caseSolved(this);
    }

    void readInput(QTextStream &in)
    {
        //...Read input data here...
        in >> r >> t;
    }

    void writeResults(QTextStream &out)
    {
        out << "Case #" << case_number << ": ";

        //...And write your results here...
        out << rings_amount << "\n";
    }

    inline bool is_solved() const { return solved; }
    inline void setCaseNumber(int n) { case_number = n; }

signals:
    void caseSolved(Case*);

private:
    int  case_number;
    bool solved;

    // ...Your problem input here...
    qint64 r, t;
    // ...Your results here...
    int rings_amount;
};

#endif // CASE_HPP
