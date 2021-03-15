#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>

class StringSorter
{
public:
    /* sort: compare every possible pair of any two lines */
    StringSorter(std::string inputFileName)
    {
        fileName = inputFileName;
        std::ifstream inputFile(fileName);
        if (inputFile.is_open())
        {
            std::string line;
            while (std::getline(inputFile, line))
            {
                unsorted.push_back(line);
            }
        }
        else
        {
            std::cout << "unable to open the text file" << std::endl;
        }
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
    std::string fileName;
    std::vector<std::string> unsorted;
    std::vector<std::string>::iterator itU = unsorted.begin();
    void CompareStringSize(std::string primary, std::string secondary) //first
    {
        std::string::iterator itP = primary.begin();
        std::string::iterator itS = secondary.begin();
        if (primary.size() == secondary.size())
        {
            /* 
            Joe          J       o       e
            Joy          J       o       y
            */
            for (short i = 0; i < secondary.size(); ++i)
            {
                compareStringContents(itP,itS);
            }
        }
        else //primary.size() != secondary.size()
        {
            /* 
            Joe          J       o       e
            Joy          J       o       y
            Joya         J       o       y       a 
            */
            short min = std::min(primary.size(), secondary.size());
            for (short i = 0; i < min; ++i)
            {
                compareStringContents(itP,itS);
            }
            //longer string to be placed later
        }
    }
    void compareStringContents(std::string::iterator it1, std::string::iterator it2)
    {
        if (*it1 != *it2)
        {
            short numP = static_cast<short>(*it1);
            short numS = static_cast<short>(*it2);
            if (numP > numS)
            {
                /* INTERCHANGE 
                    interchange()
                    */
            }
            else
            {
                /* LET IT BE */
            }
        }
        //do not need to consider uppercase, lowercase comparison
        //only the initials are capitalised
        //should be modified when there is a name with a uppercase in the middle
        else
        {
            it1 = it1++;
            it2 = it2++;
        }
    }
    void interchange(std::string primary, std::string secondary)
    {
        /* code */
    }
};
