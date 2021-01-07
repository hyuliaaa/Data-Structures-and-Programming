//
// Created by hulia on 7.1.2021 г..
//

#include "StringColumn.h"

int StringColumn::getType() {
    return 2;
}

void StringColumn::printName() {
    std::cout<<name;
}

std::string StringColumn::getName() {
    return name;
}

void StringColumn::setName(const std::string &nameCol) {
    name=nameCol;
}

void StringColumn::addValue(const std::string &val) {
    v.push_back(val);
}

void StringColumn::printValue(int row) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    std::cout<<v[row];
}

void StringColumn::updateValue(int row, std::string &val) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    v[row]=val;
}

bool StringColumn::hasValueInRow(int row, std::string &val) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    return v[row] == val;
}
