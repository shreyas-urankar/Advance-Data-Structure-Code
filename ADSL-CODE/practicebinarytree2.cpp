#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class BT
{
public:
    Node *root, *temp;
    BT()
    {
        root = NULL;
        temp = NULL;
    }
    void create();
    void insert(Node *, Node *);
    void display();
    void traverse();
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    void displayLeafNode(Node *);
    int getHeight(Node *);
    void mirrorTree(Node *);
};

void BT::create()
{
    int userch;
    do
    {
        temp = new Node;
        cout << "Enter the data:-";
        cin >> temp->data;
        temp->right = NULL;
        temp->left = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }
        cout << "Do you want to add more data(YES-1/NO-0):-";
        cin >> userch;
    } while (userch != 0);
}

void BT::insert(Node *root, Node *temp)
{
    int pos;
    cout << "Current Node is:-" << root->data << endl;
    cout << "Enter the position (1->left / 2->right):-";
    cin >> pos;
    if (pos == 1)
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
    else
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
    int option;
    bool a = true;
    while (a)
    {
        cout << "1-PRE-ORDER TRAVERSAL." << endl;
        cout << "2-IN-ORDER TRAVERSAL." << endl;
        cout << "3-POST-ORDER TRAVERSAL." << endl;
        cout << "0-Exit." << endl;
        cin >> option;
        switch (option)
        {
        case 1:
        {
            preorder(root);
            break;
        }
        case 2:
        {
            inorder(root);
            break;
        }
        case 3:
        {
            postorder(root);
            break;
        }
        case 0:
        {
            cout << "Exit: Visit Tree Traversal Again. Thank you." << endl;
            a = false;
            break;
        }
        }
    }
}

void BT::preorder(Node *temp)
{
    if (temp != NULL)
    {
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BT::inorder(Node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
}

void BT::postorder(Node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->data << " ";
    }
}

void BT::displayLeafNode(Node *root)
{
    if (root->left != NULL)
    {
        displayLeafNode(root->left);
    }
    if (root->right != NULL)
    {
        displayLeafNode(root->right);
    }
    if (root->right == NULL && root->left == NULL)
    {
        cout << root->data << " ";
    }
}

int BT::getHeight(Node *temp)
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

void BT::mirrorTree(Node *temp)
{
    if (temp != NULL)
    {
        Node *tmp = temp->left;
        temp->left = temp->right;
        temp->right = tmp;
        mirrorTree(temp->left);
        mirrorTree(temp->right);
    }
}

int main()
{
    BT p;
    int option;
    bool s = true;
    while (s)
    {
        cout << "*MENU" << endl;
        cout << "BINARY TREE" << endl;
        cout << "1-BINARY TREE CREATION" << endl;
        cout << "2-TRAVERSAL" << endl;
        cout << "3-DISPLAY LEAF NODES" << endl;
        cout << "4-FIND HEIGHT OF TREE" << endl;
        cout << "5-MIRROR TREE" << endl;
        cout << "0-EXIT" << endl;
        cout << "*" << endl;
        cout << "Option :- ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            p.create();
            break;
        }
        case 2:
        {
            p.traverse();
            break;
        }
        case 3:
        {
            p.displayLeafNode(p.root);
            break;
        }
        case 4:
        {
            int height = p.getHeight(p.root);
            cout << "Height of the tree: " << height << endl;
            break;
        }
        case 5:
        {
            p.mirrorTree(p.root);
            cout << "Mirror tree created." << endl;
            break;
        }
        case 0:
        {
            cout << "Exit" << endl;
            s = false;
            break;
        }
        }
    }
    return 0;
}
