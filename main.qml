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
                viewer.doWork(file)

            }
            else if(index ==1){
                viewer1.visible =true
                console.log("### index =1")
                viewer1.doWork(file)
            }
            else if(index ==2){
                viewer2.visible =true
                console.log("### index =2")
                viewer2.doWork(file)
            }
            else if(index ==3){
                viewer3.visible =true
                console.log("### index =3")
                viewer3.doWork(file)
            }
            else {
                viewer4.visible =true
                console.log("### index =4")
                viewer4.doWork(file)
            }
        }
    }


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


    Item {
        id: view_control
        anchors.fill: parent

        Viewer {
            id:viewer
            anchors.fill: parent
        }

        Viewer1 {
            id:viewer1
            anchors.fill: parent
        }


        Viewer2 {
            id:viewer2
            anchors.fill: parent
        }

        Viewer3 {
            id:viewer3
            anchors.fill: parent
        }

        Viewer4 {
            id:viewer4
            anchors.fill: parent
        }
    }

    /*

    Row {
        anchors.fill: parent
        spacing: 10

        Button {
            text: "Click me!"
            onClicked: {
                console.log("Button clicked!")
                viewer.visible =true
                console.log("### index =0")
                viewer.doWork("/home/sejong/Work/Lteraphy/L_Teraphy/image/0.png")
            }
        }

        Button {
            text: "Click me 2!"
            onClicked: {
                console.log("Button 2 clicked!")
                viewer.visible =false
                viewer1.visible =true
            }
        }
    }

    Component.onCompleted: {
    }

    */
}
