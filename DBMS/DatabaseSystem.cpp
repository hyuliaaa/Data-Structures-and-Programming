//
// Created by hulia on 10.1.2021 г..
//

#include "DatabaseSystem.h"
#DEFINE MAX_SIZE 1000000;
bool DatabaseSystem::createTable(const std::string &name) {
    for(size_t i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            std::cout<<"Table with that name already exists!"<<std::endl;
            return false;
        }

    }
    std::cout<<"DB SIZE: "<<db.size()<<std::endl;

    db.resize(100000)
    db.push_back(Table(name));

    std::cout<<"Table "<<name<<" created."<<std::endl;
    return true;
}

void DatabaseSystem::insertInto(const std::string &name) {
    for(size_t i=0; i<db.size();i++)
    {

        if(name==db[i].getName())
        {

            db[i].insertRow();

        }
    }
}

void DatabaseSystem::addColumn(const std::string &name, const std::string &colName, int type, bool hasPrimaryKey) {
    for(int i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            db[i].addColumn(colName,type,hasPrimaryKey);
        }
    }
}

void DatabaseSystem::addColumn(const std::string &name, Column *c) {
    for(int i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            db[i].addColumn(c);
        }
    }
}

bool DatabaseSystem::findTable(const std::string &name) {
    for(int i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            return true;
        }
    }
    std::cout<<"Table with that name does NOT exist!"<<std::endl;
    return false;
}

void DatabaseSystem::printTableNames() {
    for(size_t i=0; i<db.size();i++)
    {
        std::cout<<db[i].getName()<<std::endl;
    }

}

int DatabaseSystem::getSizeofDataBase() {
    return db.size();
}

void DatabaseSystem::printTableWithName(const std::string &name) {
    for(size_t i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            db[i].printTable();
        }
    }

}




