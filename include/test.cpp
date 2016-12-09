#include "rbtree.h"
int main()
{
    Red_Black_Tree RBTree;
    string _arr[] = {"1","2","3","4","5","6","7","8"};
    for(int i=0; i<8; i++)
    {
        RBTree.RBTree_Insert(_arr[i], VARIABLE);  //Test the insertion interface
    }
    RBTree.Preorder_Traversal();    //Test the preorder traversal interface
    
    RBTree.RBTree_Delete("1");       //Test the deletion interface
    RBTree.Preorder_Traversal();
    
    RBTree.RBTree_Insert("9", FUNCTION);
    RBTree.Preorder_Traversal();
    
    RBTree.RBTree_Delete("2");
    RBTree.Preorder_Traversal();
    
    TreeNode * s = RBTree.Find("8");     //Test the search interface
    cout<<endl<<"RBTree Node valued  has right child valued "<<s->right->name<<endl;
    
    return 0;
}