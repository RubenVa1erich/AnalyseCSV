cmake_minimum_required(VERSION 3.28)
project(AnalyseCSV)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Core Gui Widgets Charts REQUIRED)

include_directories(include)

qt_add_executable(AnalyseCSV
        resource/CSVAnalyzer.ui
        include/CSVAnalyzer.h
        include/ChartCreator.h
        include/Review.h
        include/ReviewProcessor.h
        include/SentimentAnalyzer.h
        source/main.cpp
        source/CSVAnalyzer.cpp
        source/ChartCreator.cpp
        source/Review.cpp
        source/ReviewProcessor.cpp
        source/SentimentAnalyzer.cpp
)

target_link_libraries(AnalyseCSV PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Charts
)
