#include<iostream>
using namespace std;
#define NUMNODE 500
template <class T>
class BinaryTree
{
    private:
        struct TreeNode
        {
           int info;
           int left, right,father;
        };

        TreeNode BT[NUMNODE];
        public:
        BinaryTree();
        BinaryTree(T info);
        BinaryTree(BinaryTree<T> lbt, T info, BinaryTree<T> rbt);
        bool isEmpty();
        BinaryTree<T> LChild();
        BinaryTree<T> RChild();
        T data();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    for(int i=0;i<NUMNODE;i++)
    {
        BT[i].left=-1;
        BT[i].right=-1;
        BT[i].father=-1;
    }
}

template <class T>
bool BinaryTree<T>::isEmpty()
{
    return BT[0].left==-1 && BT[0].right==-1;
}





