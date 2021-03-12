#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>

class TxtColumnAppender
{
private:
    std::string originalFileName;
    std::string additionalFileName;
    std::string combinedFileName;
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

public:
    TxtColumnAppender(std::string firstFileName, std::string secondFileName, std::string newFileName)
    {
        originalFileName = firstFileName;
        additionalFileName = secondFileName;
        combinedFileName = newFileName;
        std::ifstream fileOne(originalFileName);
        std::ifstream fileTwo(additionalFileName);
        if (fileOne.is_open() && fileTwo.is_open())
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
                std::cout << "unable to open the text file" << std::endl;
            }
            fileOne.close();
            fileTwo.close();
        }
    }
};

int main(void)
{
    //TxtColumnAppender *obj= new TxtColumnAppender("inNames.txt", "inAges.txt", "namesAndAges.txt");
    //delete obj;
    TxtColumnAppender obj("inNames.txt", "inAges.txt", "namesAndAges.txt");
    return 0;
}
