#ifndef ANALYSECSV__REVIEWPROCESSOR_H
#define ANALYSECSV__REVIEWPROCESSOR_H

#include <QList>
#include <QStandardItemModel>

#include "Review.h"

class ReviewProcessor
{
  public:
    static QList<Review> reviews(const QString &filePath, QStringList &productNames, QStandardItemModel &model);
    static void processReview(QList <Review> &reviews);
    static QMap<QDate, QMap<QString, int>> countReviewsByDate(const QList<Review> &reviews);
    static QMap<QDate, QMap<QString, int>> countReviewsByDate(const QList<Review> &reviews, const QString &productName);
};

#endif //ANALYSECSV__REVIEWPROCESSOR_H
