# Namespaces
- used for removing name conflict
- if we are writing same independent functions which are not overloaded,  everything is same, we will have name conflict

```c++
namespace First
{
  void fun()
  {
    cout<<"First";
  }
}  

namespace Second
{
  void fun()
  {
    cout<<"Second";
  }
}  

using namespace Second
int main ()
{
   First::fun();
   fun(); // will call fun() in  the second namespace, because it uses it
   
   return 0;
}
```
