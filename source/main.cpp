#include <QApplication>
#include <memory>

#include "CSVAnalyzer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::unique_ptr <CSVAnalyzer> w = std::make_unique <CSVAnalyzer>();
    w->resize(800, 600);
    w->show();

    return QApplication::exec();
}
