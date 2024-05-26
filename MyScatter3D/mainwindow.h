#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myscatter3d.h"
#include <QMainWindow>
#include <QTimer>

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

private:
    Ui::MainWindow *ui;
    MyScatter3D *scatter;
    QTimer *timer;
};
#endif // MAINWINDOW_H
