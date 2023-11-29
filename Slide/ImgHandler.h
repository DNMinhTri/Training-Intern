#ifndef IMGHANDLER_H
#define IMGHANDLER_H
#include <QObject>
#include <QStringList>
#include <QString>
#include <qqml.h>


class ImgHandler : public QObject
{
    Q_OBJECT

public:
    explicit ImgHandler(QObject *parent = nullptr);

    Q_INVOKABLE void selectImages();
    Q_INVOKABLE QString getImages () const;
    Q_INVOKABLE int getsize();
    Q_INVOKABLE int getindex();

    Q_PROPERTY(QString image READ getImages NOTIFY imagesUpdated)

signals:
    void imagesUpdated();
    void starttimer();
    void stoptimer();
public slots:
    void tick();
    void updateImage();

public:
    QStringList imageList;
    QString image;
    int index = 0;

};
#endif // IMGHANDLER_H
