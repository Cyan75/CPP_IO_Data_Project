#ifndef PERSONALINFO_HPP
#define PERSONALINFO_HPP
#include <string>
namespace pio
{
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
}

#endif
