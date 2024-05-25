import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtDataVisualization 1.2
import "."

Item {
    id: mainView
    width: 700
    height: 500

    ListModel {
        id: dataModel1
        ListElement{ xPos: 7.8; yPos: -2.2; zPos: 5.0 }
        ListElement{ xPos: 7.6; yPos: -2.4; zPos: 4.5 }
        ListElement{ xPos: 9.4; yPos: -2.6; zPos: 3.8 }
    }

    ListModel {
        id: dataModel2
        ListElement{ xPos: -9.0; yPos: 3.0; zPos: -4.5 }
        ListElement{ xPos: -8.5; yPos: 4.1; zPos: -4.0 }
        ListElement{ xPos: -8.0; yPos: 4.75; zPos: -3.9 }
    }

    ListModel {
        id: dataModel3
        ListElement{ xPos: 2.25 ; yPos: 1.36 ; zPos: -1.3 }
        ListElement{ xPos: -2 ; yPos: -0.08 ; zPos: 1 }
        ListElement{ xPos: 2.65 ; yPos: -1.2 ; zPos: 2.7 }
        ListElement{ xPos: -2.55 ; yPos: 3.48 ; zPos: -0.45 }
    }

    Item {
        id: dataView
        objectName: "dataView"
        anchors.bottom: parent.bottom
        width: parent.width
        height: parent.height

        Scatter3D {
            id: scatterGraph
            width: dataView.width
            height: dataView.height
            theme: theme
            axisX.segmentCount: 3
            axisX.subSegmentCount: 2
            axisX.labelFormat: "%.2f"
            axisY.segmentCount: 2
            axisY.subSegmentCount: 2
            axisY.labelFormat: "%.2f"
            axisZ.segmentCount: 2
            axisZ.subSegmentCount: 2
            axisZ.labelFormat: "%.2f"
            Scatter3DSeries {
                id: scatterSeries
                itemLabelFormat: "Series 1: X:@xLabel Y:@yLabel Z:@zLabel"

                ItemModelScatterDataProxy {
                    itemModel: dataModel1
                    xPosRole: "xPos"
                    yPosRole: "yPos"
                    zPosRole: "zPos"
                }
            }

            Scatter3DSeries {
                id: scatterSeriesTwo
                itemLabelFormat: "Series 2: X:@xLabel Y:@yLabel Z:@zLabel"
                itemSize: 0.2
                mesh: Abstract3DSeries.MeshCube

                ItemModelScatterDataProxy {
                    itemModel: dataModel2
                    xPosRole: "xPos"
                    yPosRole: "yPos"
                    zPosRole: "zPos"
                }
            }
            Scatter3DSeries {
                id: scatterSeriesThree
                itemLabelFormat: "Series 3: X:@xLabel Y:@yLabel Z:@zLabel"
                itemSize: 0.2
                mesh: Abstract3DSeries.MeshPyramid

                ItemModelScatterDataProxy {
                    itemModel: dataModel3
                    xPosRole: "xPos"
                    yPosRole: "yPos"
                    zPosRole: "zPos"
                }
            }
        }
    }
}
