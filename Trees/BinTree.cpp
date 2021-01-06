#include <iostream>
#include <queue>
#include <stack>
#include <vector>
template <typename T>
struct Node {
    T data;
    Node *left;
    Node *right;




};
template <typename T>
void preOrder(Node<T> *root)  //root,left,right
{
    if(root==nullptr)
    {
        return;
    }
    std::cout<<root->data<<" ";
    preOrder(root->left);

    preOrder(root->right);

}


template <typename T>
void iterativePreOrder(Node <T> *root)
{
    std::stack<Node<T>*>st;
    Node <T>* t=root;
    while (!st.empty() || t!=nullptr)
    {
        if(t!=nullptr)
        {
            std::cout<<t->data<<" ";
            st.push(t);
            t=t->left;
        }
        else
        {
            t=st.top();
            st.pop();
            t=t->right;
        }
    }
    std::cout<<std::endl;
}


template <typename T>
void inOrder(Node <T>*root)//left,root,right
{
    if(root== nullptr)
    {
        return;
    }
    inOrder(root->left);
    std::cout<<root->data;
    inOrder(root->right);



}
template <typename T>
void iterativeInOrder(Node <T> *root)
{
    Node<T> *t=root;
    std::stack<Node<T>*> st;
    while (t!=nullptr || !st.empty())
    {
        if(t!=nullptr)
        {
            st.push(t);
            t=t->left;
        }
        else
        {
            t=st.top();
            st.pop();
            std::cout<<t->data<<" ";
            t=t->right;
        }
    }
}

template <typename T>
void levelOrder(Node<T>*root)
{
    Node<T>*p=root;
    std::queue<Node<T>*>q;
    std::cout<<p->data<<" ";
    q.push(p);
    while (!q.empty())
    {
        p=q.front();
        q.pop();
        if(p->left!=nullptr)
        {
            std::cout<<p->left->data<<" ";
            q.push(p->left);
        }
        if(p->right!=nullptr)
        {
            std::cout<<p->right->data<<" ";
            q.push(p->right);
        }
    }
}

