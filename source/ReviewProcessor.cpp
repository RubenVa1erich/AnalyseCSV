#include "ReviewProcessor.h"
#include "SentimentAnalyzer.h"

#include <QFile>
#include <QTextStream>

QList <Review> ReviewProcessor::reviews(const QString &filePath, QStringList &productNames, QStandardItemModel &model)
{
    QList <Review> reviews;
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        QString line = in.readLine();
        QStringList fields = line.split(',');
        model.setHorizontalHeaderLabels(fields);

        while (!in.atEnd())
        {
            line = in.readLine();
            fields = line.split(',');
            QList<QStandardItem *> items;

            for(auto &field : fields)
            {
                items.append(new QStandardItem(field));
            }
            model.appendRow(items);

            if (fields.size() >= 3)
            {
                Review review;
                review.productName = fields[0].trimmed();
                review.reviewDate = QDate::fromString(fields[1].trimmed(), "dd-MM-yyyy");
                review.reviewText = fields[2].trimmed();

                reviews.append(review);

                if (!productNames.contains(review.productName))
                {
                    productNames.append(review.productName);
                }
            }
        }
        file.close();
    }
    return reviews;
}

void ReviewProcessor::processReview(QList <Review> &reviews)
{
    for(auto &review : reviews)
    {
        review.reviewSentiment = SentimentAnalyzer::analyseSentiment(review.reviewText);
    }
}

QMap <QDate, QMap <QString, int>> ReviewProcessor::countReviewsByDate(const QList <Review> &reviews)
{
    QMap<QDate, QMap<QString, int>> reviewsCount;

    for(const auto &review : reviews)
    {
        reviewsCount[review.reviewDate][review.reviewSentiment]++;
    }

    return reviewsCount;
}

QMap <QDate, QMap <QString, int>> ReviewProcessor::countReviewsByDate(const QList <Review> &reviews, const QString &selectedProduct)
{
    QMap<QDate, QMap<QString, int>> reviewsCount;

    for(const auto& review : reviews)
    {
        if(review.productName == selectedProduct)
        {
            reviewsCount[review.reviewDate][review.reviewSentiment]++;
        }
    }

    return reviewsCount;
}
