
//
// Created by hulia on 10.1.2021 г..
//

#ifndef DBMS_DATABASESYSTEM_H
#define DBMS_DATABASESYSTEM_H

#include <list>
#include "Table.h"

class DatabaseSystem {
private:
    std::list<Table> db;
public:

    bool createTable(const std::string& name);
    void addColumn(const std::string& name,const std::string& colName, int type, bool hasPrimaryKey);
    void addColumn(const std::string& name, Column *c);
    void insertInto(const std::string& name); //inserts row in a table with tablename name
    bool findTable(const std::string& name); //finds table with given name
    void printTableNames();//prints all table names found in the database
    void printTableWithName(const std::string& name);
    void saveTable(const std::string& tableName,const std::string& filename);
    void selectStar(const std::string& name);
    int count(const std::string& tableName,int column,const std::string& key,const std::string& op);  //функция, която връща броя на редовете, в който има ст-т key
    void update(const std::string& tableNam,int column,const std::string& key,const std::string& newVal,const std::string& o); //ф-я, която ъйдейтва ред със ст-т key до ред със ст newVal
};


#endif //DBMS_DATABASESYSTEM_H