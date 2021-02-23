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
        std::string name;
        std::string ageStr;
        std::stringstream age;
        // I do not know why this generates error -> more study on stringstream that interchanges string and numerique types
        // the compiler does not perceives << as insertion operator
        while (std::getline(unknownName, name) && std::getline(unknownAge, ageStr))
        {
            age >> ageStr;
            std::cout << name << ", " << ageStr << std::endl;
        }
        unknownName.close();
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
