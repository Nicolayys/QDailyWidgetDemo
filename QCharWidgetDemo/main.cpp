#include "mainwindow.h"

#include <QApplication>
#include "line_chart.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    // LineChart *linechart = new LineChart();
    // w.setCentralWidget(linechart);

    w.show();

    return a.exec();
}
