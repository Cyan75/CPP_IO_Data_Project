#ifndef _PERSONALINFO_H_
#define _PERSONALINFO_H_
#include <iostream>
#include <fstream>

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

//PersonalInfo::PersonalInfo() : name("X"), age(20) {}

//PersonalInfo::~PersonalInfo() {}

#endif
