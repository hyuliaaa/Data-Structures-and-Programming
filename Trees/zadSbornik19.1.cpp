#include <iostream>
#include <functional>
#include <algorithm>
template <typename T>
struct Node
{
    Node *left;
    T data;
    Node *right;
};

Node <int> * createTree()
{
    Node <int>*r=new Node<int>;
    r->data=7;
    r->left= nullptr;
    r->right= nullptr;


    Node <int> *l=new Node<int>;
    l->data=3;
    l->left= nullptr;
    l->right= nullptr;


    Node <int> * root = new Node <int>();
    root->data = 5;
    root->left = l;
    root->right = r;


    return root;


}

template <typename T>
int count(Node<T> *r)
{
    if(r== nullptr)
    {
        return 0;
    }

    return 1 + count(r->left)+count(r->right);
}

template <typename T>
int evensCount (Node <T> *r)
{
    if (r== nullptr)
    {
        return 0;
    }

    if(r->data%2==0)
    {
        return 1+evensCount(r->left)+evensCount(r->right);
    }
    return 0+evensCount(r->left)+evensCount(r->right);

}
template <typename T>
using pred=std::function<bool(const T&)>;
template <typename T>
int searchCount(Node<T>*r, pred<T> p)
{
    if(r== nullptr)
    {
        return 0;
    }
    if(p(r->data))
    {
        return 1+searchCount(r->left,p)+searchCount(r->right,p);
    }
    return 0+searchCount(r->left,p)+searchCount(r->right,p);
}

//template <typename T>
//int height(Node <T>*r)
//{
//    if(r== nullptr)
//    {
//        return 0;
//    }
//    return 1 + (max(height(r->left), height(r->right)));
//}


template <typename T>
int countLeafs(Node<T>*r)
{
    if(r== nullptr)
    {
        return 0;
    }
    if(r->left== nullptr && r->right== nullptr)
    {
        return 1;
    }
    return  countLeafs(r->left)+countLeafs(r->right);
}

template <class T>
T max ( T a, T b)
{
    return (a < b) ? b : a;
}


int main() {
    Node <int> *tree=createTree();
   // std::cout<<count(tree);
 //  std::cout<<evensCount(tree);

 //std::cout<<searchCount<int>(tree, [](int x){ return x %2==1;});
//

    return 0;
}
