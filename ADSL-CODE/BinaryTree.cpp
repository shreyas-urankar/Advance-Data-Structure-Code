#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
};

class BT
{
public:
    node *root;
    void create();
    void insert(node *, node *);
    void traverse();
    void displayLeafNode(node *temp);
    int getHeight(node *temp);

    void preorder(node *);
    void inorder(node *);
    void postorder(node *);

    BT()
    {
        root = NULL;
    }
};

void BT::create()
{
    node *temp;
    int val, userCh;
    do
    {
        cout << "\n Enter the data:-";
        cin >> val;
        temp = new node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }
        cout << "\n Do you want to add more node (YES=1 AND NO=0):-";
        cin >> userCh;
    } while (userCh != 0);
}

void BT::insert(node *root, node *temp)
{
    int position;
    cout << "\n Current root is:-" << root->data;
    cout << "\n Enter position (Left=1 and Right=2):-";
    cin >> position;
    if (position == 1)
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
        {
            insert(root->left, temp);
        }
    }
    if (position == 2)
    {
        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
        {
            insert(root->right, temp);
        }
    }
}

void BT::traverse()
{
    int op;
    do
    {
        cout << "\n Welcome to the Binary Tree Traversal";
        cout << "\n 1. Preorder ";
        cout << "\n 2. Inorder";
        cout << "\n 3. Postorder";
        cout << "\n 4. Exit";
        cout << "\n Enter your choice:-";
        cin >> op;
        switch (op)
        {
        case 1:
            preorder(root);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            postorder(root);
            break;
        }
    } while (op != 4);
}

void BT::displayLeafNode(node *temp)
{
    if (temp->left != NULL)
    {
        displayLeafNode(temp->left);
    }
    if (temp->right != NULL)
    {
        displayLeafNode(temp->right);
    }
    if (temp->left == NULL && temp->right == NULL)
    {
        cout << root->data << " ";
    }
}

int BT::getHeight(node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        int leftHeight = getHeight(temp->left);
        int rightHeight = getHeight(temp->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

void BT::preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << "\t" << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BT::inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << "\t" << temp->data;
        inorder(temp->right);
    }
}
void BT::postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << "\t" << temp->data;
    }
}

int main()
{
    BT b;
    int ch;
    do
    {
        cout << "\n Welcome to Binary Tree";
        cout << "\n 1.Create.";
        cout << "\n 2.Traverse";
        cout << "\n 3.Leaf Node";
        cout << "\n 4.Get Height ";
        cout << "\n 5.Exit";
        cout << "\n Enter your choice:-";
        cin >> ch;
        switch (ch)
        {
        case 1:
            b.create();
            break;
        case 2:
            b.traverse();
            break;
        case 3:
            b.displayLeafNode(b.root);
            break;
        case 4:
            int height = b.getHeight(b.root);
            cout << height;
            break;
        }
    } while (ch != 5);
    return 0;
}
