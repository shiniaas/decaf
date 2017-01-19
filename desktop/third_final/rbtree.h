#include <iostream>
#include <stack>
#include <cstdlib>
#define INF 0x7FFFFFFF
using namespace std;

enum COLOR {RED, BLACK};
enum Object {GLOBAL, CLASS, FORMAL, LOCAL};

struct TreeNode {
    int key;
    char* name;
    enum Object Otype;
    char* type;
    TreeNode *parent;
    TreeNode *left, *right;
    
    COLOR color;
    
    TreeNode& operator = (TreeNode& node)  //Reload the "=" for assignment
    {
        this->key = node.key;
        this->parent = node.parent;
        this->left = node.left;
        this->right = node.right;
        this->color = node.color;
        return *this;
    }
};

TreeNode NULL_NODE = {INF,nullptr,GLOBAL,nullptr,nullptr,nullptr,nullptr,BLACK};

class Red_Black_Tree
{
private:
    TreeNode * root;
    int _size;
    TreeNode * NIL;
    
    void Left_Rotate(TreeNode *x);
    void Right_Rotate(TreeNode *x);
    
    //Insertion or deletion may cause red-black tree's quality destroyed
    //So we just try to fix it by this two options.
    void RB_Insert_FixUp(TreeNode *z);
    void RB_Delete_FixUp(TreeNode *z);
    
    void Transplant(TreeNode * u, TreeNode * v);
    
    TreeNode * Tree_Minimum(TreeNode * root);
    TreeNode * Tree_Maximum(TreeNode * root);
    
public:
    Red_Black_Tree() { _size = 0; NIL = &NULL_NODE; root = &NULL_NODE;}
    
    void RBTree_Insert(int _key);
    bool RBTree_Delete(int _key);
    
    void Preorder_Traversal();
    TreeNode * Find(int _key);
};
/**
 * Left rotate the subtree
 * @param x : The root of the subtree to be rotated
 */
