//
// Created by hulia on 6.1.2021 г..
//

#ifndef DBMS_DOUBLECOLUMN_H
#define DBMS_DOUBLECOLUMN_H

#include "Column.h"

class DoubleColumn: public Column {
private:
        std::vector<double> v;
        std::string name;
public:
    DoubleColumn(const std::string& nameVal, const std::vector<double>& vec):name(nameVal),v(vec){};

    virtual int getType();
    virtual void printName();
    virtual std::string getName();
    virtual void setName(const std::string& nameCol);

    virtual size_t getSize(){ return v.size();};
    virtual void addValue(const std::string& val);
    virtual void printValue(int row);
    virtual void updateValue(int row, std::string& val);
    virtual bool hasValueInRow(int row, std::string& val);
};


#endif //DBMS_DOUBLECOLUMN_H
