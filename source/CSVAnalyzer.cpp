#include "CSVAnalyzer.h"
#include "../resource/ui_CSVAnalyzer.h"

CSVAnalyzer::CSVAnalyzer(QWidget *parent) : QWidget(parent)
{
    ui = std::make_unique <Ui::CSVAnalyzer>();
    ui->setupUi(this);

    chartView = new QChartView();
    ui->verticalLayout_2->addWidget(chartView);

    ui->chooseNameProduct->addItem("...");
    ui->chooseNameProduct->setCurrentIndex(0);
    ui->chooseNameProduct->setEnabled(false);

    connect(ui->chooseFileButton, &QPushButton::clicked, this, &CSVAnalyzer::chooseFileButtonClicked);
    connect(ui->analyseButton, &QPushButton::clicked, this, &CSVAnalyzer::analyseButtonClicked);
    connect(ui->chooseNameProduct, &QComboBox::currentIndexChanged, this, &CSVAnalyzer::updateChart);
}

CSVAnalyzer::~CSVAnalyzer()
= default;

void CSVAnalyzer::chooseFileButtonClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Load CSV-File", "", "CSV Files (*.csv)");
    if(!filePath.isEmpty())
    {
        reviews = ReviewProcessor::reviews(filePath, productNames, model);
        ui->tableView->setModel(&model);
        ui->chooseNameProduct->addItems(productNames);
    }
}

void CSVAnalyzer::analyseButtonClicked()
{
    ReviewProcessor::processReview(reviews);
    reviewCounts = ReviewProcessor::countReviewsByDate(reviews);
    updateChart();
    ui->chooseNameProduct->setEnabled(true);
}

void CSVAnalyzer::updateChart()
{
    QString selectedProduct = ui->chooseNameProduct->currentText();
    QMap<QDate, QMap<QString, int>> filterCountReviews;

    if(ui->chooseNameProduct->currentIndex() == 0)
    {
        filterCountReviews = reviewCounts;
    }
    else
    {
        filterCountReviews = ReviewProcessor::countReviewsByDate(reviews, selectedProduct);
    }

    ChartCreator::createChart(filterCountReviews, chartView->chart());
}


