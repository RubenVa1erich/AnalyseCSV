#ifndef ANALYSECSV__REVIEW_H
#define ANALYSECSV__REVIEW_H

#include <QString>
#include <QDate>

class Review
{
  public:
    QString productName;
    QDate reviewDate;
    QString reviewText;
    QString reviewSentiment;
};

#endif //ANALYSECSV__REVIEW_H
