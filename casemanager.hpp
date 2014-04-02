#ifndef CASEMANAGER_HPP
#define CASEMANAGER_HPP

#include "case.hpp"
#include <QObject>

class CaseManager : public QObject
{
    Q_OBJECT

public:
    static CaseManager* instance();
    void setTotalAmountOfCases(int amount);

    Case* getCase(int case_number);
    int getTotalAmountOfCases() const;

signals:
    void allCasesAreSolved();

public slots:
    void caseSolved(Case *cs);
    void releasePool();

private:
    CaseManager();
    static CaseManager *instance_;

    int total_amount;
    int solved_amount;
    int next_printing_idx;

    Case *case_pool;
};

#endif // CASEMANAGER_HPP
