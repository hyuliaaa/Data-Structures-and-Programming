#include <iostream>

#include "Column.h"
#include "IntColumn.h"
#include "Table.h"
#include "DoubleColumn.h"
#include "DatabaseSystem.h"

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

    std::cout << col.hasValueInRow(2, val,"=");

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
    std::cout << "CREATE TABLE                          creates table" << std::endl;
    std::cout << "SAVE TABLE                            saves table" << std::endl;
    std::cout << "INSERT INTO                           inserts row" << std::endl;
    std::cout << "SELECT * FROM                         prints table" << std::endl;
    std::cout << "PRINT TABLE WITH NAME                 prints table with given name" << std::endl;

}

void test() {  //works only on 1 table
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
        else if (str == "SELECT * FROM")
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
void help2()
{
    std::cout << "The following commands are supported:" << std::endl;
    std::cout << "CREATE TABLE                       creates table" << std::endl;
    std::cout << "SAVE TABLE                         saves table" << std::endl;
    std::cout << "INSERT INTO                        inserts row" << std::endl;
    std::cout << "SELECT * FROM                       all available  tables" << std::endl;
    std::cout << "PRINT TABLES IN DB                  prints names of all tables in the database" << std::endl;
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

            if(db.findTable(tableName))
            {
                db.printTableWithName(tableName);
            }
        }
        else if(str == "SAVE TABLE")
        {
            std::string tableName;
            std::cout << "Enter table name: ";
            std::getline(std::cin, tableName);
            std::string filename;
            std::cout<<"Enter filename: ";
            std::getline(std::cin,filename);
            if(db.findTable(tableName))
            {
                db.saveTable(tableName, filename);
            }
        }
        else if(str =="SELECT * FROM")
        {
            std::string tableName;
            std::cout << "Enter table name: ";
            std::getline(std::cin, tableName);
            if(db.findTable(tableName))
            {
                db.selectStar(tableName);
            }

        }
        else if(str=="HELP")
        {
            help2();
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

void exampleForUpdate()
{
    Table t("students");
    Column* ptr = new IntColumn ("people", {5,7,3}, false);
    Column * ptr2=new IntColumn ("marks4",{1,2,2}, false);


    t.addColumn(ptr);
    t.addColumn(ptr2);
    t.printTable();

    t.update(0,"3","6",">=");
    std::cout<<std::endl;
    t.printTable();
}
int main() {




     test2();




    return 0;
}