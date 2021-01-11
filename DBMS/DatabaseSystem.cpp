//
// Created by hulia on 10.1.2021 г..
//

#include "DatabaseSystem.h"

bool DatabaseSystem::createTable(const std::string &name) {

    for (auto it = db.begin(); it != db.end(); ++it){
        if(name==it->getName())
        {
            std::cout<<"Table with that name already exists!"<<std::endl;
            return false;
        }
    }



    db.push_back(Table(name));

    std::cout<<"Table "<<name<<" created."<<std::endl;
    return true;
}

void DatabaseSystem::insertInto(const std::string &name) {

    for (auto it = db.begin(); it != db.end(); ++it){
        if(name==it->getName())
        {
            it->insertRow();
        }
    }
}

void DatabaseSystem::addColumn(const std::string &name, const std::string &colName, int type, bool hasPrimaryKey) {
    for (auto it = db.begin(); it != db.end(); ++it)
    {
        if(name==it->getName())
        {
            it->addColumn(colName,type,hasPrimaryKey);
        }
    }
}

void DatabaseSystem::addColumn(const std::string &name, Column *c) {

    for (auto it = db.begin(); it != db.end(); ++it){
        if(name==it->getName())
        {
            it->addColumn(c);

        }
    }
}

bool DatabaseSystem::findTable(const std::string &name) {
    for (auto it = db.begin(); it != db.end(); ++it)
    {
        if(name==it->getName())
        {
            return true;
        }
    }
    std::cout<<"Table with that name does NOT exist!"<<std::endl;
    return false;
}

void DatabaseSystem::printTableNames() {

    for (auto it = db.begin(); it != db.end(); ++it){
            std::cout <<it->getName()<<std::endl;


    }

}


void DatabaseSystem::printTableWithName(const std::string &name) {

    for (auto it = db.begin(); it != db.end(); ++it){
        if(name==it->getName())
        {
            it->select();
        }
    }

}



void DatabaseSystem::saveTable(const std::string &tableName, const std::string &filename) {
    for(auto it=db.begin();it!=db.end();++it)
    {
        if(tableName==it->getName())
        {
            it->saveToFile(filename);
        }
    }
}

void DatabaseSystem::selectStar(const std::string &name) {
    for(auto it=db.begin();it!= db.end();++it)
    {
        if(name==it->getName())
        {
            it->select();
        }
    }
}

int DatabaseSystem::count(const std::string &tableName, int column, const std::string &key,const std::string& op) {
    int counter=0;
    for(auto it=db.begin();it!=db.end();++it)
    {
        if(tableName==it->getName())
        {

            counter=it->count(column,key,op);
        }
    }
    return counter;
}

void
DatabaseSystem::update(const std::string &tableName, int column, const std::string &key, const std::string &newVal,const std::string& op) {
    for(auto it=db.begin();it!=db.end();++it)
    {
        if(tableName==it->getName())
        {

            it->update(column,key,newVal,op);
        }
    }
}






