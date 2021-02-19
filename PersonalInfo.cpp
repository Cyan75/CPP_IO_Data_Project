#include "PersonalInfo.h"

PersonalInfo::PersonalInfo() : name("X"), age(20){}
void PersonalInfo::setName(std::string s) { name = s; }
std::string PersonalInfo::getName(void) { return name; }
void PersonalInfo::setAge(int a) { age = a; }
int PersonalInfo::getAge(void) { return age; }
//enum mbti {ISFJ, ESFJ, INFJ, ENFJ, ISTJ, ESTJ, INTJ, ENTJ, ISFP, ESFP, INFP, ENFP, ISTP, ESTP, INTP, ENTP};