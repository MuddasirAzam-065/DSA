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
BinaryTree<T>::BinaryTree(T info)
{
    for(int i=0;i<NUMNODE;i++)
    {
        BT[i].left=-1;
        BT[i].right=-1;
        BT[i].father=-1;
    }
    BT[0].info=info;
}       

template <class T>
BinaryTree<T>::BinaryTree(BinaryTree<T> lbt, T info, BinaryTree<T> rbt)
{
    for(int i=0;i<NUMNODE;i++)
    {
        BT[i].left=-1;
        BT[i].right=-1;
        BT[i].father=-1;
    }
    BT[0].info=info;
    if(!lbt.isEmpty())
    {
        BT[0].left=1;
        for(int i=0;i<NUMNODE;i++)
        {
            if(lbt.BT[i].left!=-1||lbt.BT[i].right!=-1)
            {
                BT[i+1]=lbt.BT[i];
                if(BT[i+1].left!=-1)
                    BT[i+1].left+=1;
                if(BT[i+1].right!=-1)
                    BT[i+1].right+=1;
            }
            else
                break;
        }
    }
    if(!rbt.isEmpty())
    {
        int offset=0;
        if(!lbt.isEmpty())
            offset=lbt.size();
        BT[0].right=offset+1;
        for(int i=0;i<NUMNODE;i++)
        {
            if(rbt.BT[i].left!=-1||rbt.BT[i].right!=-1)
            {
                BT[offset+i+1]=rbt.BT[i];
                if(BT[offset+i+1].left!=-1)
                    BT[offset+i+1].left+=offset+1;
                if(BT[offset+i+1].right!=-1)
                    BT[offset+i+1].right+=offset+1;
            }
            else
                break;
        }
    }
}

template <class T>
bool BinaryTree<T>::isEmpty()
{
    return BT[0].left==-1&&BT[0].right==-1;
}

template <class T>
BinaryTree<T> BinaryTree<T>::LChild()   
{
    BinaryTree<T> lbt;
    if(BT[0].left!=-1)
    {
        for(int i=0;i<NUMNODE;i++)
        {
            if(BT[i].left!=-1||BT[i].right!=-1)
            {
                lbt.BT[i-1]=BT[i];
                if(lbt.BT[i-1].left!=-1)
                    lbt.BT[i-1].left-=1;
                if(lbt.BT[i-1].right!=-1)
                    lbt.BT[i-1].right-=1;
            }
            else
                break;
        }
    }
    return lbt;
}

template <class T>
BinaryTree<T> BinaryTree<T>::RChild()
{
    BinaryTree<T> rbt;
    if(BT[0].right!=-1)
    {
        int offset=0;
        if(BT[0].left!=-1)
            offset=BT[0].right;
        for(int i=0;i<NUMNODE;i++)
        {
            if(BT[offset+i].left!=-1||BT[offset+i].right!=-1)
            {
                rbt.BT[i]=BT[offset+i];
                if(rbt.BT[i].left!=-1)
                    rbt.BT[i].left-=offset;
                if(rbt.BT[i].right!=-1)
                    rbt.BT[i].right-=offset;
            }
            else
                break;
        }
    }
    return rbt;
}

template <class T>
T BinaryTree<T>::data()
{
    return BT[0].info;
}

int main()
{
    BinaryTree<int> bt1(1);
    BinaryTree<int> bt2(2);
    BinaryTree<int> bt3(bt1,3,bt2);
    cout<<bt3.data()<<endl;
    cout<<bt3.LChild().data()<<endl;
    cout<<bt3.RChild().data()<<endl;
    return 0;
}