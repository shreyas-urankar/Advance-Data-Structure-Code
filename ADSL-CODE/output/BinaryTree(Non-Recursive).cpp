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
    void traverse();
    void preorder(Node *);
    void inorder(Node *);
    void postorder(Node *);
    void displayLeaf(Node *);
    int depth(Node *);
    Node* copyTree(Node *);

};

void BT::create()
{
    int userch;
    do
    {
        temp = new Node;
        cout << "Enter Data :- ";
        cin >> temp->data;
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
        cout << "Do you want to add more data :- ";
        cin >> userch;
    } while (userch != 0);
}

void BT::insert(Node *root, Node *temp)
{
    int pos;
    cout << "Current Node Is :- " << root->data << endl;
    cout << "Enter Position (1-Left / 2-Right) :- ";
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
        cout << "1-PRE-ORDER TRAVERSAL" << endl;
        cout << "2-IN-ORDER TRAVERSAL" << endl;
        cout << "3-POST-ORDER TRAVERSAL" << endl;
        cout << "0-EXIT" << endl;
        cout << "Option :- ";
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
            cout << "Exit";
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
void BT::displayLeaf(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    Node *current = root;
    Node *predecessor = NULL;

    do
    {
        if (current->left == NULL)
        {
            if (current->right == NULL)
            {
                cout << current->data << " ";
                current = current->right;
            }
            else
            {
                current = current->right;
            }
        }
        else
        {
            predecessor = current->left;

            while (predecessor->right != NULL && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                if (current->right == NULL)
                {
                    cout << current->data << " ";
                }
                current = current->right;
            }
        }
    } while (current != NULL);
}

int BT::depth(Node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }

    int depth = 0;
    Node *current = temp;

    while (current != NULL)
    {
        Node *nextLevel = current->left;
        int count = 0;

        while (nextLevel != NULL)
        {
            count++;
            nextLevel = nextLevel->left;
        }

        if (count == 0)
        {
            depth++;
            current = current->right;
        }
        else
        {
            current = current->left;
        }
    }

    return depth;
}


Node* BT::copyTree(Node *root)
{
    if (root == NULL)
    {
        return NULL;
    }

    Node* newRoot = new Node;
    newRoot->data = root->data;
    newRoot->left = NULL;
    newRoot->right = NULL;

    Node* originalCurrent = root;
    Node* copiedCurrent = newRoot;

    Node* originalPrev = NULL;
    Node* copiedPrev = NULL;
    Node* originalNext = NULL;
    Node* copiedNext = NULL;

    int count = 1;
    int nextCount = 0;

    while (originalCurrent != NULL)
    {
        if (originalCurrent->left)
        {
            copiedCurrent->left = new Node;
            copiedCurrent->left->data = originalCurrent->left->data;
            copiedNext = copiedCurrent->left;
            nextCount++;
        }

        if (originalCurrent->right)
        {
            copiedCurrent->right = new Node;
            copiedCurrent->right->data = originalCurrent->right->data;
            if (copiedNext == NULL)
            {
                copiedNext = copiedCurrent->right;
            }
            nextCount++;
        }

        originalPrev = originalCurrent;
        originalCurrent = originalCurrent->right;
        originalNext = originalCurrent ? originalCurrent->left : NULL;

        copiedPrev = copiedCurrent;
        copiedCurrent = copiedNext;

        if (--count == 0)
        {
            count = nextCount;
            nextCount = 0;
            originalCurrent = originalNext;
            copiedCurrent = copiedNext;
            copiedNext = NULL;
        }
    }

    return newRoot;
}


int main()
{
    BT p;
    int option;
    bool s = true;
    while (s)
    {
        cout << "MENU*" << endl;
        cout << "BINARY TREE" << endl;
        cout << "1-BINARY TREE CREATION" << endl;
        cout << "2-TRAVERSAL" << endl;
        cout << "3-DISPLAY LEAF NODES" << endl;
        cout << "4- Depth of a tree" << endl;
        cout << "5- Create a copy of a tree" << endl;
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
            p.displayLeaf(p.root);
            break;
        }
        case 4:{
      int treeDepth = p.depth(p.root);
    cout << "Depth of the tree: " << treeDepth << endl;
        break;
        }
        case 5:{
            Node* copy = p.copyTree(p.root);
            cout << "Copy of the tree created." << endl;
            break;
        }

        case 0:
        {
            cout << "Exit";
            s = false;
            break;
        }
      }
    }
}
