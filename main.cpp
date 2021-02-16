/* 
taking strings/ints/enum for an element: name, age, city, mbti
prevent stack overflow e.g. age over 99999999999999
action: sort by name, age, city, mbti
return tabular csv
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
}