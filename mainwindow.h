#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ProcessInfo/ProcessInfo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ProcessInfo m_top;

    QString m_arguments;

    // utility funciton used by display()
    void constructArguments();

    // this function is called when "OK" is clicked
    void display() noexcept(false);
};
#endif // MAINWINDOW_H
