#ifndef MYSCATTER3D_H
#define MYSCATTER3D_H

#include <QWidget>
#include <QQuickWidget>
#include <QQuickItem>
#include <QTimer>
#include <QtDataVisualization/Q3DScatter>

class MyScatter3D : public QWidget
{
    Q_OBJECT

private:
    QQuickWidget *quickWidget;
    QQuickItem *dataView;
    float genRandomFloat(float min = -5.0f, float max = 5.0f);

public:
    explicit MyScatter3D(QWidget *parent = nullptr);

signals:

public slots:
    void AddPlot();
    void RemovePlot();
    void RealTimePlot();
};

#endif // MYSCATTER3D_H
