//
// Created by hulia on 10.1.2021 г..
//

#ifndef DBMS_DATABASESYSTEM_H
#define DBMS_DATABASESYSTEM_H

#include <list>
#include "Table.h"

class DatabaseSystem {
private:
    std::vector<Table> db;
public:

    bool createTable(const std::string& name); //creates new table ; poradi nqkakva prichina ne moga da syzdam 2 tablici
    void addColumn(const std::string& name,const std::string& colName, int type, bool hasPrimaryKey);
    void addColumn(const std::string& name, Column *c);
    void insertInto(const std::string& name); //inserts row in a table with tablename name
    bool findTable(const std::string& name); //finds table with given name
    void printTableNames();//prints all table names found in the database
    int getSizeofDataBase();
    void printTableWithName(const std::string& name);
    
   
};


#endif //DBMS_DATABASESYSTEM_H

