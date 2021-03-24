
/* 
taking strings/ints/enum for an element: name, age, city, mbti 
prevent stack overflow e.g. age over 99999999999999
action: sort by name, age, mbti, location
return tabular csv

make header(*.h) and class(*.cpp) files for each class
?read data separated w/ comma ","(44 in ASCII) ; e.g.  Susan,23,ESTJ,Chicago,US
*/
/*
to make mulitudinous sets of profile, there are two ways:
1. to make a class w/ fields of name, age, mbti
2. to make vectors of name, age, mbti separately
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "PersonalInfo.h"

int main(void)
{
    //PersonalInfo *p1 = new PersonalInfo;
    //delete p1;
    /* PersonalInfo obj;
    obj.setName("Mike");
    std::cout<<obj.getName(); */
    /* below is examination of behabiour of iterators along std::iter_swap */
    std::vector<short> vec = {4, 6, 2, 1, 9, 7, 5, 3};
    std::vector<short>::iterator itB = vec.begin();
    std::vector<short>::iterator itE = vec.end() - 1;
    std::cout << " *itB = " << *itB << std::endl;
    std::cout << " *itE = " << *itE << std::endl;
    std::iter_swap(itB, itE);
    std::cout << " std::iter_swap(itB,itE); " << std::endl;
    std::cout << " *itB = " << *itB << std::endl;
    std::cout << " *itE = " << *itE << std::endl;
    std::cout << " The iterators are still pointing the physical places(addresses),\n instead of chaing the values which they were indicating!" << std::endl;
    
    itB = itE;
    std::cout << " *itB = *itE     ->    *itB =  " << *itB << std::endl;

    return 0;
}
