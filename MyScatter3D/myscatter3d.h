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

public:
    explicit MyScatter3D(QWidget *parent = nullptr);

signals:
};

#endif // MYSCATTER3D_H
