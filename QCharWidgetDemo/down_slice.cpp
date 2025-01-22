#include "down_slice.h"

#include <QChart>
DownSlice::DownSlice(QString label, qreal value, QAbstractSeries *downSeries, QChart *chart, QObject *parent)
: QPieSlice{parent},
    downSeries(downSeries),
    chart(chart)
{
    setValue(value);

    label += QString::number(this->value());
    label += ",";
    label += QString::number(this->percentage()*100,'f',1);
    setLabel(label);

    connect(this,&DownSlice::hovered,this,&DownSlice::showHightLight);
    connect(this,&DownSlice::clicked,this,&DownSlice::handSliceClicked);
}

void DownSlice::showHightLight(bool show)
{
    //光标浮动时效果
    setLabelVisible(show);
    setExploded(show);
}

void DownSlice::handSliceClicked()
{
    //清空当前chart的内容，添加新的数据
    chart->removeSeries(chart->series().first());
    chart->addSeries(downSeries);
    chart->setTitle(downSeries->name());
}
