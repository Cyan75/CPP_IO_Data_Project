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

        std::string::iterator itP = primary.begin();
        std::string::iterator itS = secondary.begin();
        //for(itP, itS)??
        /* Jo           J       o
           Joe          J       o       e
           Joy          J       o       y
           Joya         J       o       y       a
        */
        //if (both itP, itS are present, then compare)
        if (primary.size() == secondary.size())
        {
            for (short i = 0; i < secondary.size(); ++i)
            {
                if (*itP == *itS)
                {
                    itP++;
                    itS++;
                }
                //do not need to consider uppercase, lowercase comparison
                //only the initials are capitalised
                //should be modified when there is a name with a uppercase in the middle
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
        else //p and s have different string_size
        {
            /* 
            Joe          J       o       e
            Jo           J       o
            Joy          J       o       y
            Joya         J       o       y       a 
            */
            short min = std::min(primary.size(), secondary.size());
            for (short i = 0; i < min; ++i)
            {
                if (*itP == *itS)
                {
                    itP++;
                    itS++;
                }
                else
                {
                    /*code*/
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
