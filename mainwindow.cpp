#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

#include "QFontDatabase"
#include <QMdiSubWindow>

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
    initWindowAction(); //初始化窗体Action
    initDocAction();    //初始化文档Action

    connect(ui->mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::initWindowAction);
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

TextEdit *MainWindow::activateWindow()
{
    QMdiSubWindow* window= ui->mdiArea->activeSubWindow();
    if(window){
        return qobject_cast<TextEdit*>(window->widget());
    }

    return nullptr;
}

void MainWindow::initDocAction()
{
    ui->actionCopy->setEnabled(false);
    ui->actionCut->setEnabled(false);
    ui->actionColor->setEnabled(false);
    ui->actionBold->setEnabled(false);
    ui->actionItalic->setEnabled(false);
    ui->actionUnderline->setEnabled(false);
    ui->actionLeftAlign->setEnabled(false);
    ui->actionCenter->setEnabled(false);
    ui->actionRightAlign->setEnabled(false);
    ui->actionJustify->setEnabled(false);
}

void MainWindow::initWindowAction()
{
    bool haveSubWindow = (activateWindow() != nullptr);

    ui->actionSave->setEnabled(haveSubWindow);
    ui->actionSaveAs->setEnabled(haveSubWindow);
    ui->actionPrint->setEnabled(haveSubWindow);
    ui->actionPrintView->setEnabled(haveSubWindow);
    ui->actionUndo->setEnabled(haveSubWindow);
    ui->actionRedo->setEnabled(haveSubWindow);
    ui->actionPaste->setEnabled(haveSubWindow);
    ui->actionClose->setEnabled(haveSubWindow);
    ui->actionCloseAll->setEnabled(haveSubWindow);
    ui->actionTile->setEnabled(haveSubWindow);
    ui->actionCascade->setEnabled(haveSubWindow);
    ui->actionNext->setEnabled(haveSubWindow);
    ui->actionPrevious->setEnabled(haveSubWindow);
}

