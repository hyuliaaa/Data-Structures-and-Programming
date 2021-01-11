//
// Created by hulia on 6.1.2021 г..
//

#ifndef DBMS_INTCOLUMN_H
#define DBMS_INTCOLUMN_H

#include "Column.h"

class IntColumn: public Column {
private:
   std::vector<int> v;
   std::string name;
   bool primaryKey; //if a given column is chosen to be a primary key, there should be no 2 different rows with equal value in the column

public:
    IntColumn(){};
    IntColumn(const std::string& nameVal,const  std::vector<int>& vec, bool primKey):name(nameVal),v(vec), primaryKey(primKey){};

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
    void printVectorValues();
    bool findValue(int val);

    virtual void saveColumn(std::ostream& out);


};


#endif //DBMS_INTCOLUMN_H
