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
    void insert(const QVariantList &newData, const QVariantList &parentData = {});

private:
    TreeItem *root;

    TreeItem *search(const QVariantList &data);

    TreeItem *searchHelper(const QVariantList &data, TreeItem *);

    TreeItem *getNewItem(const QVariantList &) const;
};

#endif // TREE_H
