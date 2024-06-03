#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
};

class BST
{
public:
    int val;
    node *temp;
    node *root;
    node *mirrorRoot;
    void create();
    void traverse();
    void insert(node *, node *);
    void preorder(node *);
    void postorder(node *);
    void inorder(node *);
    int getHeight(node *);
    void mirrorTree(node *);
    int depth(node *);
    void displayLeafNode(node *);
    void displayMirrorTree(node *);

    BST()
    {
        root = NULL;
        temp = NULL;
        mirrorRoot = NULL;
    }
};

void BST::create()
{
    int val;
    int userCh;
    do
    {
        temp = new node;
        cout << "\nEnter the data:-";
        cin >> val;
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
        cout << "\nDo you want to add more node(s) (YES=1 and NO=0):-";
        cin >> userCh;
    } while (userCh != 0);
}

void BST::insert(node *root, node *temp)
{
    if (root->data > temp->data)
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

void BST::traverse()
{
    int option;
    do
    {
        cout << "\nWelcome to the traversing of Binary Search Tree.";
        cout << "\n1) Preorder.";
        cout << "\n2) Inorder.";
        cout << "\n3) Postorder.";
        cout << "\n4) Exit the traverse.";
        cout << "\nEnter the option you want to perform:-";
        cin >> option;
        switch (option)
        {
        case 1:
            cout << "\nPreorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 2:
            cout << "\nInorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "\nPostorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        }
    } while (option != 4);
}


void BST::preorder(node *temp)
{
    if (temp != NULL)
    {
        cout << "\t" << temp->data;
        preorder(temp->left);
        preorder(temp->right);
    }
}

void BST::inorder(node *temp)
{

    if (temp != NULL)
    {
        inorder(temp->left);
        cout << "\t" << temp->data;
        inorder(temp->right);
    }
}

void BST::postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        cout << "\t" << temp->data;
    }
}

int BST::getHeight(node *temp)
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

void BST::displayLeafNode(node *temp)
{
    if (temp != NULL)
    {
        if (temp->left == NULL && temp->right == NULL)
        {
            cout << temp->data<<" ";
        }
        displayLeafNode(temp->left);
        displayLeafNode(temp->right);
    }
}

void BST::mirrorTree(node *temp)
{
    if (temp != NULL)
    {
        node *tempNode = temp->left;
        temp->left = temp->right;
        temp->right = tempNode;
        mirrorTree(temp->left);
        mirrorTree(temp->right);
    }
}

int BST::depth(node *temp)
{
    if (temp == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = depth(temp->left);
        int rightDepth = depth(temp->right);
        if (leftDepth > rightDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
    }
}


int main()
{
    int option;
    BST b;
    do
    {
        cout << "\nWelcome to the Binary Search Tree.";
        cout << "\n1) Create BST.";
        cout << "\n2) Traverse BST.";
        cout << "\n3) Display Leaf Node of BST.";
        cout << "\n4) Find height of BST.";
        cout << "\n5) Mirror of BST.";
        cout << "\n6) Depth of BST.";
        cout << "\n7) Exit the BST.";
        cout << "\n......................................";
        cout << "\nEnter any one of the operation you want to perform:- ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            b.create();
            break;
        }
        case 2:
        {
            b.traverse();
            break;
        }
        case 3:
        {
            cout << "\nLeaf Node of this Binary Search Tree is:-";
            b.displayLeafNode(b.root);
            cout<<endl;
            break;
        }
        case 4:
        {
            int height = b.getHeight(b.root);
            cout << "Height of this Binary Search Tree:- " << height << endl;
            break;
        }
        case 5:
        {
            b.mirrorTree(b.root);
            cout << "Mirror tree created." << endl;
            break;
        }
        
        case 6:
        {
            int treeDepth = b.depth(b.root);
            cout << "Depth of the tree: " << treeDepth << endl;
            break;
        }
        }
    } while (option != 7);
    return 0;
}
