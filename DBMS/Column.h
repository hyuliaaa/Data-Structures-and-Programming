//
// Created by hulia on 6.1.2021 г..
//

#ifndef DBMS_COLUMN_H
#define DBMS_COLUMN_H

#include <iostream>
#include <vector>
#include <limits>
#include <cfloat>
#include <string>

class Column
{
public:

    virtual int getType()=0;  //0-int, 1-double, 2-string, 3-bool
    virtual void printName()=0; //prints name of column
    virtual void setName(const std::string &name)=0; //sets name of column
    virtual void addValue(const std::string& val)=0; //adds value to column
    virtual void printValue(int row)=0; //prints value of row
    virtual std::string getName()=0; //gets name of column
    virtual size_t getSize()=0; //gets size of column
    virtual void updateValue(int row, std::string& val)=0; //updates value of current row
    virtual bool hasValueInRow(int row, std::string& val) = 0; //checks whether we have a value on a specific row
    virtual int count()=0; //number of elements in a column
    virtual std::string maxValue()=0; //finds max value of a column
    virtual std::string minValue()=0; //finds min value of a column
    virtual std::string average()=0; //find average of all values in a column
    virtual std::string sum()=0; //finds sum of all all elements in a column

    virtual void saveColumn(std::ostream& out)=0;


    virtual ~Column(){};

};


#endif //DBMS_COLUMN_H
