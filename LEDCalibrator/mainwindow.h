#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/colorgrid.h"
#include "Led/leds.h"

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
    void on_pushButton_clicked();
    void on_tableWidget_cellChanged(int row, int column);

    void colorChanged();

private:
    Ui::MainWindow *ui;

    ColorGrid *m_colorGrid;
    LEDS *m_leds;

    void setupTable();
    void addRow(LED *l);
};
#endif // MAINWINDOW_H
