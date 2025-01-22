#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QChartView;
class QtCharts;
class QChart;
QT_END_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_type_combox__currentIndexChanged(int index);

    void on_x_combox__currentTextChanged(const QString &arg1);

    void on_y_combox__currentTextChanged(const QString &arg1);

    void on_zoom_in__clicked();

    void on_zoom_out__clicked();

private:
    Ui::MainWindow *ui;
    QChartView *chart_view_;
    QChart *chart_;
};
#endif // MAINWINDOW_H
