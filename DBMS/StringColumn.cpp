//
// Created by hulia on 7.1.2021 г..
//

#include "StringColumn.h"

int StringColumn::getType() {
    return 2;
}

void StringColumn::printName() {
    std::cout<<name;
}

std::string StringColumn::getName() {
    return name;
}

void StringColumn::setName(const std::string &nameCol) {
    name=nameCol;
}

void StringColumn::addValue(const std::string &val) {
    if(primaryKey)
    {
        if(findValue(val))
        {
            std::cerr<<"String is already found in the column!"<<std::endl;
            return;
        }
        else
        {
            v.push_back(val);
        }
    }
    else
    {
        v.push_back(val);
    }

}

void StringColumn::printValue(int row) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    std::cout<<v[row]<<" ";
}

void StringColumn::updateValue(int row,const std::string &val) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    if(primaryKey)
    {
        if(findValue(val))
        {
            std::cerr<<"String is already found in the column!"<<std::endl;
            return;
        }
        else
        {
            v[row]=val;
        }
    }
    else
    {
        v[row]=val;
    }

}

bool StringColumn::hasValueInRow(int row,const std::string &val, const std::string& op) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    if(op =="=") {
        return v[row] ==  val;
    }
    else if(op ==">")
    {
        return v[row]> val;
    }
    else if(op ==">=")
    {
        return v[row]>= val;
    }
    else if(op=="<")
    {
        return v[row]<= val;
    }
    else if(op=="<=")
    {
        return v[row]<= val;
    }
    else if(op=="!=")
    {
        return v[row]!= val;
    }
    else
    {
        std::cerr<<"INVALID OPERATION" <<std::endl;
        return false;
    }

}

int StringColumn::count() {
    return v.size();
}

std::string StringColumn::maxValue() {
    std::string str="Operation maximum value for string column unavailable!\n";
    return  str;
}

std::string StringColumn::minValue() {
    std::string str="Operation minimal value for string column unavailable!\n";
    return  str;
}

std::string StringColumn::sum() {
    std::string str="Operation sum for string column unavailable!\n";
    return  str;
}

std::string StringColumn::average() {
    std::string str="Operation average for string column unavailable!\n";
    return  str;
}

bool StringColumn::findValue(const std::string &str) {
    for(const auto & i : v)
    {
        if(i==str)
        {
            return true;
        }

    }
    return false;
}

void StringColumn::saveColumn(std::ostream &out) {

    int type=getType();
    out.write((char *)(&type), sizeof(int));
    size_t sizeName=name.size();
    out.write((char*)&sizeName, sizeof(size_t));
    out.write(name.c_str(),sizeName);
    out.write((char*)&primaryKey, sizeof(bool));
    for(size_t i=0; i<v.size();i++)
    {
        size_t sizeStr=v[i].length();
        out.write((char *)& sizeStr, sizeof(size_t));
        out.write(v[i].c_str(),sizeStr);
    }
}

void StringColumn::orderBy(const std::string &str) {
    if(str=="ASC") {
        std::sort(v.begin(),  v.end());
    }
    else if(str=="DESC")
    {
        std::sort(v.rbegin(),  v.rend());
    }
    else
    {
        std::cout<<"INVALID INPUT!";
        return;
    }

}
