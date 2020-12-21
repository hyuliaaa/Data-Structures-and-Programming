# Map
- usually implemented as balanced tree or hashsets

## std::map
- include  #include <map> 
- similar to a dictionary
- elements are stored as Key,Value pairs(std::pairs)
- ordered by key
- no duplicate elements (keys are unique)
- direct element access using the key

**initialization**
```c++
std::map <std::string, int> m1
{
    {"Larry", 18},
    {"Moe",25}
};    
```
```c++
std::map <std::string, std::string> m
{
    {"Bob", "Butcher"},
    {"Anne","Baker"},
    {"George", "Candlestick maker"}
    
};

std::<<m.size(); //3
std:pair <std::string,std::string> p1 {"James", "Singer"};
m.inset(p1);
m.insert(std::make_pair ("Lena", "Sales manager"));
m["Frank"] = "Teacher"; //insert
m["Frank"] = "Shopper"; //update value


m.erase("Anne"); //erase Anne
if(m.find("Lena"!=m.end()) //if I get back an iterarator that is not pointing to the end of the map, the we found a match
  std::cout<<"Found Lena";
 m.clear(); //removes all elements from the map 

```
## std::multi_map
- ordered by key
- allows duplicate elements
- all iterators are available
## std::unordered_map
- #include <unordered_map>
- elements are unordered
- no duplicate element allowed
- no reverse iterators
