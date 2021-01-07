//
// Created by hulia on 6.1.2021 г..
//

#ifndef DBMS_COLUMN_H
#define DBMS_COLUMN_H

#include <iostream>
#include <vector>

class Column
{
public:
    virtual int getType()=0; // 0- int, 1-double, 2-string, 3-bool
    virtual void printName()=0;
    virtual void setName(const std::string &name)=0;
    virtual void addValue(const std::string& val)=0;
    virtual void printValue(int row)=0;
    virtual std::string getName()=0;
    virtual size_t getSize()=0;
    virtual void updateValue(int row, std::string& val)=0;
    virtual bool hasValueInRow(int row, std::string& val) = 0;


    virtual ~Column(){};

};

#endif //DBMS_COLUMN_H
