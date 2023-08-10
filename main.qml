import QtQuick 2.12
import QtQuick.Controls 2.12
import Viewer 1.0
import Viewer1 1.0
import Viewer2 1.0
import Viewer3 1.0
import Viewer4 1.0


ApplicationWindow {
    visible: true
    width: 800
    height: 600

    function runSequence()
    {
        if(viewer.z ==1){
            viewer.z =0
            viewer1.z =1
            viewer2.z =0
            viewer3.z =0
            viewer4.z =0
        }
        else if(viewer1.z ==1){
            viewer.z =0
            viewer1.z =0
            viewer2.z =1
            viewer3.z =0
            viewer4.z =0
        }
        else if(viewer1.z ==1){
            viewer.z =0
            viewer1.z =0
            viewer2.z =1
            viewer3.z =0
            viewer4.z =0
        }
        else if(viewer2.z ==1){
            viewer.z =0
            viewer1.z =0
            viewer2.z =0
            viewer3.z =1
            viewer4.z =0
        }
        else if(viewer3.z ==1){
            viewer.z =0
            viewer1.z =0
            viewer2.z =0
            viewer3.z =0
            viewer4.z =1
        }
        else {
            viewer.z =1
            viewer1.z =0
            viewer2.z =0
            viewer3.z =0
            viewer4.z =0
        }
    }

    Item {
        id: control
        width: 640
        height: 480

        Viewer {
            id:viewer
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer.openViewer()
                viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/0.PNG")

            }
        }

        Viewer1 {
            id:viewer1
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer1.openViewer()
                viewer1.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/1.PNG")

            }
        }

        Viewer2 {
            id:viewer2
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer2.openViewer()
                viewer2.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/2.PNG")

            }
        }

        Viewer3 {
            id:viewer3
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer3.openViewer()
                viewer3.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/3.PNG")

            }
        }
        Viewer4 {
            id:viewer4
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer4.openViewer()
                viewer4.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/4.PNG")

            }
        }
    }

/*
    Button {
        id:layerChange
        x:650
        y:10
        text: "Layer Change"
        onClicked: {
            console.log(";;;;")

            if(viewer.z ==1){
                viewer.z =0
                viewer1.z =1
            }
            else {
                viewer.z =1
                viewer1.z =0
            }
        }
    }
    */

    Timer {
        id: timer
        interval: 330-200 // 1초마다
        repeat: true
        running: false // 시작 전에는 타이머 중지

        onTriggered: {
            //counter++;
            runSequence()

        }
    }

    Component.onCompleted: {
        timer.start()
    }

}
