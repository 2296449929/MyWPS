#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mdiArea->setBackground(QBrush(Qt::white));
}

MainWindow::~MainWindow()
{
    delete ui;
}

