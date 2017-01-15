#include "rbtree.h"

int main()
{
    Red_Black_Tree RBTree;
    int _arr[] = {};
    for(int i=0; i<0; i++)
    {
        RBTree.RBTree_Insert(_arr[i]);  //Test the insertion interface
    }
    RBTree.Preorder_Traversal();    //Test the preorder traversal interface
    
    RBTree.RBTree_Delete(18);       //Test the deletion interface
    RBTree.Preorder_Traversal();
    
//    RBTree.RBTree_Insert(3);
//    RBTree.Preorder_Traversal();
//    
//    RBTree.RBTree_Insert(3);
//    RBTree.Preorder_Traversal();
//    
//    TreeNode * s = RBTree.Find(17);     //Test the search interface
//    cout<<endl<<"RBTree Node valued 17 has right child valued "<<s->right->key<<endl;
    
    return 0;
}