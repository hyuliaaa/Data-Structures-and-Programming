//
// Created by hulia on 7.1.2021 г..
//

#include "BoolColumn.h"

int BoolColumn::getType() {
    return 3;
}

void BoolColumn::printName() {
    std::cout<<name;
}

std::string BoolColumn::getName() {
    return name;
}

void BoolColumn::setName(const std::string &nameCol) {
    name=nameCol;
}

void BoolColumn::addValue(const std::string &val) {
    if(primaryKey)
    {
        if(val=="TRUE")
        {
            if(findValue(true))
            {
                std::cerr<<"An element with that value is already present in the column"<<std::endl;
                return;
            }
            else
            {
                v.push_back(true);
            }
        }
        else if(val=="FALSE")
        {
            if(findValue(false))
            {
                std::cerr<<"An element with that value is already present in the column"<<std::endl;
                return;
            }
            else
            {
                v.push_back(true);
            }
        }
        else
        {
            std::cerr<<"You  have entered wrong value for bool!"<<std::endl;
            return;
        }


    }
    else
        {
        if (val == "TRUE")
        {
            v.push_back(true);
        }
        else if (val == "FALSE")
        {
            v.push_back(false);
        }
        else
            {
            std::cerr << "You have entered wrong value for Bool!";
            return;
        }
    }
}

void BoolColumn::printValue(int row) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    printInWords(v[row]);
}

void BoolColumn::updateValue(int row, std::string &val) {
    if(v.size()>=row)
    {
        std::cerr<<"NO SUCH ROW";
        return;
    }
    if(primaryKey)
    {
        if(val=="TRUE")
        {
            if(findValue(true))
            {
                std::cerr<<"An element with that value is already present in the column"<<std::endl;
                return;
            }
            else
            {
                v[row]= true;
            }
        }
        else if(val=="FALSE")
        {
            if(findValue(false))
            {
                std::cerr<<"An element with that value is already present in the column"<<std::endl;
                return;
            }
            else
            {
                v[row]= false;
            }
        }
        else
        {
            std::cerr<<"You  have entered wrong value for bool!"<<std::endl;
            return;
        }


    }
    else
    {
        if (val == "TRUE")
        {
            v[row]= true;
        }
        else if (val == "FALSE")
        {
            v[row]= false;
        }
        else
        {
            std::cerr << "You have entered wrong value for Bool!";
            return;
        }
    }

}



bool BoolColumn::hasValueInRow(int row, std::string &val) {
    if(v.size()<=row)
    {
        std::cerr<<"NO SUCH ROW";
        return false;
    }
    return (val == "TRUE" && v[row] == 1) || (val == "FALSE" && v[row] == 0);

}

int BoolColumn::count() {
    return v.size();
}

std::string BoolColumn::maxValue() {

        std::string str="Operation maximum value for bool column unavailable!\n";
        return  str;

}

std::string BoolColumn::minValue() {
    std::string str="Operation minimal value for bool column unavailable!\n";
    return  str;
}

std::string BoolColumn::sum() {
    std::string str="Operation sum for bool column unavailable!\n";
    return  str;
}

std::string BoolColumn::average() {
    std::string str="Operation average for bool column unavailable!\n";
    return  str;
}

bool BoolColumn::findValue(bool value) {

    for(size_t i=0; i<v.size();i++)
    {
        if(v[i]==value)
        {
            return true;
        }
    }
    return false;
}

void BoolColumn::saveColumn(std::ostream &out) {
    int type=getType();
    out.write((char *)(&type), sizeof(int));
    size_t sizeName=name.size();
    out.write((char*)&sizeName, sizeof(size_t));
    out.write(name.c_str(),sizeName);
    out.write((char*)&primaryKey, sizeof(bool));
    for(size_t i=0; i<v.size();i++)
    {
        bool el=v[i];
        out.write((char*)&el, sizeof(bool));
    }

}

void BoolColumn::printInWords(bool el) {
    if(el==1)
    {
        std::cout<<"TRUE"<<" ";
    }
    else
    {
        std::cout<<"FALSE"<<" ";
    }
}
