#include <iostream>
#include <fstream>


struct Student
{
    char name[50];
    int age;
    double gpa;
};
int main() {


    Student st={"Angela", 56,4.5};

    //std::out - za pisane vyv faila
    std::fstream file("file.bin", std::ios::binary | std::ios::out);
    if(file.is_open())
    {
        //we cast the address to char
        file.write((char*)(&st), sizeof(Student));
        file.close();
    }
    else
    {
        std::cerr<<"File cannot be opened!"<<std::endl;
        return 1;
    }


    Student st2{};

    file.open("file.bin",std::ios::binary | std::ios::in);
    if(file.is_open())
    {
        file.read((char*) (&st2), sizeof(Student));
        file.close();

    } else
    {
        std::cerr<<"File cannot be opened!"<<std::endl;
        return 1;
    }

    std::cout<<st2.name<<" "<<st2.age<<" "<<st2.gpa<<std::endl;



    Student arr[3] = {
            {"Maria", 25, 4.5},
            {"Elena", 23,5.5},
            {"Hyulia", 22,6.0}
    };


    std::fstream f("Students.bin", std::ios::binary | std::ios::out);
    if(f.is_open())
    {
        //the advantage is that we write the the information about the 3 students at once
        f.write((char *) (arr), 3* sizeof(Student));
        f.close();
    }
    else
    {
        std::cerr<<"File cannot be opened!"<<std::endl;
        return 1;
    }

    Student arr2[3];
    f.open("Students.bin", std::ios::binary | std::ios::in);
    if(f.is_open())
    {
        //we read it at once
        f.read((char *)arr2, 3* sizeof(Student));
        f.close();
    }
    else
    {
        std::cerr<<"File cannot be opened!"<<std::endl;
        return 1;
    }

    for(int i =0 ;i<3; i++)
    {
        std::cout<<arr2[i].name<<" "<<arr2[i].age<<" "<<arr2[i].gpa<<std::endl;
    }

    return 0;
}
