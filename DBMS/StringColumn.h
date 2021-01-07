//
// Created by hulia on 7.1.2021 г..
//

#ifndef DBMS_STRINGCOLUMN_H
#define DBMS_STRINGCOLUMN_H

#include "Column.h"

class StringColumn: public Column {
private:
    std::vector<std::string> v;
    std::string name;
public:
    StringColumn(const std::string& nameVal,const  std::vector<std::string>& vec):name(nameVal),v(vec){};

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


#endif //DBMS_STRINGCOLUMN_H
