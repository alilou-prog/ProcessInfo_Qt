#include "treemodel.h"
#include <string>
#include "ProcessInfo/SystemAnalyser.h"


using namespace std;


TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    setupModelData();
}


QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    return QVariant(QString::fromLatin1("EMPTY"));
    // return orientation == Qt::Horizontal && role == Qt::DisplayRole
    //            ? rootItem->data(section) : QString{};
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    // if it is root, it has no index ==> default-value
    if (!hasIndex(row, column, parent))
        return {};

    // get a pointer to the parent
    TreeItem *parentItem = parent.isValid()
                               ? static_cast<TreeItem*>(parent.internalPointer())
                               : tree.root;

    // get a pointer to the child. If it exists, call createIndex() with : row, column and childItem
    if (auto *childItem = parentItem->child(row))
        return createIndex(row, column, childItem);
    // otherwise return default ModelIndex
    return {};
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return {};
    // get internal pointer of this Item, then get parent pointer using parentItem()
    auto *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    return parentItem != tree.root
               ? createIndex(parentItem->row(), 0, parentItem) : QModelIndex{};
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (parent.column() > 0)
        return 0;

    const TreeItem *parentItem = parent.isValid()
                                     ? static_cast<const TreeItem*>(parent.internalPointer())
                                     : tree.root;
    // row count is child count
    return parentItem->childCount();
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    return tree.root->columnCount();
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


// ################ LOCAL FUNCTIONS

// split a string into a vector according to a given delimiter
void split(string &str, vector<string> &tokens, const string &delimiter = " ")
{
    size_t pos {0};
    string token;

    while( (pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0,pos);
        tokens.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    // the last token
    tokens.push_back(str);
}

// count the number of indentation for a string and remove it
// here indentation will be two spaces "  "
// this help us to determine hierarchy level
int indentationCount(string& str, const string &indentation)
{
    size_t pos{0};
    int indentationNum{0};

    while( (pos = str.find(indentation)) != string::npos)
    {
        ++indentationNum;
        str.erase(0, pos + indentation.length());
    }

    return indentationNum;
}

// store the splitted output in a GeneralTree
void storeInTree(vector<string> &tokens, Tree &tree)
{
    // indentation is two spaces
    const string indentation = "  ";
    // track the last token (line) because it could be a parent
    //  if we enter a new level of hierarchy
    string lastToken{""};

    // this table is used to store the parents' data
    // the index of each element indicates the level of its children
    //  in the hierachy
    string parentsData[10]{}; // assume 10 level of hierarchy as a max

    // we use these two vars to detect if we enter a new level
    //  of hierarchy
    int currentIndentationCount {0}, newIndentationCount;

    for (auto &&str : tokens)
    {
        // remove indentation and get its count
        newIndentationCount = indentationCount(str, indentation);

        // if we detect that we entered a new higher level of hierarchy
        //  (depth), we set the parentData with the corresponding index
        // index = hierarchy/depth level

        if(newIndentationCount > currentIndentationCount) // either + or -
        {
            parentsData[newIndentationCount] = lastToken;
            currentIndentationCount = newIndentationCount; // update
        }

        // insert in the tree
        // convert from std::string to QString to initialize QStringList
        QVariantList childData = {QString::fromStdString(str)};
        QVariantList parentData = {QString::fromStdString( parentsData[currentIndentationCount] )};

        tree.insert(childData, parentData);

        // update lastToken
        lastToken = str;
    }
}

// ################ LOCAL FUNCTIONS

void TreeModel::setupModelData()
{
    SystemAnalyser top;
    // execute ps specifying comm attribute and --forest option
    const string command = "ps -eo comm -H";
    top.RunCommand(command.data());

    // store the output in a local string
    string output {top.output()};

    // split the output into lines in a vector
    std::vector <string> lines;
    split(output, lines, "\n");

    // now storing in the tree
    storeInTree(lines, tree);
}
