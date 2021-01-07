//
// Created by hulia on 7.1.2021 г..
//

#include "BoolColumn.h"

int BoolColumn::getType() {
    return 3;
}

void BoolColumn::printName() {
    std::cout<<name;
}

std::string BoolColumn::getName() {
    return name;
}

void BoolColumn::setName(const std::string &nameCol) {
    name=nameCol;
}

void BoolColumn::addValue(const std::string &val) {
    if(val=="true")
    {
        v.push_back(true);
    }
    else if(val=="false")
    {
        v.push_back(false);
    }
    else
    {
        std::cerr<<"You have entered wrong Bool!";
        return;
    }
}

void BoolColumn::printValue(int row) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    std::cout<<v[row];
}

void BoolColumn::updateValue(int row, std::string &val) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    if(val=="true")
    {
        v[row]=true;
    }
    else if(val=="false")
    {
        v[row]= false;
    }
    else
    {
        std::cerr<<"You have entered wrong Bool!";
        return;
    }

}



bool BoolColumn::hasValueInRow(int row, std::string &val) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    return (val == "true" && v[row] == 1) || (val == "false" && v[row] == 0);

}
