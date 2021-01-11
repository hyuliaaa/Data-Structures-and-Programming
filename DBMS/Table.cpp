//
// Created by hulia on 7.1.2021 г..
//

#include "Table.h"

void Table::printName() {
    std::cout<<name;
}

void Table::setName(const std::string& nameVal) {
    name=nameVal;
}

std::string &Table::getName() {
    return name;
}

void Table::addColumn(const std::string &colName, int type, bool hasPrimaryKey) {
    if(type==0)
    {
            std::vector <int> v(table.size(),0);
            table.push_back(new IntColumn(colName,v,hasPrimaryKey));
    }
    else if(type==1)
    {
        std::vector <double > v(table.size(),0);
        table.push_back(new DoubleColumn(colName,v,hasPrimaryKey));
    }
    else if(type==2)
    {
        std::vector <std::string > v(table.size(),"");
        table.push_back(new StringColumn(colName,v,hasPrimaryKey));
    }
    else if(type==3)
    {
        std::vector <bool > v(table.size(),false);
        table.push_back(new BoolColumn(colName,v,hasPrimaryKey));
    }
    else
    {
        std::cerr<<"NO SUCH TYPE!"<<std::endl;
        return;
    }


}



void Table::printTable() {


    for(size_t i=0; i<table[0]->getSize();i++)
    {

           printRow(i);
           std::cout<<std::endl;

    }
}

Table::Table(const std::string &nameVal):name(nameVal) {
    for(size_t i=0; i<table.size();i++)
    {
        table[i]= nullptr;
    }
}

Table::~Table() {
   free();

}

Table::Table()
{
    for(int i=0; i<table.size();i++)
    {
        table[i]= nullptr;
    }

}

void Table::addColumn(Column *c) {
    table.push_back(c);
}

void Table::printColumn(int number) {
    if(number>=table.size())
    {
        std::cerr<<"Invalid number of column";
        return;
    }
    for(int i=0; i<table[number]->getSize();i++)
    {
        table[number]->printValue(i);
    }
}

void Table::insertRow() {
    for(size_t i=0; i<table.size();i++)
    {
            std:: string value;
            std::cout<<"Enter a value for " <<table[i]->getName()<<" :";
            std::getline(std::cin,value);
            table[i]->addValue(value);

    }
}
void Table::printRow(int row) {

    if(row>=table[0]->getSize())
    {
        std::cout<<"INVALID ROW NUMBER"<<std::endl;
        return;
    }
    for(size_t i=0; i<table.size();i++)
    {

        table[i]->printValue(row);


    }


}

void Table::copy(const Table &other) {
    name=other.name;
    for(size_t i=0; i<other.table.size();i++)
    {
        table[i]=other.table[i];
    }

}

void Table::free() {
    for(size_t i=0; i<table.size();i++)
    {
        delete table[i];
        table[i]= nullptr;
    }
    table.clear();

}

Table::Table(const Table &other) {
    copy(other);

}

Table &Table::operator=(const Table &other) {
    if(this!=&other)
    {
        free();
        copy(other);
    }
    return *this;
}

void Table::saveToFile(const std::string &filename) {  //todo:think whether or not should i check for nullptr
    std::ofstream outFile(filename,std::ios::binary);  //opening file for writing
    if(outFile.is_open())
    {
        size_t nameSize=name.length();
        outFile.write((char*)&nameSize, sizeof(size_t));
        outFile.write(name.c_str(),nameSize);
        for(size_t i=0; i<table.size();i++)
        {
            table[i]->saveColumn(outFile);
        }
        outFile.close();
    }
    else
    {
        std::cerr<<"File cannot be opened";
        return;
    }
}

void Table::updateColumn() {

}

void Table::select() {
    printTable();
}




