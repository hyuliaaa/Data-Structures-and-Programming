#include <iostream>
#include <stack>
#include <queue>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

};


Node *newNode(int data)
{
    Node *current=new Node;
    current->data=data;
    current->left=nullptr;
    current->right=nullptr;

    return current;
}


int height(Node *root)
{
    if(root==nullptr)
    {
        return 0;
    }

    return max(1+height(root->left), 1 + height(root->right));
}

void printNodesAtGivenLevel(Node *root, int level)
{
    if(root==nullptr)
    {
        return;
    }
    if(level==1)
        cout<<root->data<<" ";
    else if (level>1)
    {
        printNodesAtGivenLevel(root->left,level-1);
        printNodesAtGivenLevel(root->right, level-1);
    }
}

void printLevelOrder(Node *root)
{
    int h=height(root);
    for(int i=1; i<=h; i++)
    {
        printNodesAtGivenLevel(root,i);
    }
}

void levelOrderQueue(Node *root)
{
    if (root==nullptr)
    {
        return;
    }

    queue <Node *> q;
    q.push(root);
    while(!q.empty())
    {
        Node *current=q.front();
        cout<<current<<" ";
        q.pop();

        if(current->left !=nullptr)
        {
            q.push(current->left);
        }

        if(current->right!=nullptr)
        {
            q.push(current->right);
        }
    }
}
/* Iterative function for inorder tree
   traversal */
void inOrder(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != NULL || !s.empty())
    {
        /* Reach the left most Node of the
           curr Node */
        while (curr !=  NULL)
        {
            /* place pointer to a tree node on
               the stack before traversing
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its
           left subtree.  Now, it's right
           subtree's turn */
        curr = curr->right;

    } /* end of while */
}


void deleteTree(Node *current)
{
        if(current==nullptr)
        {
            return;
        }
        deleteTree(current->left);
        deleteTree(current->right);
        delete current;
}

int minElement(Node *root)
{

    if(root==nullptr){
    return INT_MAX;
    }

    int minEl=root->data;
    int lt=minElement(root->left);
    int rt=minElement(root->right);

    if(minEl > lt)
    {
        minEl=lt;
    }

    if(minEl>rt)
    {
        minEl=rt;
    }


   return minEl;

}


/* Driver program to test above functions*/
int main()
{

   Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printLevelOrder(root);
    cout<<endl;

    cout<<minElement(root);
    return 0;
}
