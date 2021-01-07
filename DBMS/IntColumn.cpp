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
    int intVal=stoi(val);
    v.push_back(intVal);


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
    int intVal=stoi(val);
    v[row]=intVal;
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

int IntColumn::getVecSize() {
    return v.size();
}

void IntColumn::printVectorValues() {
    for(int i : v)
    {
        std::cout<<i<<" ";
    }

}


