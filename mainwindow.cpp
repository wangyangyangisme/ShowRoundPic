#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QImage>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::getRoundQImage(const QImage& img,QSize size)
{
    if (img.isNull())
    {
        return QImage();
    }
    QImage resultImage(size,QImage::Format_ARGB32_Premultiplied);
    QImage mask("mask.png");
    QPainter painter(&resultImage);
    painter.setCompositionMode(QPainter::CompositionMode_Source);
    painter.fillRect(resultImage.rect(), Qt::transparent);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.drawImage(0, 0, mask);
    painter.setCompositionMode(QPainter::CompositionMode_SourceOut);
    painter.drawImage(0, 0, img.scaled(size));
    painter.setCompositionMode(QPainter::CompositionMode_DestinationOver);
    painter.end();
    return resultImage;
}

void MainWindow::paintEvent(QPaintEvent* e)
{
    QPainter p(this);
    p.drawImage(50,50,getRoundQImage(QImage("user.png"),QSize(140,140)));
}
