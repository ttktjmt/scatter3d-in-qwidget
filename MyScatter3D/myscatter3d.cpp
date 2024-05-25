#include "myscatter3d.h"

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
