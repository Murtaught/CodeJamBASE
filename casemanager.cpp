#include "casemanager.hpp"
#include <QDebug>

CaseManager* CaseManager::instance_ = NULL;

CaseManager *CaseManager::instance()
{
    if ( instance_ == NULL )
        instance_ = new CaseManager();

    return instance_;
}

void CaseManager::setTotalAmountOfCases(int amount)
{
    qDebug() << "Setting total amount of cases to " << amount;

    total_amount  = amount;
    solved_amount = 0;

    if (case_pool != NULL)
        releasePool();

    case_pool = new Case[amount];

    for (int i = 0; i < amount; ++i)
    {
        case_pool[i].setCaseNumber( i + 1 );
        connect(&case_pool[i],    &Case::caseSolved,
                instance_, &CaseManager::caseSolved, Qt::QueuedConnection);
    }
}

void CaseManager::releasePool()
{
    delete[] case_pool;
}

Case *CaseManager::getCase(int case_number)
{
    return &case_pool[case_number - 1];
}

int CaseManager::getTotalAmountOfCases() const
{
    return total_amount;
}

void CaseManager::caseSolved(Case *cs)
{
    ++solved_amount;

    qDebug() << this << ": " << cs << "was solved"
             << "(" << solved_amount << "/" << total_amount << ")";

    if (solved_amount == total_amount)
        emit allCasesAreSolved();
}

CaseManager::CaseManager()
    : QObject(0), total_amount(0), solved_amount(0), case_pool(NULL)
{
}
