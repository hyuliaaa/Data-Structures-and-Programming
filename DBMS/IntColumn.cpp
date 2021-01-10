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

void IntColumn::updateValue(int row, std::string& val) {
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

bool IntColumn::hasValueInRow(int row, std::string &val) {
    int intVal=stoi(val);
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    return v[row] == intVal;
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
};


