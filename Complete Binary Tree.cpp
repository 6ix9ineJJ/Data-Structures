#include <iostream>
#include <list>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node() {
        data = 0;
        left = NULL;
        right = NULL;
    }
    
};


///////-----------------  Printing Tree code  -------------------///////////
struct Trunk
{
    Trunk* prev;
    string str;

    Trunk(Trunk* prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk* p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

// Recursive function to print binary tree
// It uses inorder traversal
void printTree(node* root, Trunk* prev, bool isRight)
{
    if (root == NULL)
        return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}


///////////////-------------------------------////////////////////////////



class  cbt : public node
{
    node* root;
    node* temp;
    node* lastnode;

public:

    cbt() {
        root = NULL;
        temp = NULL;
        lastnode = NULL;
    }

    inline node* get_root()
    {
        return root;
    }

    void create()
    {
        int t;
        cout << "Enter the total number of Elements : ";
        cin >> t;
        
        for (int i = 0; i < t; i++)
        {
            //creating a node to be inserted
            temp = new node;
            temp->left = NULL;
            temp->right = NULL;

            cout << "\nEnter the element : ";
            cin >> temp->data;
            lastnode = temp;

            //inserting the current node in the tree
            root = insert(root, temp);
        }
    }

    void insert(int val)
    {
        temp = new node;
        temp->left = NULL;
        temp->right = NULL;
        temp->data = val;
        lastnode = temp;
        root = insert(root, temp);
    }
                
    node* insert(node* r, node* t)
    {
        //Inserting a node in the tree
        if (r == NULL)
            return t;
        else if (bal(r) == 0 && check(r->right))  //Condition to insert node in the right sub-tree
            r->right = insert(r->right, t);
        else if (bal(r) == 0)                      //condition to insert node in the left sub-tree
            r->left = insert(r->left, t);
        else if (bal(r) == 1 && check(r->left))   //condition to insert node in the left sub-tree
            r->left = insert(r->left, t);
        else if (bal(r) == 1)
            r->right = insert(r->right, t);      //condition to insert node in right sub-tree

        return r;
    }; 


    int height(node* r)
    {
        if (r == NULL)
            return 0;
        else
        {
            int lheight = height(r->left) + 1;
            int rheight = height(r->right) + 1;

            return (lheight > rheight) ? lheight : rheight; //returns maximum height
        }
    };          //method to get height of a given node


    int bal(node* r)
    {
        if (r == NULL)
            return 0;
        int lheight = height(r->left) + 1;
        int rheight = height(r->right) + 1;

        return (lheight - rheight); //[Balance Factor = Height of Left Sub-Tree - Height of Right Sub-Tree]
    };             /*method to get the balance factor of a given node
                                [Balance Factor = Height of Left Sub-Tree - Height of Right Sub-Tree] */
    bool check(node* r)
    {
        //traversing the nodes of the subtree to check any node with balance factor > 0
        if (r == NULL)
            return false;
        bool x = check(r->left);
        if (bal(r))
            return true;
        bool y = check(r->right);

        return x || y;    //If any node present with balance factor > 0
    };         //method to check any node with balance factor > 0

    void levelOrderTraversal(node* root)
    {
        // create an empty queue and enqueue root node
        list<node*> queue;
        queue.push_back(root);

        // pointer to store current node
        node* curr = nullptr;

        // run till queue is not empty
        while (queue.size())
        {
            // process each node in queue and enqueue their
            // non-empty left and right child to queue
            curr = queue.front();
            queue.pop_front();

            cout << curr->data << "\t";

            if (curr->left)
                queue.push_back(curr->left);

            if (curr->right)
                queue.push_back(curr->right);
        }

    }

    node* find(node* nod, int value) {
        if (nod == NULL)
            return NULL;
        else if (value < nod->data)
            return find(nod->left, value);
        else if (value > nod->data)
            
            return find(nod->right, value);
        else
            return nod;
    }




    ~cbt()
    {
        delete root;
        delete temp;
    };

};


int main()
{
    cbt c;
    c.create();
    c.insert(10);
    c.insert(15);

    cout << "\n\n LEVAL ORDER \t";
    c.levelOrderTraversal(c.get_root());
    cout << "\n\n";
    
    /////////  Printing Treee   /////////////
    cout << "/------------------Displaying Tree------------------\\\n" << endl;
    printTree(c.get_root(), NULL, false);
    cout << "\n-------------------------------------------------------" << endl;
    ////-----------------------------------------////

    node* search = c.find(c.get_root(), 3);
    if (search == NULL)
        cout << "Value not found." << endl;
    else
        cout << "\n\n\n\The node having value " << search->data << " is present in the Tree.\n\n" << endl;


    return 0;
}