template <typename T>
int countNodes(Node <T>*root)
{
    if(root== nullptr)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

template <typename T>
bool hasPathSum(const Node<T> *root, T targetSum)  //proverqva dali ima pyt ot korena do listoto sys suma targetSum
{
        if(root== nullptr)
        {
            return false;
        }
        if(targetSum==0)
        {
            return true;
        }
        if(root->data < targetSum)
        {
            return  hasPathSum(root->left,targetSum-root->data) || hasPathSum(root->right,targetSum-root->data);

        }
        if(root->data > targetSum)
        {
            return false;
        }





}
template <typename T>
bool isLeaf(Node<T> *n)
{
    return n!= nullptr && n->left == nullptr && n->right == nullptr;
}

template <typename T>
void printAllPaths(Node <T> *root,std::vector<T> vec)
{

    if(root==nullptr)
    {
        return;
    }
    if(isLeaf(root))
    {
        vec.push_back(root->data);
        for(auto& el:vec)
        {
            std::cout<<el<<" ";
        }
        std::cout<<std::endl;
    }
    else
    {
        vec.push_back(root->data);
        printAllPaths(root->left,vec);
        printAllPaths(root->right,vec);
    }

}


template <typename T>
bool sameTree(const Node<T> *leftRoot, const Node<T> *rightRoot)
{

    if(leftRoot==nullptr && rightRoot==nullptr)
    {
        return true;
    }
    if(leftRoot->data!=rightRoot->data)
    {
        return false;
    }

    return (leftRoot->data==rightRoot->data) &&
    sameTree(leftRoot->left,rightRoot->left) && sameTree(leftRoot->right,rightRoot->right);
}

template <typename T>
void mirror(Node<T>* root)
{
    if(root==nullptr)
    {
        return;
    }
    if(isLeaf(root))
    {
        return;
    }

    mirror(root->left);
    mirror(root->right);

    Node<T>*temp;
    temp=root->left;
    root->left=root->right;
    root->right=temp;
}


template <typename T>
void mirrorUsingQ(Node <T>*root)
{
    if(root==nullptr)
    {
        return;
    }

    std::queue<Node<T>*>q;
    q.push(root);
    while (!q.empty())
    {
        Node<T> *current=q.front();
        q.pop();
        swap(current->left,current->right);
        if(current->left)
        {
            q.push(current->left);
        }
        if(current->right)
        {
            q.push(current->right);
        }
    }

}


template <typename T>
bool isPalyndrome(std::vector<T> v) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != v[v.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

template <typename T>
void printPath(std::vector<T>v)
{
    for(T &el:v)
    {
        std::cout<<el<<" ";
    }
    std::cout<<std::endl;
}
template <typename T>
void printAllPalyndromicPaths(Node<T>*root,  std::vector<T> vec)
{
    if(root== nullptr)
    {
        return;
    }

    if(isLeaf(root))
    {
            vec.push_back(root->data);
            if(isPalyndrome(vec)) {
                printPath(vec);
            }
    }
    else
    {
        vec.push_back(root->data);
        printAllPalyndromicPaths(root->left,vec);
        printAllPalyndromicPaths(root->right,vec);
    }
}


template <typename T>
void printAllPathsWithSpecifiedSumHelper(Node<T>* root, std::vector<T> vec, int sum, int sumSoFar)
{
    if(root== nullptr)
    {
        return;
    }
    sumSoFar+=root->data;
    vec.push_back(root->data);
    if(sumSoFar==sum)
    {
        std::cout<<"Path Found: ";
        printPath(vec);
    }

    if(root->left)
    {
        printAllPathsWithSpecifiedSumHelper(root->left,vec,sum,sumSoFar);
    }
    if(root->right)
    {
        printAllPathsWithSpecifiedSumHelper(root->right,vec,sum,sumSoFar);
    }
   // vec.pop_back();
}
template <typename T>
void printAllPathsWithSpecifiedSum(Node<T>* root, std::vector<T> vec, int sum)
{

    printAllPathsWithSpecifiedSumHelper(root,vec,sum,0);
}
//For every node, data value must be equal to sum of data values in left and right children. Consider data value as 0 for NULL children.
template <typename T>
bool childrenSumProperty(Node<T>*root)
{
    if(root== nullptr)
    {
        return true;
    }
    if(isLeaf(root))
    {
        return true;
    }
    int leftData=0;
    int rightData=0;
    if(root->left!= nullptr)
    {
        leftData=root->left->data;
    }
    if(root->right)
    {
        rightData=root->right->data;
    }


    return (leftData+rightData=root->data) &&childrenSumProperty(root->left) && childrenSumProperty(root->right);
}

int main() {

    Node<int> *root=new Node<int>{1, nullptr, nullptr};
    root->left=new Node<int>{2, nullptr, nullptr};
    root->right=new Node<int>{3, nullptr, nullptr};
    root->left->left=new Node <int>{1, nullptr,nullptr};
    root->right->left=new Node<int>{1,nullptr,nullptr};

//    preOrder(root);
//    iterativePreOrder(root);
//    inOrder(root);
//    iterativeInOrder(root);
    //levelOrder(root);
  //  std::cout<<countNodes(root);
 //   std::cout<<hasPathSum(root,10);
    //std::cout<<isLeaf(root->right);
 //   std::vector<int> v;
   // printAllPaths(root,v);
//    Node<int> *root1=new Node<int>{1, nullptr, nullptr};
//    root1->left=new Node<int>{2, nullptr, nullptr};
//    root1->right=new Node<int>{3, nullptr, nullptr};
//    root1->left->left=new Node <int>{5, nullptr,nullptr};
//
//   // std::cout<<    sameTree(root,root1);
//   mirror(root);
//   levelOrder(root);

    std::vector<int> v;
   // printAllPalyndromicPaths(root,v);
   printAllPathsWithSpecifiedSum(root,v,4);
    return 0;
}
