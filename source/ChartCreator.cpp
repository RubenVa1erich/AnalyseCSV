#include "ChartCreator.h"

#include <memory>


void ChartCreator::createChart(const QMap <QDate, QMap <QString, int>> &countReviews, QChart* chart)
{
    chart->removeAllSeries();
    for(auto& axis : chart->axes())
    {
        chart->removeAxis(axis);
    }

    int maxCountReview = 0;

    auto* series = new QHorizontalStackedBarSeries(chart);
    auto* positiveSet = new QBarSet("positive");
    auto* negativeSet = new QBarSet("negative");
    auto* neutralSet = new QBarSet("neutral");

    for (auto it = countReviews.begin(); it != countReviews.end(); it++)
    {
        int positiveCount = it.value().value("positive", 0);
        int negativeCount = it.value().value("negative", 0);
        int neutralCount = it.value().value("neutral", 0);

        positiveSet->append(positiveCount);
        negativeSet->append(negativeCount);
        neutralSet->append(neutralCount);

        maxCountReview = qMax(maxCountReview, positiveCount + negativeCount + neutralCount);
    }

    series->append(positiveSet);
    series->append(negativeSet);
    series->append(neutralSet);

    chart->addSeries(series);

    QStringList categories;
    for (auto it = countReviews.begin(); it != countReviews.end(); it++)
    {
        categories << it.key().toString("dd.MM.yyyy");
    }

    auto* axisY = new QBarCategoryAxis(chart);
    axisY->append(categories);
    axisY->setTitleText("Date");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    auto* axisX = new QValueAxis(chart);
    axisX->setTitleText("Count reviews");
    axisX->setTickInterval(1.0);
    axisX->setRange(0, maxCountReview);
    axisX->setTickCount(maxCountReview + 1);
    axisX->setLabelFormat("%i");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
}
