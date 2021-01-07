//
// Created by hulia on 6.1.2021 г..
//

#include "DoubleColumn.h"
#include <cstdlib>
#include <string>

int DoubleColumn::getType() {
    return 1;
}

void DoubleColumn::printName() {
    std::cout<<name;
}

std::string DoubleColumn::getName() {
    return name;
}

void DoubleColumn::addValue(const std::string &val) {
    double doubleVal=stod(val);
    v.push_back(doubleVal);
}

void DoubleColumn::printValue(int row) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW"<<std::endl;
        return;
    }

    std::cout<<v[row]<<" ";
}

void DoubleColumn::updateValue(int row, std::string &val) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    double doubleVal=stod(val);
    v[row]=doubleVal;

}
void DoubleColumn::setName(const std::string& nameCol)
{
    name=nameCol;
}

bool DoubleColumn::hasValueInRow(int row, std::string &val) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    double doubleVal=stod(val);
    return v[row] == doubleVal;
}
