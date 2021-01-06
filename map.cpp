#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
void display(std::map<std::string,vector<int>>& m)
{
    for(auto& elem:m)
    {
        cout<<elem.first<<":";
        for(auto &vecElem: elem.second )
        {
            cout<<vecElem<<" ";
        }
    }
    cout<<endl;
}

void print(std::vector<map<string,vector<int>>> &vec)
{
    for(auto &x : vec)
    {
        for(auto &el : x)
        {
            for(auto &curr : el.second)
            {
                cout<<curr<<" ";
            }
        }
    }
}
int main() {


    std::map <std::string, vector<int>> m1
            {
                    {"Larry", {1,2,3,4}}
            };

    m1["Larry"].push_back(7);
  //  display(m1);


   std::vector<map<std::string,vector<int>>> table;
   table.push_back({{"Hello", {1,2,3,4}}});
   table.at(0)["Hello"].push_back(5);
   print(table);





    return 0;
}
