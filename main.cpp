#include <QApplication>
#include <QDebug>

#include "treemodel.h"
#include <QTreeView>

#include <QProcess>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TreeModel model;
    QTreeView view;
    view.setModel(&model);
    view.show();
    return a.exec();
}




