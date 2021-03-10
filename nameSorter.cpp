#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>

short getFileLines(std::string fileName)
{
    std::ifstream file(fileName);
    std::string line;
    short numLines = 0;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            numLines++;
        }
    }
    return numLines;
}

int main(void)
{
    std::ifstream unknownName("inNames.txt");
    std::ifstream unknownAge("inAges.txt");
    if (getFileLines("inNames.txt")==getFileLines("inAges.txt"))
    {
        std::cout<<" data files are compatible "<<std::endl;
    }
    if (unknownName.is_open() && unknownAge.is_open())
    {
        std::ofstream nameAge("namesAndAges.txt");
        std::string *name = new std::string;
        std::string *ageStr = new std::string;
        while (std::getline(unknownName, *name) && std::getline(unknownAge, *ageStr))
        {
            short *age = new short;
            *age = std::stoi(*ageStr);
            nameAge << *name << ", " << *age << "," << std::endl;
            delete age;
        }
        delete ageStr;
        delete name;
        nameAge.close();
    }
    else
    {
        std::cout << "unable to open txt" << std::endl;
    }
    unknownName.close();
    unknownAge.close();
    
    return 0;
}
