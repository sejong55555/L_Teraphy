import QtQuick 2.12
import QtQuick.Controls 2.12
import Viewer 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Viewer {
        id:viewer
        anchors.fill: parent

        Component.onCompleted: {
            console.log(" viewer completed")
            viewer.openViewer()

        }
    }
}
