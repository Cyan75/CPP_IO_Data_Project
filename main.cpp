/* 
taking strings/ints/enum for an element: name, age, city, mbti
prevent stack overflow e.g. age over 99999999999999
action: sort by name, age, mbti, location
return tabular csv

make header(*.h) and class(*.cpp) files for each class
?read data separated w/ comma ","(44 in ASCII) ; e.g.  Susan,23,ESTJ,Chicago,US
*/
#include <iostream>
class PersonalInfo
{
public:
    PersonalInfo();
    ~PersonalInfo();

private:
    std::string name;
    int age;
    //enum mbti = {};
    
};
class Location : public PersonalInfo
{
public:
    Location();
    ~Location();

private:
    std::string city;
    std::string contry;
};
int main(void)
{
    std::cout<<"Hello";
    return 0;
}
