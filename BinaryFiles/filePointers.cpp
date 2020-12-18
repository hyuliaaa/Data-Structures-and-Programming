#include <iostream>
#include <fstream>
#include <cstring>

int main() {

    //za pisane vyv fail - output to the file
    char alph[]= "abcdefghijklmnopqrstuvwxyz";
    std::fstream file("alphabet.bin", std::ios::out | std::ios::binary);
    if (file.is_open())
    {
        file.write((char *)alph,strlen(alph) );
        file.close();
    }
    else
    {
        std::cerr<<"Could't open file!";
        return 1;
    }


    file.open("alphabet.txt", std::ios::in);
   if(file.is_open())
   {
       char c;
       file.seekg(6L,std::ios::beg);  // kato broim ot 0 do 6, pointer sochi kym g
       file.get(c); //vzimame stoinostta i mestim pointera edna poziciq .
       std::cout<<c<<std::endl;
       file.get(c); // sega sochim kym h i mu vzimame stoinostta  i mestim pointer edna poziciq na dqsno
       std::cout<<c<<std::endl;
       file.seekg(3L, std::ios::cur); // ot tekushtata poziciq mestim 3 napred
       file.get(c);
       std::cout<<c<<std::endl;
       file.seekg(-1,std::ios::end); //std::ios::end po princip sochi sled kraq na faila i tam si ima identificator eof , koito ni go pokazva
       file.get(c); // kato e -1 oznachava che se vryshtame edna poziciq nazad, toest sme realno na posledniq bait of faila.
       std::cout<<c<<std::endl;

       file.close();

   }
   else
   {
       std::cerr<<"Could't open file!";
       return 1;
   }

    return 0;
}
