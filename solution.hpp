#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <QTextStream>
#include <QDebug>

struct Solution
{
    void input(QTextStream &in)
    {
        Q_UNUSED(in)
    }

    void solve()
    {
        ans = a;
        for (int i = 0; i < 10e7; i++)
            ans += i;
    }

    void output(QTextStream &out)
    {
        out << ans << "\n";
    }

protected:
    // input:
    int a;

    // results:
    long long ans;
};

#endif // SOLUTION_HPP
