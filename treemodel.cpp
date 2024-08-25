#include "treemodel.h"

TreeModel::TreeModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
    , rootItem(std::make_unique<TreeItem>(QVariantList{tr("PID"), tr("COMM")}))
{
    setupModelData(QStringView{data}.split(u'\n'), rootItem.get());
}


QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    return orientation == Qt::Horizontal && role == Qt::DisplayRole
               ? rootItem->data(section) : QVariant{};
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    // if it is root, it has no index ==> default-value
    if (!hasIndex(row, column, parent))
        return {};

    // get a pointer to the parent
    TreeItem *parentItem = parent.isValid()
                               ? static_cast<TreeItem*>(parent.internalPointer())
                               : rootItem.get();
    // get a pointer to the child. If it exists, call createIndex() with : row, column and childItem
    if (auto *childItem = parentItem->child(row))
        return createIndex(row, column, childItem);
    return {}; // satisfy the compiler
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return {};
    // get internal pointer of this Item, then get parent pointer using parentItem()
    auto *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    return parentItem != rootItem.get()
               ? createIndex(parentItem->row(), 0, parentItem) : QModelIndex{};
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;

    const TreeItem *parentItem = parent.isValid()
                                     ? static_cast<const TreeItem*>(parent.internalPointer())
                                     : rootItem.get();
    // row count is child count
    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return {};

    const auto *item = static_cast<const TreeItem*>(index.internalPointer());
    return item->data(index.column());
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    return index.isValid()
    ? QAbstractItemModel::flags(index) : Qt::ItemFlags(Qt::NoItemFlags);
}


// ############################
// ## SETTING UP THE MODEL DATA
// ############################

void TreeModel::setupModelData(const QList<QStringView> &lines, TreeItem *parent)
{

}
