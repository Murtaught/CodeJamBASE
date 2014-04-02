#ifndef CASE_HPP
#define CASE_HPP

#include "solution.hpp"

#include <QObject>
#include <QRunnable>
#include <QThread>
#include <QTextStream>
#include <QDebug>

class Case : public QObject, public QRunnable, public Solution
{
    Q_OBJECT
    //friend class CaseManager;

public:
    // ctor & dtor
    explicit Case() : QObject(0), solved(false) { setAutoDelete(false); }

    void run()
    {
        Solution::solve();

        solved = true;
        emit caseSolved(this);
    }

    void readInput(QTextStream &in)
    {
        // IRL solution can't depend on case number
        // This is just an example, quite stupid one
        a = case_number - 1;

        Solution::input(in);
    }

    void writeResults(QTextStream &out)
    {
        out << "Case #" << case_number << ": ";
        Solution::output(out);
    }

    inline bool is_solved() const { return solved; }
    inline void setCaseNumber(int n) { case_number = n; }

signals:
    void caseSolved(Case*);

private:
    int  case_number;
    bool solved;
};

#endif // CASE_HPP
