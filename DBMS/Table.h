//
// Created by hulia on 7.1.2021 г..
//

#ifndef DBMS_TABLE_H
#define DBMS_TABLE_H

#include "Column.h"
#include "IntColumn.h"
#include "DoubleColumn.h"
#include "BoolColumn.h"
#include "StringColumn.h"
#include <functional>
#include <fstream>


class Table {
private:
    std::string name;
    std::vector<Column*>table;

    void copy(const Table& other);
    void free();
public:
    Table();
    Table(const std::string& nameVal);
    Table(const Table& other);
    Table& operator=(const Table& other);
    ~Table();


    //adds an empty column
    void addColumn(const std::string& colName, int type, bool hasPrimaryKey);
    //here the added column must be allocated dynamically on heap;
    void addColumn(Column *c);
    void printName();

    void setName(const std::string& nameVal);
    void printTable();
    void printColumn(int number);
    void insertRow();
    void printRow(int row);
    void select(); //this is select* which chooses all columns in the table and prints them "SELECT * FROM students
    int count(int column,const std::string& key,const std::string& op); //returns count of rows that have key
    void update(int column,const std::string& key,const std::string& newVal,const std::string& op); //updates rows with key to newVal

    void saveToFile(const std::string& filename);

    std::string& getName();


};


#endif //DBMS_TABLE_H