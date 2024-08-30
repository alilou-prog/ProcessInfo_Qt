#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <stdexcept>

#include "treemodel.h"
#include <QTreeView>

#include "ProcessInfo/ProcessInfo.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    TreeModel model;
    QTreeView view;
    view.setModel(&model);
    view.show();
    return a.exec();
}
