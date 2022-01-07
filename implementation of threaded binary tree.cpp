#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    int leftBit, rightBit;  /*  1 = child ||  0 = thread */
};

class ThreadedBinarySearchTree
{
    public:
        Node *root, *temp, *temp1;

        // Threaded Binary Search Tree

        Node *dummy;        // Dummy -> data = -1

        ThreadedBinarySearchTree()
        {
            root = NULL;

            dummy = new Node;

            dummy -> data = -1;

            dummy -> right = dummy;
            dummy -> rightBit = 1;

            dummy -> left = dummy;
            dummy -> leftBit = 0;
        }
        
        void insert( int key, Node *& temp)
        {
                
            if ( root == NULL)
            {   
                root = new Node;
                dummy -> left = root;
                dummy -> leftBit = 1;

                root -> left = dummy;
                root -> leftBit = 0;
                    
                root -> right = dummy;
                root -> rightBit = 0;

                root -> data = key;
                
                return;
            }

            if ( key == temp -> data)
            {
                cout << "\nDuplicate value." << endl;
                return;
            }

            if ( key > temp -> data)
            {
                if ( temp -> rightBit == 0)
                {
                    temp1 = new Node;
                    temp1 -> data = key;
                    
                    temp1 -> right = temp -> right;
                    temp1 -> rightBit = temp -> rightBit;

                    temp -> right = temp1;
                    temp -> rightBit = 1;

                    temp1 -> left = temp;
                    temp1 -> leftBit = 0;

                    return;
                }
                insert ( key, temp -> right);
            }

            if ( key < temp -> data)
            {
                if ( temp -> leftBit == 0)
                {
                    temp1 = new Node;
                    temp1 -> data = key;
                    
                    temp1 -> left = temp -> left;
                    temp1 -> leftBit = temp -> leftBit;

                    temp -> left = temp1;
                    temp -> leftBit = 1;

                    temp1 -> right = temp;
                    temp1 -> rightBit = 0;

                    return;
                }
                insert ( key, temp -> left);
            }
        }

        Node * search( int key, Node *& temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return NULL;
            }

            if ( temp -> data == key)
            {
                return temp;
            }

            if ( ( temp -> right != NULL) && ( key > temp -> data))
            {
                return search( key, temp -> right);
                
            }

            if ( ( temp -> left != NULL) && ( key < temp -> data))
            {
                return search( key, temp -> left);
            }

            if ( temp -> left == NULL && temp -> right == NULL)
            {
                cout << "\nData not found." << endl;
                return NULL;
            }
        }

        Node * find_successor( Node * temp, Node *& parent)
        {
            if ( temp -> leftBit == 0)
                return temp;
            
            parent = temp;
            return find_successor( temp -> left, parent);
        }

        void delete_Node( Node * temp, Node * parent)
        {
            if ( temp -> leftBit == 1 && temp -> rightBit == 1)
            {
                Node * successor_parent = temp;
                Node * successor = find_successor( temp -> right, successor_parent);

                temp -> data = successor -> data;
                delete_Node( successor, successor_parent);
                return;
            }

            if ( temp -> leftBit == 1 && temp -> rightBit == 0)
            {
                if ( temp -> data < parent -> data)
                {
                    parent -> left = temp -> left;
                    parent -> leftBit = temp -> leftBit;
                }

                else
                {
                    parent -> right = temp -> left;
                    parent -> rightBit = temp -> leftBit;
                }

                Node * temp2 = temp -> left;

                while ( temp2 -> rightBit != 0)
                    temp2 = temp2 -> right;

                temp2 -> right = temp -> right;

                delete temp;
                return;
            }

            if ( temp -> leftBit == 0 && temp -> rightBit == 1)
            {
                if ( temp -> data > parent -> data)
                {
                    parent -> right = temp -> right;
                    parent -> rightBit = temp -> rightBit;
                }

                else
                {
                    parent -> left = temp -> right;
                    parent -> leftBit = temp -> rightBit;
                }

                Node * temp2 = temp -> right;

                while ( temp2 -> leftBit != 0)
                    temp2 = temp2 -> left;

                temp2 -> left = temp -> left;

                delete temp;
                return;
            }

            if ( temp -> leftBit == 0 && temp -> rightBit == 0)
            {
                if ( parent -> left == temp)
                {
                    parent -> left = temp -> left;
                    parent -> leftBit = 0;
                }
            
                if ( parent -> right == temp && parent != dummy)
                {
                    parent -> right = temp -> right;
                    parent -> rightBit = 0;
                }

                if ( temp == root)
                {
                    root = NULL;
                    dummy -> left = dummy;
                    dummy -> leftBit = 0;
                }
                delete temp;
            }
        }

        void remove( int key, Node * temp)
        {
            if ( root == NULL)
            {
                cout << "\nTree is empty." << endl;
                return;
            }

            if ( temp -> left ->  data == key)
            {
                delete_Node( temp -> left, temp);
                return;
            }

            if ( ( temp != dummy) && ( temp -> right -> data == key))
            {
                delete_Node( temp -> right, temp);
                return;
            }

            if ( temp == dummy)
            {
                remove( key, temp -> left);
                return;
            }

            if ( ( key > temp -> data) && ( temp -> rightBit == 1))
            {
                remove( key, temp -> right);
                return;
            }

            cout << "\nValue does not exist." << endl;
            return;
        }

        void print_inorder()
        {
            temp = root;

            while ( temp -> left != dummy)
            {
                temp = temp -> left;
            }


            while ( temp != dummy)
            {
                cout << temp -> data << "\t";

                if ( temp -> rightBit == 0)
                    temp = temp -> right;

                else
                {
                    temp = temp -> right;
                    while ( temp -> leftBit == 1)
                        temp = temp -> left;
                }
            }
        }
};

int main()
{
    ThreadedBinarySearchTree tree;

    tree.insert( 6,  tree.root);
    tree.insert( 3,  tree.root);
    tree.insert( 8,  tree.root);
    tree.insert( 1,  tree.root);
    tree.insert( 5,  tree.root);
    tree.insert( 7,  tree.root);
    tree.insert( 11, tree.root);
    tree.insert( 9,  tree.root);
    tree.insert( 13, tree.root);

    //tree.print_inorder( tree.root);

    ThreadedBinarySearchTree tree2;

    tree2.insert( 100, tree2.root);
    tree2.insert( 150, tree2.root);
    tree2.insert( 180, tree2.root);
    tree2.insert( 170, tree2.root);
    tree2.insert( 190, tree2.root);

    tree2.print_inorder();

    cout << endl;

    tree2.remove( 150, tree2.dummy);

    cout << tree2.root -> right -> left -> data;
}
