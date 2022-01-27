#include <iostream>
using namespace std;

class Node{
public:
    Node* left;
    Node* right;

    int value;
    int height;

    Node(int value)
    {
        this->value = value;
        left = right = NULL;
        height = 1;
    }
};


class AVL
{
    
public:

    int getHeight(Node* node)
    {
        if (node == NULL)
            return 0;

        return node->height;
    }


    Node* updateHeight(Node* node)
    {
        
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        return node;
    }


    Node* insert(Node* root, int value)
    {
        if (root == NULL)
            return new Node(value);

        if (root->value < value)
            root->right = insert(root->right, value);
        else if (root->value == value)
        {
            cout << "value: " << value << " No duplicate vertex allowed." << endl;
            return root;
        }
        else
            root->left = insert(root->left, value);

        root = updateHeight(root);

        int balance_factor = getHeight(root->left) - getHeight(root->right);

        // LR rotation
        if (balance_factor > 1 && root->left->value < value)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        // RR rotation
        else if (balance_factor > 1 && root->left->value > value)
            return rightRotate(root);
        // LL rotation
        else if (balance_factor < -1 && root->right->value < value)
            return leftRotate(root);
        // RL rotation
        else if (balance_factor < -1 && root->right->value > value)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    Node* leftRotate(Node* root)
    {
        Node* x = root->right;
        Node* t = x->left;

        root->right = t;
        x->left = root;

        // update height
        x = updateHeight(x);
        root = updateHeight(root);

        return x;
    }
    Node* rightRotate(Node* root)
    {
        Node* x = root->left;
        Node* t = x->right;

        root->left = t;
        x->right = root;

        // update height
        root = updateHeight(root);
        x = updateHeight(x);

        return x;
    }
    void printAll(Node* root)
    {
        if (root->left != NULL)
            printAll(root->left);

        cout << root->value << " ";

        if (root->right != NULL)
            printAll(root->right);
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
            return b;
    }
};
int main()
{
    AVL avl;
    Node* root = NULL;

    root = avl.insert(root, 10);
    root = avl.insert(root, 20);
    root = avl.insert(root, 30);
    root = avl.insert(root, 40);
    root = avl.insert(root, 50);
    root = avl.insert(root, 25);

    avl.printAll(root);

    return 0;
}