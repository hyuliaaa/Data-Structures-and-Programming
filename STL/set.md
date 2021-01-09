# SET
**1. Associative containers** 
- collection of stored objects that allow fast retrieval using a key
- usually implemented as a balanced binary tree or hashset
- most operations are very efficient
2. **Sets**
- std::set
- std::unordered_set
- std::multiset
- std::unordered_multiset
## std::set
In order to use a set, we must #include <set> :
- similar to a mathematical set
- elements are ordered by key
- no duplicate element

## Example
```c++
std::set<int> s {4,1,1,3,3,2,5}; //1 2 3 4 5 - no error for duplicate elements
std::cout<<s.size(); //5
std::cout<<s.max_sizs(); //a very large number  , no concept of front and back, do not allow direct access to elements
 s.insert(7); //1 2 3 4 5 7, if 7 is in the set it won't be added, if not - will be added in order
  s.erase(3);
  auto it= s.find(5);
  if (it!=s.end())
  s.erase(it);
  s.count(1); // tells how many times an element appears - 0 or 1
  s.clear(); //remove all elements
  s.empty(); //true or false
  ```
## std::multi_set
- sorted by key
- allows duplicate elements
- all iterators are available
## std::unordered_set
- It is in #include <unordered_set>
- elements are unordered
- no duplicate elements allowed
- elements cannot be modified (*must be erased  and then inserted*)
- no reverse iterators allowed
## std::unordered_multiset
- elements are unordered
- allows duplicate elements
- no reverse iterators allowed

```c++

    ///numbers are ordered
    set<int>digits= {4, 1, 4 ,5, 0, 2 , 7 ,8 ,3 ,9 ,6 ,5,8 ,9 ,7 ,5 ,3, 4};
    for (int d:digits)
    {
        cout<<d<<" ";
    }

    cout<<endl;
    cout<<endl;

    set<char>letters;
    string sentence="the quick brown fox jumps over the lazy dog";
    istringstream sentenceIn(sentence);
    char letter;

    while(sentenceIn>>letter)
    {
        letters.insert(letter);
    }
    ///letters are ordered in alphabetical order
    for(set<char>::iterator it=letters.begin(); it!=letters.end(); it++)
    {
        cout<<*it;
    }
    cout<<endl;
```
