#include <set>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

std::vector<std::string> putInVector(std::string& str)
{
        std::stringstream stream{str};
        std::string word;
        std::vector <std::string> v;
        while (stream>>word)
        {
            v.push_back(word);
        }
    return v;



}

void printMap(std::unordered_map <std::string, int> m);
//checks if a given string of words can be formed from words present in a dictionary
bool matchWords(std::vector<std::string> v1, std::vector<std::string> v2)
{
    //map to store all words in a dict with their count
    std::unordered_map<std::string, int> m;

    for(int i=0; i<v1.size();i++)
    {
        m[v1[i]]++;
    }

    printMap(m);

    for(int i=0; i<v2.size();i++)
    {
        if(m[v2[i]]) //if word is present in the map
        {
            m[v2[i]]--;
        }
        else //if not present
        {
            return false;
        }
    }
    return true;
}


void printMap(std::unordered_map <std::string, int> m)
{
    for(auto const& pair:m)
    {
        std::cout<<pair.first<<": "<<pair.second<<std::endl;
    }
}

//count words that appear two times in an array of words
int countWords(std::string str[],int n)
{
    std::unordered_map<std::string,int> m;
    for(int i=0; i<n;i++)
    {
        m[str[i]]+=1;
    }

    printMap(m);
    int res=0;
    for(auto & it : m)
    {
        if(it.second==2)
        {
            res++;
        }
    }
    return res;
}
int main()
{
//    std::string dic= "find a geeks all for on geeks answers inter";
//    std::string sentence = "find all answers on geeks for geeks";
//
//    std::vector<std::string> dict=putInVector(dic);
//
//
////    //masiv ot stirngove
////    std::string dictionary[] = { "find", "a", "geeks",
////                            "all", "for", "on",
////                            "geeks", "answers", "inter" };
//
//
//    std::cout<<matchWords(dict,putInVector(sentence));


    std::string s[] = { "hate", "love", "peace", "love",
                   "peace", "hate", "love", "peace",
                   "love", "peace" };

    int n = sizeof(s) / sizeof(s[0]);
    std::cout << countWords(s, n);


    
    return 0;
}
