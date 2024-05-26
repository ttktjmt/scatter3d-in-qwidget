#include "myscatter3d.h"
#include <QDebug>
#include <random>

MyScatter3D::MyScatter3D(QWidget *parent)
    : QWidget{parent}
{
    quickWidget = new QQuickWidget(this);
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    quickWidget->setAttribute(Qt::WA_AcceptTouchEvents);
    quickWidget->setSource(QUrl("qrc:/graph.qml"));

    // connect(quickWidget, &QQuickWidget::statusChanged, this, &FeatureSpaceView3D::onStatusChangedView);
    // connect(quickWidget, &QQuickWidget::sceneGraphError, this, &FeatureSpaceView3D::onSceneGraphError);

    dataView = quickWidget->rootObject()->findChild<QQuickItem*>("dataView");
    if (!dataView) {
        qWarning() << "dataView not found";
        return;
    }
}

float MyScatter3D::genRandomFloat(float min, float max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

void MyScatter3D::AddPlot()
{
    // generate additional plot with random position
    qDebug() << "AddPlot() called!!";
    QVariant x(genRandomFloat());
    QVariant y(genRandomFloat());
    QVariant z(genRandomFloat());

    dataView = quickWidget->rootObject()->findChild<QQuickItem*>("dataView");
    QMetaObject::invokeMethod(dataView, "addPlot",
                              Q_ARG(QVariant, x),
                              Q_ARG(QVariant, y),
                              Q_ARG(QVariant, z));
}

void MyScatter3D::RemovePlot()
{
    // remove the latest plot
    qDebug() << "RemovePlot() called!!";
    dataView = quickWidget->rootObject()->findChild<QQuickItem*>("dataView");
    QMetaObject::invokeMethod(dataView, "removePlot");
}

void MyScatter3D::RealTimePlot()
{
    // project real-time plot with random position
    qDebug() << "RealTimePlot() called!!";
    QVariant x(genRandomFloat());
    QVariant y(genRandomFloat());
    QVariant z(genRandomFloat());

    dataView = quickWidget->rootObject()->findChild<QQuickItem*>("dataView");
    QMetaObject::invokeMethod(dataView, "realTimePlot",
                              Q_ARG(QVariant, x),
                              Q_ARG(QVariant, y),
                              Q_ARG(QVariant, z));
}
