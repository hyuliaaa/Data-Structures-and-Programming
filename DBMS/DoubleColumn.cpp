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

void DoubleColumn::updateValue(int row,const std::string &val) {
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

bool DoubleColumn::hasValueInRow(int row,const std::string &val,const std::string& op) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    double doubleVal=stod(val);
    if(op =="=") {
        return v[row] == doubleVal;
    }
    else if(op ==">")
    {
        return v[row]>doubleVal;
    }
    else if(op ==">=")
    {
        return v[row]>=doubleVal;
    }
    else if(op=="<")
    {
        return v[row]<=doubleVal;
    }
    else if(op=="<=")
    {
        return v[row]<=doubleVal;
    }
    else if(op=="!=")
    {
        return v[row]!=doubleVal;
    }
    else
    {
        std::cerr<<"INVALID OPERATION" <<std::endl;
        return false;
    }
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

void DoubleColumn::saveColumn(std::ostream &out) {
    int type=getType();
    out.write((char *)(&type), sizeof(int));
    size_t sizeName=name.size();
    out.write((char*)&sizeName, sizeof(size_t));
    out.write(name.c_str(),sizeName);
    out.write((char*)&primaryKey, sizeof(bool));
    for(size_t i=0; i<v.size();i++)
    {
        out.write((char*)&v[i], sizeof(double));
    }
}

void DoubleColumn::orderBy(const std::string &str) {
    if(str=="ASC") {
        std::sort(v.begin(),  v.end());
    }
    else if(str=="DESC")
    {
        std::sort(v.begin(),  v.end(), std::greater<double>());
    }
    else
    {
        std::cout<<"INVALID INPUT!";
        return;
    }
}
