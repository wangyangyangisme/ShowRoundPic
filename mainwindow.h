#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage getRoundQImage(const QImage& img,QSize size);
    void paintEvent(QPaintEvent* e);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
