# Минималистична система за управление на бази данни
Проектът минималистична  СУБД реализира създаването на система, изградена от таблици, които поддържат произволен брой типизирани колони с възможни типове за колоните: целочислен, число с плаваща запетая, символен низ с произволна дължина и булев.
## Концепции
Проектът СУБД е реализиран чрез парадигмата за обектно-ориентираното програмиране, която представлява моделиране на предмети както от реалния свят, така и от научните сфери, чрез обекти, които да взаимодействат помежду си. Основни концепции, които се обхващат от ООП(обектно-ориентирано програмиране) са идеята за абстракция на данните, капсулиране(т.е. скриване на съществените данни за потребителя), полиморфизъм(обекти от един и същи тип да имат един и същи интерфейс, но различна реализация) и наследяване.
## Oбща архитектура
Проекътът е изграден на базата на основни концепции в обектно-ориентираното програмиране, като за неговата реализация са използвани няколко основни класа „Колона(Column)“, „Колона, поддържаща целочислени типове(IntColumn)“, „Колона поддържаща символни низове(StringColumn)“, „Колона, поддържаща булеви типове(BoolColumn)“ и „Колона, поддържаща числа с плаваща запетая(DoubleColumn)“. Като класът „Колона“ е абстрактен клас, който има за наследници изброените по-горе 4 класа за различните типове колони. Също така, реализиран е и клас „Таблица“ , който поддържа набор от типизирани колони. Проектът съдържа клас „Система за бази данни“(DatabaseSystem), който съдържа набор от таблици.
![shema](https://user-images.githubusercontent.com/54545875/104169070-a8e4c000-5407-11eb-87ad-3fe99be18521.png)
## Използване на системата
- Програма изпълнява диалогов режим за изпълнение на команди на базата от данни.
-  След като потребителят е стартирал програмата, той трябва да въведе команда  според определен синтаксис, която да извърши желанието от потребителя действия
## Примерна декларация на някои класове
- абстрактен клас "Колона"
```c++
class Column
{
public:

    virtual int getType()=0;  //0-int, 1-double, 2-string, 3-bool
    virtual void printName()=0; //prints name of column
    virtual void setName(const std::string &name)=0; //sets name of column
    virtual void addValue(const std::string& val)=0; //adds value to column
    virtual void printValue(int row)=0; //prints value of row
    virtual std::string getName()=0; //gets name of column
    virtual size_t getSize()=0; //gets size of column
    virtual void updateValue(int row,const std::string& val)=0; //updates value of current row
    virtual bool hasValueInRow(int row,const std::string& val,const std::string& op) = 0; //checks whether we have a value on a specific row
    virtual int count()=0; //number of elements in a column
    virtual std::string maxValue()=0; //finds max value of a column
    virtual std::string minValue()=0; //finds min value of a column
    virtual std::string average()=0; //find average of all values in a column
    virtual std::string sum()=0; //finds sum of all all elements in a column
    virtual void orderBy(const std::string& str)=0;
    virtual void saveColumn(std::ostream& out)=0;


    virtual ~Column(){};

};
```
- клас "Колона, поддържаща целочислени типове"
```c++
class IntColumn: public Column {
private:
   std::vector<int> v;
   std::string name;
   bool primaryKey; //if a given column is chosen to be a primary key, there should be no 2 different rows with equal value in the column

public:
    IntColumn(){};
    IntColumn(const std::string& nameVal,const  std::vector<int>& vec, bool primKey):name(nameVal),v(vec), primaryKey(primKey){};

    virtual int getType();
    virtual void printName();
    virtual std::string getName();
    virtual void setName(const std::string& nameCol);
    virtual size_t getSize(){ return v.size();};
    virtual void addValue(const std::string& val);
    virtual void printValue(int row);
    virtual void updateValue(int row, std::string& val);
    virtual bool hasValueInRow(int row, std::string& val);
    virtual int count();
    virtual std::string maxValue();
    virtual std::string minValue();
    virtual std::string sum();
    virtual std::string average();
    void printVectorValues();
    bool findValue(int val);

    virtual void saveColumn(std::ostream& out);


};
```
## Бъдещи перспективи
Тук се предоставят подобрения, свързани с бъдещата перспектива на проектът.
СУБД ще предоставя възможност за създаване на списък от потребители, които ще имат достъп до системата, като потребителите ще бъдат разделени на 2 вида:
-  Администратори – те ще поддържат системата
-  Клиенти – те ще използват системата за извличане, добавяне на нова информация и лесно търсене на определени данни.
Всеки потребител ще има достъп до системата след въвеждане на потребителско име и парола.
