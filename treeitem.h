#ifndef TREEITEM_H
#define TREEITEM_H

#include <memory>
#include <QVariant>
#include <vector>

class Tree;

class TreeItem
{
    friend class Tree;

public:
    explicit TreeItem(QVariantList data, TreeItem *parentItem = nullptr);

    void appendChild(std::unique_ptr<TreeItem> &&child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    QVariantList allData() const;
    int row() const;
    TreeItem *parentItem();

private:
    std::vector<std::unique_ptr<TreeItem>> m_childItems;
    QVariantList m_itemData;
    TreeItem *m_parentItem;
};

#endif // TREEITEM_H
