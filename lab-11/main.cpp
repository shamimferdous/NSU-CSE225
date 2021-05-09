#include <iostream>
#include <algorithm>

using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *CreateNewNode(int data) //will help to print the best insertion order
{
    struct bstNode *temp = new bstNode;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    cout << data << " ";

    return temp;
}

//defining Insert function
bstNode *Insert(bstNode *root, int value)
{
    if (root == NULL)
    {
        struct bstNode *temp = new bstNode;
        temp->data = value;
        temp->left = temp->right = NULL;

        return temp;
    }

    if (value < root->data)
    {
        root->left = Insert(root->left, value);
    }
    else
    {
        root->right = Insert(root->right, value);
    }

    return root;
}

//defining Search function
bool Search(bstNode *root, int value)
{
    struct bstNode *temp = root;

    while (temp->data != value)
    {

        if (temp != NULL)
        {

            if (temp->data > value)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }

            if (temp == NULL)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

//defining FindMin function
bstNode *FindMin(bstNode *root)
{
    struct bstNode *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp;
}

//defining FindMax function
bstNode *FindMax(bstNode *root)
{
    struct bstNode *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

//defining FindHeight function
int FindHeight(bstNode *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int rightSTDepth = FindHeight(root->right);
        int leftSTDepth = FindHeight(root->left);

        if (rightSTDepth > leftSTDepth)
        {
            return (leftSTDepth + 1);
        }
        else
        {
            return (rightSTDepth + 1);
        }
    }
}

//defining PreOrder function
void PreOrder(struct bstNode *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

//defining InOrder function
void InOrder(struct bstNode *root)
{
    if (root != NULL)
    {
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

//defining InOrder function
void PostOrder(struct bstNode *root)
{
    if (root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}

//defining Delete function
bstNode *Delete(bstNode *root, int value)
{

    if (value < root->data)
        root->left = Delete(root->left, value);

    else if (value > root->data)
        root->right = Delete(root->right, value);

    else
    {
        if (root->left == NULL)
        {
            struct bstNode *temp = root->right;
            return temp;
        }
        else if (root->right == NULL)
        {
            struct bstNode *temp = root->left;
            return temp;
        }

        struct bstNode *temp = FindMin(root->right);

        root->data = temp->data;

        root->right = Delete(root->right, temp->data);
    }

    return root;
}

//defining CountNumberOfNodes function
int CountNumberOfNodes(bstNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return CountNumberOfNodes(root->left) + CountNumberOfNodes(root->right) + 1;
    }
}

//defining InOrderSuccessor function
void InOrderSuccessor(bstNode *root, bstNode *&successor, int value)
{
    if (root == NULL)
    {
        successor = NULL;
        return;
    }

    if (root->data == value)
    {
        if (root->right)
        {
            successor = FindMin(root->right);
        }
    }
    else if (value < root->data)
    {
        successor = root;
        InOrderSuccessor(root->left, successor, value);
    }
    else
    {
        InOrderSuccessor(root->right, successor, value);
    }
}

//defining BestInsertionOrder function
bstNode *BestInsertionOrder(int treeElems[], int head, int tail)
{

    if (head > tail)
    {
        return NULL;
    }

    int rootElem = (head + tail) / 2;

    struct bstNode *root = CreateNewNode(treeElems[rootElem]);

    root->left = BestInsertionOrder(treeElems, head, rootElem - 1);
    root->right = BestInsertionOrder(treeElems, rootElem + 1, tail);

    return root;
}

int main()
{
    struct bstNode *root = NULL;

    //inserting keys in bst
    root = Insert(root, 11);
    root = Insert(root, 9);
    root = Insert(root, 4);
    root = Insert(root, 2);
    root = Insert(root, 7);
    root = Insert(root, 3);
    root = Insert(root, 17);
    root = Insert(root, 0);
    root = Insert(root, 5);
    root = Insert(root, 1);

    //searching in BST
    bool isFound;
    isFound = Search(root, 10);
    if (isFound)
    {
        cout << "Item Was Found!" << endl;
    }
    else
    {
        cout << "Item Was not found!" << endl;
    }

    //finding minimum key
    struct bstNode *min = FindMin(root);
    cout << "Minimum value: " << min->data << endl;

    struct bstNode *max = FindMax(root);
    cout << "Maximum value: " << max->data << endl;

    cout << "Height of the tree: " << FindHeight(root) << endl;

    cout << "InOrder Traversal: " << endl;
    InOrder(root);
    cout << endl;

    cout << "PreOrder Traversal: " << endl;
    PreOrder(root);
    cout << endl;

    cout << "PostOrder Traversal: " << endl;
    PostOrder(root);
    cout << endl;

    cout << "Number of nodes in BST: " << CountNumberOfNodes(root) << endl;

    cout << "Deleted an item" << endl;
    struct bstNode *deletedItem = Delete(root, 1);

    cout << "Number of nodes in BST: " << CountNumberOfNodes(root) << endl;

    struct bstNode *successor;
    InOrderSuccessor(root, successor, 3);

    if (successor)
    {
        cout << "InOrder Successor of 3 is: " << successor->data;
    }
    else
    {
        cout << "Successor not found!" << endl;
    }

    //finding best insertion order
    int treeElems[] = {11,
                       9,
                       4,
                       2,
                       7,
                       3,
                       17,
                       0,
                       5,
                       1};

    int treeElemsLength = sizeof(treeElems) / sizeof(treeElems[0]);
    sort(treeElems, treeElems + treeElemsLength);

    cout << endl;
    cout << "Best insertion order for 11 9 4 2 7 3 17 0 5 1 - " << endl;
    struct bstNode *tree = BestInsertionOrder(treeElems, 0, treeElemsLength - 1);

    return 0;
}