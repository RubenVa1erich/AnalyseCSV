#include <QList>

#include "SentimentAnalyzer.h"


QString SentimentAnalyzer::analyseSentiment(const QString &text)
{
    int countPositiveReview = 0;
    int countNegativeReview = 0;

    QStringList positiveWords = {"хорошо", "отлично", "прекрасно", "замечательно"};
    QStringList negativeWords = {"плохо", "ужасно", "неприятно", "разочарован"};

    for(const QString& word : positiveWords)
    {
        if(text.contains(word, Qt::CaseInsensitive))
        {
            countPositiveReview++;
        }
    }

    for(const QString& word : negativeWords)
    {
        if(text.contains(word, Qt::CaseInsensitive))
        {
            countNegativeReview++;
        }
    }

    if(countPositiveReview > countNegativeReview) return "positive";
    else if(countPositiveReview < countNegativeReview) return "negative";
    else return "neutral";
}
