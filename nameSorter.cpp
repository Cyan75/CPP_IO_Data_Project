#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
int main(void)
{

    std::ifstream unknownName("inNames.txt");
    std::ifstream unknownAge("inAges.txt");
    std::ofstream nameAge("namesAndAges.txt");
    if (unknownName.is_open() && unknownAge.is_open())
    {
        std::string *name = new std::string;
        std::string *ageStr = new std::string;
        while (std::getline(unknownName, *name) && std::getline(unknownAge, *ageStr))
        {
            short *age = new short;
           *age = std::stoi(*ageStr);
            std::cout << *name << ", " << *age << "," << std::endl;
            delete age;
        }
        unknownName.close();
        delete ageStr;
        delete name;
    }
    else
    {
        std::cout << "unable to open txt" << std::endl;
    }
    /* 
    
    if (nameAge.is_open())
    {
        while (std::getline(nameAge, line))
        {
            nameAge << ;
        }
        nameAge.close();
    }
    else
    {
        std::cout << "unable to write txt" << std::endl;
    }
 */
    return 0;
}
