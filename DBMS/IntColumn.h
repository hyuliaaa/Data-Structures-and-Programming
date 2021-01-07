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

public:
    IntColumn(){};
    IntColumn(const std::string& nameVal,const  std::vector<int>& vec):name(nameVal),v(vec){};

    virtual int getType();
    virtual void printName();
    virtual std::string getName();
    virtual void setName(const std::string& nameCol);


    virtual size_t getSize(){ return v.size();};
    virtual void addValue(const std::string& val);
    virtual void printValue(int row);
    virtual void updateValue(int row, std::string& val);
    virtual bool hasValueInRow(int row, std::string& val);
    int getVecSize();
    void printVectorValues();


};


#endif //DBMS_INTCOLUMN_H
