//
// Created by hulia on 6.1.2021 г..
//

#include "IntColumn.h"
#include <string>

int IntColumn::getType() {
    return 0;
}

void IntColumn::printName() {
    std::cout<<name;
}

std::string IntColumn::getName() {
    return name;
}

void IntColumn::addValue(const std::string& val) {
    if(primaryKey)
    {   int intVal=stoi(val);
        if(findValue(intVal))
        {
            std::cerr<<"Element with this value cannot be added, because it is already present in the column!";
            return;
        }
        else
        {
            v.push_back(intVal);
        }


    }
    else
    {
        int intVal=stoi(val);
        v.push_back(intVal);
    }



}

void IntColumn::printValue(int row) {
    if(row>=v.size())
    {
        std::cerr<<"NO SUCH ROW"<<std::endl;
        return;
    }
    std::cout<<v[row]<<" ";
}

void IntColumn::updateValue(int row, const std::string& val) {
    if(row>=v.size())
    {
        std::cerr<<"NO SUCH ROW"<<std::endl;
        return;
    }

    if(primaryKey)
    {   int intVal=stoi(val);
        if(findValue(intVal))
        {
            std::cerr<<"Element with this value cannot be updated, because it is already present in the column!";
            return;
        }
        else
        {
            v[row]=intVal;
        }


    }
    else
    {
        int intVal=stoi(val);
        v[row]=intVal;
    }

}

void IntColumn::setName(const std::string& nameCol) {
    name=nameCol;
}

bool IntColumn::hasValueInRow(int row,const std::string &val,const std::string& op) {
    int intVal=stoi(val);
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }

    if(op =="=") {
        return v[row] == intVal;
    }
    else if(op ==">")
    {
        return v[row]>intVal;
    }
    else if(op ==">=")
    {
        return v[row]>=intVal;
    }
    else if(op=="<")
    {
        return v[row]<=intVal;
    }
    else if(op=="<=")
    {
        return v[row]<=intVal;
    }
    else if(op=="!=")
    {
        return v[row]!=intVal;
    }
    else
    {
        std::cerr<<"INVALID OPERATION" <<std::endl;
        return false;
    }
}



void IntColumn::printVectorValues() {
    for(int i : v)
    {
        std::cout<<i<<" ";
    }

}

std::string IntColumn::maxValue() {
    int maxValue=INT_MIN;
    for(int el : v)
    {
        if(el>maxValue)
        {
            maxValue=el;
        }
    }
    std::string strVal=std::to_string(maxValue);
    return strVal;
}

std::string IntColumn::minValue() {
    int minVal=INT_MAX;
    for(int curr: v)
    {
        if(curr <minVal)
        {
            minVal=curr;
        }

    }
    std::string strVal=std::to_string(minVal);
    return strVal;
}

std::string IntColumn::average() {
    int sum=0;
    for(int i : v)
    {
        sum+=i;
    }

    std::string strVal=std::to_string((double)sum/v.size());
    return strVal;
}

int IntColumn::count() {
    return v.size();
}

std::string IntColumn::sum() {
    int sum=0;
    for(int i : v)
    {
        sum+=i;
    }
    std::string strVal=std::to_string(sum);
    return strVal;
}

bool IntColumn::findValue(int val) {
    for(int i : v)
    {
        if(i==val)
        {
            return true;
        }
    }
    return false;
}

void IntColumn::saveColumn(std::ostream &out) {

    int type=getType();
    out.write((char *)(&type), sizeof(int));
    size_t sizeName=name.size();
    out.write((char*)&sizeName, sizeof(size_t));
    out.write(name.c_str(),sizeName);
    out.write((char*)&primaryKey, sizeof(bool));
    for(size_t i=0; i<v.size();i++)
    {
        out.write((char*)&v[i], sizeof(int));
    }
}

void IntColumn::orderBy(const std::string &str) {
    if(str=="ASC") {
        std::sort(v.begin(),  v.end());
    }
    else if(str=="DESC")
    {
        std::sort(v.begin(),  v.end(), std::greater<int>());
    }
    else
    {
        std::cout<<"INVALID INPUT!";
        return;
    }
}


