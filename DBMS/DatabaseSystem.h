//
// Created by hulia on 10.1.2021 г..
//

#ifndef DBMS_DATABASESYSTEM_H
#define DBMS_DATABASESYSTEM_H

#include "Table.h"

class DatabaseSystem {
private:
    std::vector<Table> db;
public:

    void createTable(const std::string& name); //creates new table
    void insertRow(const std::string& name); //inserts row in a table with tablename name

};


#endif //DBMS_DATABASESYSTEM_H
