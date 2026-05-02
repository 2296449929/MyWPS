#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "QFontDatabase"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    init(); //初始化Mainwindow
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    ui->mdiArea->setBackground(QBrush(Qt::white));

    initFontSize();     //初始化字号组合框
    initScrollBar();    //初始化滚动条
}

void MainWindow::initFontSize()
{
    ui->comboBoxFontSize->clear();

    for(int i : QFontDatabase::standardSizes()){    //standardSizes返回标准字体大小的列表
        ui->comboBoxFontSize->addItem(QString::number(i));
    }

    QFont font = QApplication::font();  //获取当前应用程序默认字体
    int fontSize = font.pointSize();
    int index = ui->comboBoxFontSize->findText(QString::number(fontSize));
    ui->comboBoxFontSize->setCurrentIndex(index);
}

void MainWindow::initScrollBar()
{
    //设置水平垂直滚动条显示策略
    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

