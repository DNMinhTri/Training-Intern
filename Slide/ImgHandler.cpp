#include "ImgHandler.h"
#include <QFileDialog>
#include <QTimer>
#include <QApplication>
#include <QString>

ImgHandler::ImgHandler(QObject *parent) : QObject(parent) {
    image  = "file:////home/tri/Downloads/images/test.png";
    index = -1;
};

void ImgHandler::selectImages() {
    QStringList imageurls = QFileDialog::getOpenFileNames(nullptr,"Get Images","/home",tr("Image Files (*.png *.jpg)"));
    if (imageurls.size() <= 0) return;
    imageList = imageurls;
    index = 0;
    emit starttimer();

}

int ImgHandler::getsize(){
    QStringList a = imageList;
    return a.size();
}

int ImgHandler::getindex(){

    return index;
}


void ImgHandler::tick(){

    updateImage();
}


QString ImgHandler::getImages() const {
    QString a = "file:///";
    if (index >= 0)
    return a+image;
    else return image;
}

void ImgHandler::updateImage(){
    if (index == -1) return;
        else {
        if (index >= imageList.size())
            index = 0;
        image = imageList.at(index);
        index++;
        emit imagesUpdated();
    }
}

