#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scatter = ui->MyScatterWidget;

    connect(ui->addButton,      SIGNAL(clicked(bool)),  scatter,    SLOT(AddPlot()));
    connect(ui->removeButton,   SIGNAL(clicked(bool)),  scatter,    SLOT(RemovePlot()));

    timer = new QTimer(this);
    connect(timer,              SIGNAL(timeout()),      scatter,    SLOT(RealTimePlot()));
    timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}
