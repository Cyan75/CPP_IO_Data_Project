#include "DataAppender.hpp"

pio::DataAppender::DataAppender(std::string first, std::string second, std::string combined)
{
    std::string originalFileName = first;
    std::string additionalFileName = second;
    std::string combinedFileName=combined;
    std::ifstream fileOne(originalFileName);
    std::ifstream fileTwo(additionalFileName);
    if (fileOne.is_open() && fileTwo.is_open())
    {
        try
        {
            if (getFileLines(originalFileName) == getFileLines(additionalFileName))
            {
                //std::cout << " data files are compatible " << std::endl;
                std::ofstream resultingFile(combinedFileName);
                std::string *name = new std::string;
                std::string *ageStr = new std::string;
                while (std::getline(fileOne, *name) && std::getline(fileTwo, *ageStr))
                {
                    short *age = new short;
                    *age = std::stoi(*ageStr);
                    resultingFile << *name << ", " << *age << "," << std::endl;
                    delete age;
                }
                delete ageStr;
                delete name;
                resultingFile.close();
            }
            else
            {
                throw 505;
            }
        }
        catch (std::exception &e)
        {
            std::cout << "unable to open the text file" << std::endl;
        }
    }
    fileOne.close();
    fileTwo.close();
}
short pio::DataAppender::getFileLines(std::string fileName)
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
