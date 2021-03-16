#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>

class StringSorter
{
public:
    StringSorter(std::string inputFileName, std::string outputFileName)
    {
        *iFileName = inputFileName;
        *oFileName = outputFileName;
        std::vector<std::string> *unsorted = new std::vector<std::string>;
        //std::vector<std::string>::iterator itU = unsorted->begin();
        std::ifstream inputFile(*iFileName);
        if (inputFile.is_open())
        {
            std::string line;
            while (std::getline(inputFile, line))
            {
                unsorted->push_back(line);
            }
        }
        else
        {
            std::cout << "unable to open the text file" << std::endl;
        }
        sort(*unsorted, *oFileName);
        delete unsorted;
    }
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

private:
    std::string *iFileName = new std::string;
    std::string *oFileName = new std::string;
    bool ifTwoStringShoulBeInterchanged(std::string primary, std::string secondary)
    {
        std::string::iterator itP = primary.begin();
        std::string::iterator itS = secondary.begin();
        /* 
            Joe          J 74       o 111      e 101     '' 0
            Joy          J 74       o 111      y 121     '' 0
            Joya         J 74       o 111      y 121      a 97
            Fio          F 70       i 105      o 111     '' 0
        */
        while (*itP == *itS)
        {
            itP++;
            itS++;
            // duplication exceptions?
        }
        //*itP != *itS
        if (ifTwoCharsAreInOrder(itP, itS))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool ifTwoCharsAreInOrder(std::string::iterator it1, std::string::iterator it2) //special characters? ¿, ú, á, ô ... s
    {
        short numP = static_cast<short>(*it1);
        short numS = static_cast<short>(*it2);
        if (numP > numS)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void sort(std::vector<std::string> pListOfStrings, std::string oFileName)
    {
        /* code */
        
        std::ofstream outputFile;
        if (outputFile.is_open())
        {
            
        }
    }
};
