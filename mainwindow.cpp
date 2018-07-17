#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <string>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btnSelectVideo_clicked() {

    QMediaPlayer* player = new QMediaPlayer();
    QVideoWidget* vw = new QVideoWidget();

    player->setVideoOutput(vw);

    QFileDialog fileDialog(this);
    fileDialog.setAcceptMode(QFileDialog::AcceptOpen);
    fileDialog.setWindowTitle(tr("Open Movie"));
    if (fileDialog.exec() == QDialog::Accepted)
        player->setMedia(fileDialog.selectedUrls().constFirst());

    vw->setGeometry(0, 0, 20, 12);
    this->setCentralWidget(vw);

    player->play();

    qDebug() << player->state();

}
