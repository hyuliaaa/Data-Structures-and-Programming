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
    if(primaryKey)
    {
        if(findValue(doubleVal))
        {
            std::cerr<<"Element with this value cannot be added, because it is already in the column!";
            return;
        }
        else
        {
            v.push_back(doubleVal);
        }


    }else
    {

        v.push_back(doubleVal);
    }



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
    if(primaryKey)
    {
        if(findValue(doubleVal))
        {
            std::cerr<<"Element with this value cannot be updated, because it is already in the column!";
            return;
        }
        else
        {
            v[row]=doubleVal;
        }


    }else
    {

        v[row]=doubleVal;
    }

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

std::string DoubleColumn::maxValue() {

    double maxVal=DBL_MIN;
    for(double curr : v)
    {
        if(curr>maxVal)
        {
            maxVal=curr;
        }
    }
    std::string strVal=std::to_string(maxVal);
    return strVal;

}

std::string DoubleColumn::minValue() {
    double minVal=DBL_MAX;
    for(double curr: v)
    {
        if(curr<minVal)
        {
            minVal=curr;
        }
    }
    std::string strVal=std::to_string(minVal);
    return strVal;

}

std::string DoubleColumn::average() {
    double sum=0;
    for(double i : v)
    {
        sum+=i;
    }

    std::string strVal=std::to_string(sum/v.size());
    return strVal;
}

int DoubleColumn::count() {
    return v.size();
}

std::string DoubleColumn::sum() {
    double sum=0;
    for(double i : v)
    {
        sum+=i;

    }
    std::string strVal=std::to_string(sum);
    return strVal;

}

bool DoubleColumn::findValue(double value) {
    for(double i:v)
    {
        if(i==value)
        {
            return true;
        }
    }
    return false;
}
