import QtQuick 2.12
import QtQuick.Controls 2.12
import QtMultimedia 5.12

import Viewer 1.0
import Viewer1 1.0
import Viewer2 1.0
import Viewer3 1.0
import Viewer4 1.0
import interfaceManager 1.0

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
    //동작이 느려 사용못할 것 같음

    */

    function disableVisible()
    {
        viewer.visible = false
        viewer1.visible = false
        viewer2.visible = false
        viewer3.visible = false
        viewer4.visible = false
    }

    Connections {
        target: InterfaceManager

        onSigWriteDone:{
            console.log("qml sigWrite Done"+index)
            disableVisible()


            if(index ==0){
                viewer.visible =true
                console.log("### index =0")
                viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/0.png")

            }
            else if(index ==1){
                viewer1.visible =true
                console.log("### index =1")
                viewer1.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/1.png")
            }
            else if(index ==2){
                viewer2.visible =true
                console.log("### index =2")
                viewer2.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/2.png")
            }
            else if(index ==3){
                viewer3.visible =true
                console.log("### index =3")
                viewer3.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/3.png")
            }
            else {
                viewer4.visible =true
                console.log("### index =4")
                viewer4.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/4.png")
            }

        }
    }



    /*
    Item {
        id:mediaplay_contorl
        anchors.fill: parent

        MediaPlayer {
            id: mediaPlayer
            source: "file:///home/sejong/Work/Lteraphy/L_Teraphy/image/background/LESSERAFIM.mp4"

            onPlaybackStateChanged: {
                if (playbackState === 0) {
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
    */


    Item {
        id: view_control
        //width: 640
        //height: 480
        anchors.fill: parent

        MediaPlayer {
            id: mediaPlayer
            source: "file:///home/sejong/Work/Lteraphy/L_Teraphy/image/background/LESSERAFIM.mp4"

            onPlaybackStateChanged: {
                if (playbackState === 0) {
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







        Viewer {
            id:viewer
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                //viewer.openViewer()
                //viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/1.png")

            }

        }



        Viewer1 {
            id:viewer1
            anchors.fill: parent

            Component.onCompleted: {
                console.log(" viewer completed")
                //viewer1.openViewer()
                //viewer1.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/1.png")

            }

        }


        Viewer2 {
            id:viewer2
            anchors.fill: parent


            Component.onCompleted: {
                console.log(" viewer completed")
                //viewer2.openViewer()
                //viewer2.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/2.png")

            }

        }

        Viewer3 {
            id:viewer3
            anchors.fill: parent


            Component.onCompleted: {
                console.log(" viewer completed")
                //viewer3.openViewer()
                //viewer3.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/3.png")

            }

        }
        Viewer4 {
            id:viewer4
            anchors.fill: parent


            Component.onCompleted: {
                console.log(" viewer completed")
                //viewer4.openViewer()
                //viewer4.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/4.png")

            }

        }
    }

    Row {
        anchors.fill: parent
        spacing: 10

        Button {
            text: "Click me!"
            onClicked: {
                console.log("Button clicked!")

                //videoOutput.z =0
                //viewer.visible =true
                //viewer1.visible =false
                viewer.visible =true
                console.log("### index =0")
                viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/0.png")

            }
        }

        Button {
            text: "Click me 2!"
            onClicked: {
                console.log("Button 2 clicked!")
                //videoOutput.z =3
                viewer.visible =false
                viewer1.visible =true
            }
        }
    }

    Component.onCompleted: {
        //opencv test, save a png file
        //viewer.z =1
        //viewer1.z =0
        //viewer2.z =0
        //viewer3.z =0
        //viewer4.z =0
        //mediaplay_contorl.z =4
    }

}
