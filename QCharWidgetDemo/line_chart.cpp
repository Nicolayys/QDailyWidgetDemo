#include "line_chart.h"
#include "ui_line_chart.h"

#include <QtCharts>
#include <QPoint>
LineChart::LineChart(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LineChart)
{
    ui->setupUi(this);

    //相当于data 数据层
    //折线图
    // QLineSeries *series = new QLineSeries();
    // series->append(1,10);
    // series->append(2,15);
    // series->append(3,20);
    // series->append(4,60);
    // *series<<QPoint(5,30)<<QPoint(6,35)<<QPoint(7,80);

    // 饼状图
    QPieSeries *series = new QPieSeries();
    series->append("2",20);
    series->append("13",40);
    series->append("12",40);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true); //切片的爆炸效果
    slice->setLabelVisible(true);//标签的隐藏
    slice->setBrush(Qt::blue);
    //柱状图
    // QBarSet *set0 = new QBarSet("joho");
    // QBarSet *set1 = new QBarSet("anno");
    // *set0<<1<<2<<4;
    // *set1<<12<<23<<44;
    // QBarSeries * series = new QBarSeries();
    // series->append(set0);
    // series->append(set1);

    // 模型层 model
    QChart * chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("line chart");
    chart->legend()->setVisible(true); //图例是否能看到 -显示名称或标签
    chart->legend()->setAlignment(Qt::AlignLeft);
    chart->setAnimationOptions(QChart::AllAnimations);//设置进场动画
    chart->createDefaultAxes();
    //视图层 view
    QChartView * chartView = new QChartView();
    chartView->setChart(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(chartView);
    this->setLayout(layout);
}

LineChart::~LineChart()
{
    delete ui;
}
