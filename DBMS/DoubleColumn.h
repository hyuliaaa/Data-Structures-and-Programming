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
        bool primaryKey;
public:
    DoubleColumn(const std::string& nameVal, const std::vector<double>& vec, bool primKey):name(nameVal),v(vec),primaryKey(primKey){};

    virtual int getType();
    virtual void printName();
    virtual std::string getName();
    virtual void setName(const std::string& nameCol);

    virtual size_t getSize(){ return v.size();};
    virtual void addValue(const std::string& val);
    virtual void printValue(int row);
    virtual void updateValue(int row, std::string& val);
    virtual bool hasValueInRow(int row, std::string& val);
    virtual int count();
    virtual std::string maxValue();
    virtual std::string minValue();
    virtual std::string sum();
    virtual std::string average();
    bool findValue(double value);

};


#endif //DBMS_DOUBLECOLUMN_H
