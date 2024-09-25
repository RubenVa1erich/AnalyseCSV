#ifndef ANALYSECSV__CHARTCREATOR_H
#define ANALYSECSV__CHARTCREATOR_H

#include <QMap>
#include <QDate>
#include <QtCharts>
#include <QDateTimeAxis>

class ChartCreator
{
  public:
    static void createChart(const QMap<QDate, QMap<QString, int>> &countReviews, QChart* chart);

};

#endif //ANALYSECSV__CHARTCREATOR_H