void Red_Black_Tree::Left_Rotate(TreeNode *x)
{
    if(x->right == NIL)
        return;
    
    TreeNode * y = x->right;    //Set y
    x->right = y->left;     //Turn y's left subtree into x's subtree
    
    if(y->left!=NIL)
    {
        y->left->parent = x;
    }
    
    y->parent = x->parent;  //Link x's parent to y
    
    if(x->parent == NIL)
    {
        root = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    
    y->left = x;    //Put x on y's left
    x->parent = y;
}
/**
 * Right rotate the subtree
 * Symmetry with the function "Left Rotate" above.
 * @param x : The root of the subtree to be rotated
 */
void Red_Black_Tree::Right_Rotate(TreeNode *y)
{
    if(y->left == NIL)
        return;
    
    TreeNode *x = y->left;
    y->left = x->right;
    
    if(x->right != nullptr)
    {
        x->right->parent = y;
    }
    
    x->parent = y->parent;
    
    if(y->parent == NIL)
    {
        root = x;
    }
    else if(y == y->parent->left)
    {
        y->parent->left = x;
    }
    else
    {
        y->parent->right = x;
    }
    
    x->right = y;
    y->parent = x;
}
/**
 * Transplant the subtree u with the subtree v
 */
void Red_Black_Tree::Transplant(TreeNode * u, TreeNode * v)
{
    if(u->parent == NIL)
    {
        root = v;
    }
    else if(u == u->parent->left)
    {
        u->parent->left = v;
    }
    else
    {
        u->parent->right = v;
    }
    
    v->parent = u->parent;
}
/**
 * Find a node whose key value equals to "_key"
 * @param  _key : The key value
 * @return      : If the node exists, return the node. Else, return the NULL_NODE.
 */
TreeNode * Red_Black_Tree::Find(/*TreeNode * root,*/ int _key)  //The circulation version of Search
{
    TreeNode * p = root;
    
    while(p != NIL && p->key!=_key)
    {
        if(p->key > _key)
            p = p->left;
        else
            p = p->right;
    }
    return p;
}

//Get the minimum key in x's posterity and return the pointer to that node
TreeNode * Red_Black_Tree::Tree_Minimum(TreeNode * root)
{
    TreeNode * p = root;
    
    while(p->left != NIL)
    {
        p = p->left;
    }
    return p;
}

//Get the maximum key in x's posterity and return the pointer to that node
TreeNode * Red_Black_Tree::Tree_Maximum(TreeNode * root)
{
    TreeNode * p = root;
    
    while(p->right != NIL)
    {
        p = p->right;
    }
    return p;
}

void Red_Black_Tree::Preorder_Traversal(/*TreeNode * root */)   //The circulation version of Preorder Traversal
{
    cout<<"Preorder Traversal : ";
    stack<TreeNode *> TreeNode_Stack;
    TreeNode * p = root;
    
    while(p!=NIL || !TreeNode_Stack.empty())
    {
        while(p!=NIL)
        {
            TreeNode_Stack.push(p);
            cout<<p->key<<" ";
            if(p->color==BLACK)
                cout<<"BLACK ";
            else
                cout<<"RED ";
            p = p->left;
        }
        if(!TreeNode_Stack.empty())
        {
            p = TreeNode_Stack.top();
            TreeNode_Stack.pop();
            p = p->right;
        }
    }
    cout<<endl;
}
void Red_Black_Tree::RBTree_Insert(int _key)
{
    TreeNode * z = new TreeNode;
    z->key = _key;
    z->color = RED;
    z->left = z->right = NIL;
    
    TreeNode *y = NIL;
    TreeNode *x = root;
    
    while(x != NIL)
    {
        y = x;
        if(_key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    
    z->parent = y;
    if(y == NIL)
    {
        root = z;
    }
    else if(z->key < y->key)
    {
        y->left = z;
    }
    else
    {
        y->right = z;
    }
    
    RB_Insert_FixUp(z);
}
/**
 * Fix the double-red bug in this tree
 * @param z : a node which was just inserted
 */
void Red_Black_Tree::RB_Insert_FixUp(TreeNode *z)
{
    while(z->parent->color == RED)
    {
        if(z->parent == z->parent->parent->left)
        {
            TreeNode * y = z->parent->parent->right;
            if(y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->right)
                {
                    z = z->parent;
                    Left_Rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                Right_Rotate(z->parent->parent);
            }
        }
        else
        {
            TreeNode * y = z->parent->parent->left;
            if(y->color == RED)
            {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            }
            else
            {
                if(z == z->parent->left)
                {
                    z = z->parent;
                    Right_Rotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                Left_Rotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}
/**
 * Delete a node from the RB-Tree
 * @param  _key : The key value of the node which is to deleted
 * @return      : True for succeed, and false for no such node existed.
 */
bool Red_Black_Tree::RBTree_Delete(int _key)
{
    TreeNode *z = Find(_key);
    if(z == NIL)
    {
        cout<<"Error : No node valued "<<_key<<" !"<<endl;
        return false;
    }
    
    TreeNode *y = z;
    COLOR y_original_color = y->color;
    
    TreeNode *x;
    if(z->left == NIL)
    {
        x = z->right;
        Transplant(z,z->right);
    }
    else if(z->right == NIL)
    {
        x = z->left;
        Transplant(z,z->left);
    }
    else
    {
        y = Tree_Minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if(y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            Transplant(y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        Transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_original_color == BLACK)
        RB_Delete_FixUp(x);
    
    delete z;
    return true;
}
/**
 * Delete a node may cause Black-Height changed, and this function is to fix this bug.
 * @param x : The place where the substitude node used to be
 */
void Red_Black_Tree::RB_Delete_FixUp(TreeNode *x)
{
    while(x!=root && x->color == BLACK)
    {
        if(x == x->parent->left)
        {
            TreeNode *w = x->parent->right;
            if(w->color == RED)
            {
                w->color = BLACK;
                w->parent->color = RED;
                Right_Rotate(w);
                w = x->parent->right;
            }
            
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if(w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    Right_Rotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                Left_Rotate(x->parent);
                x = root;
            }
        }
        else
        {
            TreeNode *w = x->parent->left;
            if(w->color == RED)
            {
                w->color = BLACK;
                w->parent->color = RED;
                Left_Rotate(w);
                w = x->parent->left;
            }
            
            if(w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if(w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    Left_Rotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                Right_Rotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}
