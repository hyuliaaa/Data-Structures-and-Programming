# Predprocessor directives/Macros
- instructions to compiler,
- instructions are followed and performed before compilation
```c++
#define PI 3.14  // symbolic constant
#define C cout
#define SQR(x) (x * x)
#define MSG(x) #x // whatever parameter we send will be converted into a string 
int main()
{ 
    cout<<PI; //will be replaced before program starts compiling
    c<<10 // c will be replaces by cout before compilation
    
    cout<<SQR(5); // this will be replaced by 5 * 5
    cout<<MSG(HELLO); // predprocessor will be replaced by "Hello" 
}
```
