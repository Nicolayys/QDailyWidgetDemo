#ifndef DOWN_SLICE_H
#define DOWN_SLICE_H

#include <QPieSlice>
#include <QAbstractSeries>
class DownSlice : public QPieSlice
{
    Q_OBJECT
public:
    explicit DownSlice(QString label, qreal value,
                       QAbstractSeries * downSeries,QChart* chart,
                       QObject *parent = nullptr);

public Q_SLOTS:
    void showHightLight(bool show);
    void handSliceClicked();
private:
    QAbstractSeries * downSeries;
    QChart * chart;
};

#endif // DOWN_SLICE_H
