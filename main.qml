import QtQuick 2.12
import QtQuick.Controls 2.12
import Viewer 1.0
import Viewer1 1.0
import Viewer2 1.0
import Viewer3 1.0
import Viewer4 1.0
import QtMultimedia 5.12


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

    /*
    property int currentIndex: 0
    property var imagePaths: ["img1.jpg", "img2.jpg", "img3.jpg"]

    Image {
        id: background
        anchors.fill: parent
        source: "file:///home/sejong/Work/Lteraphy/L_Teraphy/image/background/"+imagePaths[currentIndex]

        Timer {
            interval: 1000 // 1초마다
            running: true
            repeat: true

            onTriggered: {
                currentIndex = (currentIndex + 1) % imagePaths.length;
                background.source = "file:///home/sejong/Work/Lteraphy/L_Teraphy/image/background/" + imagePaths[currentIndex];
            }
        }
    }

    */

    Item {
        id:mediaplay_contorl
        anchors.fill: parent

        MediaPlayer {
            id: mediaPlayer
            source: "file:///home/sejong/Work/Lteraphy/L_Teraphy/image/background/LESSERAFIM.mp4"

            onPlaybackStateChanged: {
                if (playbackState === 0/*MediaPlayer.EndOfMediaState*/) {
                    mediaPlayer.seek(0);
                    mediaPlayer.play();
                }
            }
        }

        VideoOutput {
            id: videoOutput
            anchors.fill: parent
            source: mediaPlayer
        }

        Component.onCompleted: {
            mediaPlayer.muted =true
            mediaPlayer.play()
        }
    }


    Item {
        id: view_control
        width: 640
        height: 480

        /*
        Viewer {
            id:viewer
            //anchors.fill: parent
            x:20
            y:100
            width: 600
            height: 600

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer.openViewer()
                //viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/0.PNG")
                //viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/test.PNG")
                //viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/btn_Camera_B_on.png")
                viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/img_car_01.png")

            }
        }
        */


        Viewer1 {
            id:viewer1
            //anchors.fill: parent
            x:20
            y:100
            width: 600
            height: 600

            Component.onCompleted: {
                console.log(" viewer completed")
                viewer1.openViewer()
                //viewer1.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/1.PNG")
                viewer1.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/test.png")

            }
        }

        /*
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
        */

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
        //timer.start()

        //opencv test, save a png file
        viewer.z =1
        viewer1.z =0
        viewer2.z =0
        viewer3.z =0
        viewer4.z =0
    }

}
