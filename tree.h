#ifndef TREE_H
#define TREE_H

// #include "treeitem.h"
#include <QVariant>

class TreeModel;
class TreeItem;


class Tree
{
    friend class TreeModel;
public:
    Tree();
    ~Tree();
    void insert(QVariantList newData, QVariantList parentData = {});

private:
    TreeItem *root;

    TreeItem *search(QVariantList data);

    TreeItem *searchHelper(QVariantList data, TreeItem *);

    TreeItem *getNewItem(QVariantList) const;
};

#endif // TREE_H
