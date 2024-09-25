#ifndef ANALYSECSV__CSVANALYZER_H
#define ANALYSECSV__CSVANALYZER_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QMap>
#include <QChartView>
#include <QStringList>
#include <QFileDialog>
#include <QStandardItemModel>

#include <memory>

#include "Review.h"
#include "ReviewProcessor.h"
#include "ChartCreator.h"


QT_BEGIN_NAMESPACE
namespace Ui
{
    class CSVAnalyzer;
}
QT_END_NAMESPACE

class CSVAnalyzer : public QWidget
{
  Q_OBJECT

  public:
    explicit CSVAnalyzer(QWidget *parent = nullptr);
    ~CSVAnalyzer() override;

  private:
    std::unique_ptr<Ui::CSVAnalyzer> ui;
    QChartView* chartView;
    QList<Review> reviews;
    QStandardItemModel model;
    QStringList productNames;
    QMap<QDate, QMap<QString, int>> reviewCounts;

  private slots:
    void chooseFileButtonClicked();
    void analyseButtonClicked();
    void updateChart();
};

#endif //ANALYSECSV__CSVANALYZER_H
