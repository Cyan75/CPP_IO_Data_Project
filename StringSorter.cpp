#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>

class StringSorter
{
private:
    std::string fileName;
    void compareTwoStrings(std::string primary, std::string secondary)
    {
        short min = std::min(primary.size(), secondary.size());
        std::string::iterator itP = primary.begin();
        std::string::iterator itS = secondary.begin();
        //for(itP, itS)??
        for (short i = 0; i < min; ++i)// Jo vs Joe -> ?? 
        {
            if (*itP == *itS)
            {
                itP++;
                itS++;
            }
            else
            {
                short numP = static_cast<short>(*itP);
                short numS = static_cast<short>(*itS);
                if (numP < numS)
                {
                    /* LET IT BE */
                }
                else
                {
                    /* INTERCHANGE 
                    interchange(*/
                }
            }
        }
    }
    void interchange(std::string primary, std::string secondary)
    {
        /* code */
    }

public:
    StringSorter(std::string inputFileName)
    {
        fileName = inputFileName;
        std::ifstream listOfString(fileName);
        if (listOfString.is_open())
        {
            std::string line;
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
};
