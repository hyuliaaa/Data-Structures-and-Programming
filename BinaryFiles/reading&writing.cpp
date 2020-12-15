#include <iostream>
#include <fstream>
int main() {

    int a[]= {1,2,3};
    int b[]={};


    std::fstream file ("myBin.bin", std::ios::binary|std:: ios::in | std::ios::out | std::ios::trunc);
    ///checking if the file  opened correctly
    if(!file)
    {
        std::cerr<<"The file could not be created!"<<std::endl;
        return 1;
    }
    else
    {
        
        file.write((char*)a, 3*sizeof(int));
        file.close();
    }

    //opening the file only for reading from it
    file.open("myBin.bin",std::ios::binary| std::ios::out);
    if(!file)
    {
        std::cerr<<"The file could not be created!"<<std::endl;
        return 1;
    }
    else
    {
        file.read((char*)b, 3* sizeof(int));
        file.close();
    }

    for(int i=0; i<3;i++)
    {
        std::cout<<b[i]<<" ";
    }

    return 0;
}
