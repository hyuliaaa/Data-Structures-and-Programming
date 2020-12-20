**Pointers**
  SYNTAX | MEANING
  -------|--------
  int const *ptr | ptr is a pointer to const int 
  const int *ptr | ptr is a pointer to int constant (i.e. const int)
  int *const ptr | ptr is a const ptr to int
  const int * const ptr | ptr is a const ptr to a const int


```c++
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() {

    int arr[]= {1,2,3};
    cout<<arr[0]<<endl;  //1
    cout<<&arr[0]<<endl; //0x61fe0c
    cout<<arr<<endl;//0x61fe0c

    int *p=arr;
    cout<<p;   //0x61fe0c
    cout<<endl;
    cout<<*p; // 1
    p++; //change to next location
    cout<<p<<endl;//10x61fe10
    cout<<*p<<endl; //2

    return 0;
}
```
