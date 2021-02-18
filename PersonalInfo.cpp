#include "PersonalInfo.h"

PersonalInfo::PersonalInfo() : name{"X"}, age{20}
{
}
void setName(std::string s) { name = s; }
std::string getName(void) { return name; }
void setAge(int a) { age = a; }
int getAge(void) { return age; }
std::string name;
int age;
//enum mbti {ISFJ, ESFJ, INFJ, ENFJ, ISTJ, ESTJ, INTJ, ENTJ, ISFP, ESFP, INFP, ENFP, ISTP, ESTP, INTP, ENTP};