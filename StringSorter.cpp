#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>

class StringSorter
{
private:
    std::string fileName;
    void compareSizeTwoStrings(std::string primary, std::string secondary) //first
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
                if (*itP != *itS)
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
                //do not need to consider uppercase, lowercase comparison
                //only the initials are capitalised
                //should be modified when there is a name with a uppercase in the middle
                else
                {
                }
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
            }
        }
    }
    //
    void compareTwoLetter(char firstLetter, char secondLetter)
    {
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
