//
// Created by hulia on 10.1.2021 г..
//

#include "DatabaseSystem.h"

void DatabaseSystem::createTable(const std::string &name) {
    for(size_t i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            std::cout<<"Table with that name already exists!"<<std::endl;
            return;
        }

    }
    db.push_back(Table(name));
}

void DatabaseSystem::insertRow(const std::string &name) {
    for(size_t i=0; i<db.size();i++)
    {
        if(name==db[i].getName())
        {
            db[i].insertRow();
        }
    }
}



