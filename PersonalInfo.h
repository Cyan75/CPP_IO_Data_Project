#include <iostream>
#include <fstream>
#ifndef PERSONALINFO_H
#define PERSONALINFO_H
class PersonalInfo
{
private:
    std::string name;
    int age;
public:
    PersonalInfo();
    ~PersonalInfo();
    void setName(std::string s);
    std::string getName(void);
    void setAge(int a);
    int getAge(void);
};

PersonalInfo::PersonalInfo(/* args */)
{
}

PersonalInfo::~PersonalInfo()
{
}

#endif PERSONALINFO_H
