#include <iostream>

#include "Column.h"
#include "IntColumn.h"
#include "Table.h"
#include "DoubleColumn.h"
#include "DatabaseSystem.h"
void table()
{
    std::vector<std::vector<int>> table;
    table.push_back({ 1,2,3 }); //add column
    table.push_back({ 5,6,8 });
    std::cout << table.size() << std::endl;  //  number columns
    std::cout << table[0].size(); //number of rows

//    std::cout<<table[0][0]<<std::endl;  //1
//    std::cout<<table[0][1]<<std::endl; //2
//    std::cout<<table[0][2]<<std::endl; //3
//    std::cout<<table[1][0]<<std::endl;//4
    for (auto& row : table)
    {
        for (int col : row)
        {
            std::cout << col << " ";  //column in row
        }
    }

    //    for(int i=0; i<table.size(); i++)
    //    {
    //        for(int j=0; j<table[i].size();j++)
    //        {
    //            std::cout<<table[i][j]<<" ";
    //        }
    //    }

    for (int i = 0; i < table[0].size(); i++)
    {
        for (int j = 0; j < table[i].size(); j++)
        {
            std::cout << table[i][j] << " ";
        }
    }
    //    vector<vector<int>> vec{ { 1, 2, 3 },
    //                             { 4, 5, 6 },
    //                             { 7, 8, 9, 4 } };


};
void intColTest()
{

    IntColumn col;
    std::string name = "grade";
    col.setName(name);
    col.addValue("1");
    col.addValue("2");

    std::cout << col.count();
    std::string val = "6";
    col.updateValue(0, val);
    col.printVectorValues();

    std::cout << col.hasValueInRow(2, val);

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
bool validateString(std::string& str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_'))
        {
            return false;
        }


    }
    return true;
}
void help()
{
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "CREATE TABLE                       creates table" << std::endl;
    std::cout << "SAVE TABLE                         saves table" << std::endl;
    std::cout << "INSERT INTO                        inserts row" << std::endl;
    std::cout << "SELECT * FROM                        prints table" << std::endl;
    std::cout << "AVERAGE                             find average" << std::endl;
}

void test() {
    Table t;
    std::cout << "Welcome to Database Management System! To see a list of all commands type HELP: " << std::endl;
    std::cout << "> ";
    std::string str;
    getline(std::cin, str);
    while (str != "QUIT") {
        if (str == "HELP")
        {
            help();
        }
        else if (str == "CREATE TABLE") {
            std::cout << "Enter table name" << std::endl;
            std::getline(std::cin, str);
            if (!validateString(str))
            {
                std::cout << "INVALID NAME FOR TABLE!" << std::endl;
                return;
            }
            t = (str);
            std::cout << "Enter number of columns in the table: ";
            int n;
            std::cin >> n;
            std::cin.ignore();
            for (int i = 0; i < n; i++) {
                std::cout << "Enter name of column:";
                std::string colname;
                if (!validateString(colname))
                {
                    std::cout << "INVALID NAME FOR COLUMN!" << std::endl;
                    return;
                }
                std::getline(std::cin, str);
                std::cout << "Enter type of column:";
                std::string type;
                std::getline(std::cin, type);
                if (type == "string") {
                    Column* c = new StringColumn(colname, { "" }, false);
                    t.addColumn(c);
                }
                else if (type == "int") {
                    Column* c = new IntColumn(colname, { 0 }, false);
                    t.addColumn(c);
                }
                else if (type == "double") {

                    Column* c = new DoubleColumn(colname, { 0 }, false);
                    t.addColumn(c);
                }
                else if (type == "bool") {

                    std::vector<bool> v;
                    Column* c = new BoolColumn(colname, v, false);
                    t.addColumn(c);

                }
                else {
                    std::cout << "This type is not valid!" << std::endl;
                    return;
                }
            }
            std::cout << "Table " << t.getName() << " created." << std::endl;
        }
        else if (str == "INSERT INTO")
        {
            t.insertRow();
        }
        else if (str == "SELECT * FROM")  //todo vij zashto printira 0
        {
            t.select();
        }
        else if (str == "SAVE TABLE")
        {
            std::cout << "Enter a filename to save the table: " << std::endl;
            std::string filename;
            std::getline(std::cin, filename);
            t.saveToFile(filename);
            std::cout << "SUCCESSFULLY SAVED TO FILE!" << std::endl;

        }
        else
        {
            std::cout << "You have entered a wrong command! Try again!" << std::endl;
        }


        std::cout << "Choose a new command to execute:" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, str);
    }
    std::cout << "Exiting. Good bye!" << std::endl;


}

