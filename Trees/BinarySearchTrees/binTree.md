# Binary Search Tree
- binary tree in which for every node all the elements in the left subtree are smaller than that node and all the elements in the right subtree are greater
- useful for searching a tree in less number of comparisons
## Properties
- BST does not have duplicates
- inorder traversal(left,root,right) gives the elements in sorted order
- for n nodes we can generate Catalan number of trees 
## Representation
- using linked list
```C++
template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
}
```

## Searching 
- comlexity: log n
- tail recursion(if the last statement in a function is a recursive call) 
```c++
Node *recursiveSearch(Node *t, int key)
{
     if(t==nullptr)
        return nullprtr;
     if(key==t->data)
        return t;
     else if (key< t->data)
        return recursiveSearch(t->left,key);
     else
        return recursiveSearch(t->right, key);
}
```
- iterative function
``` c++
Node *search(Node *t, int key)
{

    while (t!=nullptr)
    {
        if(key==t->data)
            return t;
        if(key<t->data)
            t=t->left;
        else
            t=t->right; 
            
     }
   return nullptr;
}   
 ```           
## Inserting
- first check whether the value we are inserting is already present, if present do not to anything
- time: O(log n)
```c++
void insert (Node *t, int key)
{
      Node *r=nullptr;
      Node *p;
      while(t!=nullptr
      {
          r=t;
          if(key==t->data)
          {
              return;
          }
          else if (key < t->data)
          {
              t=t->left;
          }
          else
             t=t->right;
       }   
        
        t=new Node;
        t->data=key;
        t->left=t->right=nullptr;
        if (t->data < r->data)
        {
            r->left=t;
        }
        else
        {
            r->right=t;
        }
}
```
- recursive 
```c++
Node *insert(Node *p, int key)
{
    Node *t;
    if(p== nullptr)
    {
        t=new Node;
        t->data=key;
        t->left= nullptr;
        t->right= nullptr;
        return t;
    }
    if(key< p->data)
    {
        p->left=insert(p->left,key);
    }
    else
    {
        p->right=insert(p->right,key);
    }
    return p;
}

int main() {
    Node *root= nullptr;
    root=insert(root,30);
    insert(root,20);
    insert(root,25);
  
    return 0;
}
```
- creating a BST is done for O(n*log n)
