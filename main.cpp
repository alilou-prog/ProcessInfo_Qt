#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include <stdexcept>
#include "ProcessInfo/ProcessInfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
