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

```c++
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main() {

    int matrix[5][4] = {
            { 1, 2, 3, 4},
            { 5, 6, 7, 8},
            { 9, 10, 11, 12},
            {13, 14, 15, 16},
            {17, 18, 19, 20}
    };
    //matrix is a pointer to the first element of the array which is an array
    cout<<matrix<<endl; //0x61fdd0
    cout<<&matrix[0]<<endl; //0x61fdd0 -address of first element
    cout<<matrix[0]<<endl; //0x61fdd0 - address of first elem
    cout<<(*matrix)<<endl;//0x61fdd0 - address of first elem
    cout<<*matrix[0]<<endl; //1
    cout<<**matrix<<endl; //1
    cout<<*matrix[1]<<endl;//5
    cout<<*matrix[2]<<endl;  //9
    cout<<&matrix[1]<<endl; //address of 5
    cout<<matrix[0][1]<<endl; //2
    cout<<(*(*(matrix)+1))<<endl; //2



    return 0;
}
```
