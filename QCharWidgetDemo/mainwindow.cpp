#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QChartView>
#include <QtCharts>
#include <QtCharts/QBarSet>
#include <QtCharts/QPieSlice>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart_ = new QChart();

    QPieSeries *series = new QPieSeries();
    series->append("2",20);
    series->append("13",40);
    series->append("12",40);


    chart_->addSeries(series);
    chart_->setTitle("line chart");
    chart_->legend()->setVisible(true); //图例是否能看到 -显示名称或标签
    chart_->legend()->setAlignment(Qt::AlignLeft);
    chart_->setAnimationOptions(QChart::AllAnimations);//设置进场动画
    chart_->createDefaultAxes();


    chart_view_ = new QChartView(chart_);
    chart_view_->setRenderHint(QPainter::Antialiasing);
    ui->scroll_area_->setWidget(chart_view_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_type_combox__currentIndexChanged(int index)
{
    chart_->removeAllSeries();
    if(0 == index){
        //柱状图
        QBarSet * set0 = new QBarSet("Mickle");
        QBarSet * set1 = new QBarSet("Jone");

        *set0<<1<<2<<3<<4<<5<<6;
        *set1<<5<<0<<1<<8<<9<<2;
        QBarSeries * bar_series = new QBarSeries();
        bar_series->append(set0);
        bar_series->append(set1);

        QValueAxis * axisX = new QValueAxis();
        axisX->setTitleText("饼状图-x");
        axisX->setTickCount(10);
        axisX->setRange(0,20);

        QValueAxis * axisY = new QValueAxis();
        axisY->setTitleText("饼状图-y");
        axisY->setTickCount(5);
        axisY->setRange(10,100);

        chart_->setAxisX(axisX,bar_series);
        chart_->setAxisY(axisY,bar_series);

        chart_->addSeries(bar_series);


    }else if(1 == index){
        //折线图
        QLineSeries *series = new QLineSeries();
        series->append(1,10);
        series->append(2,15);
        series->append(3,20);
        series->append(4,60);
        *series<<QPoint(5,30)<<QPoint(6,35)<<QPoint(7,80);

        chart_->addSeries(series);

    }else if(2 == index){
        //饼状图
        QPieSeries *series = new QPieSeries();
        series->append("2",20);
        series->append("13",40);
        series->append("12",40);

        for (int var = 0; var < 5; ++var) {
            QPieSlice * slice = new QPieSlice(QString::number(var),QRandomGenerator::global()->bounded(1000));

            connect(slice, &QPieSlice::hovered, this, [slice](bool state){
                slice->setExploded(state);
            });

            *series<<slice;
        }
        chart_->addSeries(series);
    }


}


void MainWindow::on_x_combox__currentTextChanged(const QString &arg1)
{

}


void MainWindow::on_y_combox__currentTextChanged(const QString &arg1)
{

}


void MainWindow::on_zoom_in__clicked()
{
    chart_->zoomIn();
}


void MainWindow::on_zoom_out__clicked()
{
    chart_->zoomOut();
}

