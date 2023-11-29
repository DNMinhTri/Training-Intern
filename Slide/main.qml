import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Dialogs 1.3
import QtQuick.Controls 2.15

import ImgHandler 1.0
import "."

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Image Selector")

    ImgHandler {
        id: imghandler
    }
    Timer {
        id: onesec
        interval: 1000 // 1s
        running: false
        repeat: true   // Repeat

        onTriggered: {
            console.log("Timer triggered");
            imghandler.tick();
            console.log(imghandler.getImages())
            console.log(imghandler.getsize())
            console.log(imghandler.getindex())
        }

    }

    Connections {
        target: imghandler
        function onStarttimer() {
            onesec.start();
        }
        function onStoptimer() {
            onesec.stop();
        }
        function onImagesUpdated() {
            image1.source = imghandler.getImages();
            image2.source = imghandler.getImages();
        }
    }

    Column{
        anchors.centerIn: parent
        spacing:20

        Row{
            id: c1
            spacing: 20
            anchors.horizontalCenter: parent.horizontalCenter
            Image   {
                id: image1
                width: 200
                height: 200
                source: imghandler.getImages()
                anchors.verticalCenter: c1.verticalCenter
                fillMode: Image.Stretch
                MouseArea {
                            anchors.fill: parent

                            onPositionChanged:{
                                if (image1.width >= mouseX)
                                image1.width = image1.width - mouseX
                                else if (image1.width < mouseX)
                                    image1.width = mouseX - image1.width

                                if (image1.height >= mouseY)
                                image1.height = image1.height - mouseY
                                else if (image1.height < mouseY)
                                    image1.height =  mouseY - image1.height

                                if (image1.width > 300) image1.width = 300
                                if (image1.width < 50) image1.width = 50
                                if (image1.height > 300) image1.height = 300
                                if (image1.height < 50) image1.height = 50
                            }
                            onClicked: {
                                onesec.restart();
                                imghandler.updateImage();
                            }
                }
            }

            Image   {
                id: image2
                width: 200
                height: 200
                source: imghandler.getImages()
                anchors.verticalCenter: c1.verticalCenter
                fillMode: Image.Stretch
                MouseArea {
                            anchors.fill: parent

                            onPositionChanged:{
                                if (image2.width >= mouseX)
                                image2.width = image2.width - mouseX
                                else if (image2.width < mouseX)
                                    image2.width = mouseX - image2.width

                                if (image2.height >= mouseY)
                                image2.height = image2.height - mouseY
                                else if (image2.height < mouseY)
                                    image2.height =  mouseY - image2.height

                                if (image2.width > 300) image2.width = 300
                                if (image2.width < 50) image2.width = 50
                                if (image2.height > 300) image2.height = 300
                                if (image2.height < 50) image2.height = 50
                            }
                            onClicked: {
                                onesec.restart();
                                imghandler.updateImage();
                            }
                }
            }
        }
        Button  {
            width:200
            anchors.horizontalCenter: c1.horizontalCenter
            text: "Select images"
            onClicked: imghandler.selectImages()
        }
    }
}
