#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "textedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();

private:
    Ui::MainWindow *ui;

    void initFontSize();
    void initScrollBar();
    TextEdit* activateWindow();
    void initDocAction();

private slots:
    void initWindowAction();
};
#endif // MAINWINDOW_H
