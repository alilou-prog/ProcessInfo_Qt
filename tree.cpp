#include <vector>
#include <stdexcept>

#include "tree.h"
#include "treeitem.h"

using namespace std;

Tree::Tree() :root{nullptr} {}

Tree::~Tree() {}

void Tree::insert(const QVariantList &newData, const QVariantList &parentData)
{
    // if root is not set, set it first !
    if(root == nullptr)
    {
        auto newPtr = getNewItem(newData);
        root = newPtr;
        return;
    }

    // insert under root
    if (parentData == QVariantList{QString::fromLatin1("")}) {
        auto newPtr = getNewItem(newData);
        newPtr->m_parentItem = root;
        root->appendChild(std::unique_ptr <TreeItem>{newPtr});
        return;
    }

    auto parentPtr = search(parentData);
    if(parentPtr != nullptr)
    {
        auto newPtr = getNewItem(newData);
        newPtr->m_parentItem = parentPtr;
        parentPtr->appendChild(std::unique_ptr <TreeItem>{newPtr});
        return;
    }

    throw std::invalid_argument("invalid parentItem Data");
}

TreeItem *Tree::search(const QVariantList &data)
{
    return searchHelper(data,root);
}

TreeItem *Tree::searchHelper(const QVariantList &data, TreeItem *nodePtr)
{
    if(nodePtr != nullptr)
    {
        if (nodePtr->allData() == data)
            return nodePtr;

        std::vector <TreeItem *> subTreesResults;
        for(auto &&ptr : nodePtr->m_childItems)
        {
            subTreesResults.push_back( searchHelper(data, ptr.get()) );
        }

        for(auto &&resultPtr : subTreesResults)
        {
            if(resultPtr != nullptr)
                return resultPtr;
        }

        return nullptr;
    }

    return nullptr;
}

TreeItem *Tree::getNewItem(const QVariantList &data) const
{
    return new TreeItem (data);
}
