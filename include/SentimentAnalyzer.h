#ifndef ANALYSECSV__SENTIMENTANALYZER_H
#define ANALYSECSV__SENTIMENTANALYZER_H

#include <QString>

class SentimentAnalyzer
{
  public:
    static QString analyseSentiment(const QString& text);
};

#endif //ANALYSECSV__SENTIMENTANALYZER_H
