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
#include "PersonalInfo.h"

int main(void)
{
    PersonalInfo *p1 = new PersonalInfo;
    delete p1;
    return 0;
}