void test2()
{
    DatabaseSystem db;
    std::cout << "Welcome to Database Management System! To see a list of all commands type HELP: " << std::endl;
    std::cout << "> ";
    std::string str;
    getline(std::cin, str);
    while (str != "QUIT")
    {
        if (str == "CREATE TABLE")  //syzdavame tablica i dobavqme avtomatichno edin red v neq s default values
        {
            std::cout << "Enter table name" << std::endl;
            std::string tableName;
            std::getline(std::cin, tableName);
            if (!validateString(tableName))
            {
                std::cout << "INVALID NAME FOR TABLE!" << std::endl;
                return;
            }
            if (!db.createTable(tableName))
            {
                return;
            }
            std::cout << "Enter number of columns in the table: ";
            int n;
            std::cin >> n;
            std::cin.ignore();
            for (int i = 0; i < n; i++) {
                std::cout << "Enter name of column:";
                std::string colname;
                std::getline(std::cin, colname);
                if (!validateString(colname))
                {
                    std::cout << "INVALID NAME FOR COLUMN!" << std::endl;
                    return;
                }
                std::cout << "Enter type of column:";
                std::string type;
                std::getline(std::cin, type);
                if (type == "string") {
                    Column* c = new StringColumn(colname, { "" }, false);
                    db.addColumn(tableName, c);
                }
                else if (type == "int") {
                    Column* c = new IntColumn(colname, { 0 }, false);
                    db.addColumn(tableName, c);
                }
                else if (type == "double") {

                    Column* c = new DoubleColumn(colname, { 0 }, false);
                    db.addColumn(tableName, c);
                }
                else if (type == "bool") {

                    std::vector<bool> v;
                    Column* c = new BoolColumn(colname, v, false);
                    db.addColumn(tableName, c);

                }
                else {
                    std::cout << "This type is not valid!" << std::endl;
                    return;
                }
            }
        }
        else if (str == "INSERT INTO")
        {
            std::string tableName;
            std::cout << "Enter table name: ";
            std::getline(std::cin, tableName);
            db.insertInto(tableName);
        }
        else if (str == "PRINT TABLES IN DB")
        {
            db.printTableNames();
        }
        else if (str == "PRINT TABLE WITH NAME")
        {
            std::string tableName;
            std::cout << "Enter table name: ";
            std::getline(std::cin, tableName);
            db.printTableWithName(tableName);
        }
        else
        {
            std::cout << "You have entered a wrong command! Try again!" << std::endl;
        }
        std::cout << "Choose a new command to execute:" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, str);
    }

    std::cout << "Exiting. Good bye!" << std::endl;
}
int main() {

    //  Table t("students");
    //   Column* ptr = new IntColumn ("people", {1,2,3}, true);
    //  Column * ptr2=new BoolColumn ("marks4",{1,0,1}, false);
    //  //  DoubleColumn c("marks4",{7.9,8,9});
    //   //  ptr->addValue("4");
    // //    ptr->printValue(3);
    //   // std::cout<<ptr2->average();
    //
    ////
    //  t.addColumn(ptr);
    //  t.addColumn(ptr2);
    //////    t.insertRow();
    //////
    //////
    //    DatabaseSystem db;
    //    db.createTable("stood");
    //    db.insertRow("stood");
    ////    t.saveToFile("table.bin");
////
//    DatabaseSystem db;
//    db.createTable("students");
//    db.addColumn("students", "fn", 0, false);
//     db.insertInto("students");
//    db.printTableWithName("students");
     test2();




    return 0;
}