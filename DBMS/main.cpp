#include <iostream>

#include "Column.h"
#include "IntColumn.h"
#include "Table.h"
#include "DoubleColumn.h"

void table()
{
    std::vector<std::vector<int>> table;
    table.push_back({1,2,3}); //add column
    table.push_back({5,6,8});
    std::cout<<table.size()<<std::endl;  //  number columns
    std::cout<<table[0].size(); //number of rows

//    std::cout<<table[0][0]<<std::endl;  //1
//    std::cout<<table[0][1]<<std::endl; //2
//    std::cout<<table[0][2]<<std::endl; //3
//    std::cout<<table[1][0]<<std::endl;//4
    for(auto & row : table)
    {
        for(int col : row)
        {
            std::cout<<col<<" ";  //column in row
        }
    }

//    for(int i=0; i<table.size(); i++)
//    {
//        for(int j=0; j<table[i].size();j++)
//        {
//            std::cout<<table[i][j]<<" ";
//        }
//    }

    for(int i=0; i<table[0].size(); i++)
    {
        for(int j=0; j<table[i].size();j++)
        {
            std::cout<<table[i][j]<<" ";
        }
    }
//    vector<vector<int>> vec{ { 1, 2, 3 },
//                             { 4, 5, 6 },
//                             { 7, 8, 9, 4 } };


};
void intColTest()
{

    IntColumn col;
    std::string name="grade";
    col.setName(name);
    col.addValue("1");
    col.addValue("2");

    std::cout<<col.getVecSize();
     std::string val="6";
    col.updateValue(0,val);
    col.printVectorValues();

    std::cout<<col.hasValueInRow(2,val);

}


void ex()
{
//    Table t("students");
//    IntColumn c("col", {1,2,3});
//    DoubleColumn dc("db",{2.0,2.1,3.3});
//    std::unique_ptr<Column> ptr=std::unique_ptr<IntColumn>(new IntColumn("col", {1,2,3}));
//    t.addColumnWithElements(ptr);
//    t.printTable();
}



int main() {

    Table t("students");
    Column* ptr = new IntColumn ("people", {1,2,3});
    Column * ptr2=new DoubleColumn ("marks4",{7.9,8,9});
    t.addColumn(ptr);
    t.addColumn(ptr2);
    t.addRow();


    t.printTable();



    return 0;
}