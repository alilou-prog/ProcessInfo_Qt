#include <QApplication>
#include <QDebug>

#include "treemodel.h"
#include <QTreeView>

#include <QProcess>
#include <iostream>
#include "ProcessInfo/SystemAnalyser.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TreeModel model;
    QTreeView view;
    view.setModel(&model);
    view.show();
    return a.exec();
}




