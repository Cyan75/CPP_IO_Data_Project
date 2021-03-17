#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

class StringSorter
{
public:
    StringSorter(std::string inputFileName, std::string outputFileName)
    {
        *iFileName = inputFileName;
        *oFileName = outputFileName;
        std::vector<std::string> *unsorted = new std::vector<std::string>;
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
        /*
            sort
        */
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
    /*
        • collect pivot candidates randomly
        • default number of the candidates is three(fix?)
        • choose the middle as the pivot
        • 
    */
    std::vector<std::string> quickSort(std::vector<std::string> unsortedVector)
    {
        short max = unsortedVector.size();
        short pivotCandidateNum = 3;
        std::vector<short> pivotCandidates;
        for (short i = 0; i < pivotCandidateNum; ++i)
        {
            std::srand(std::time(nullptr));
            short *pickRandom = new short;
            *pickRandom = (std::rand() % max);
            pivotCandidates.push_back(*pickRandom);
            delete pickRandom;
        }
        std::sort(pivotCandidates.begin(), pivotCandidates.end());
        short pivotIndex = ((*pivotCandidates.begin() + *(pivotCandidates.end() - 1)) >> 1) / 2;
        /*
        what type should the pivot have???? 
        ?? pivot = ????
        */

        std::vector<std::string>::iterator itRight = unsortedVector.begin();
        std::vector<std::string>::iterator itLeft = unsortedVector.begin();
        do
        {
            if (false/*ifTwoStringShoulBeInterchanged()*/)
            {
                /* code */
            }
            
        } while (false/* condition */);
        
    }
};
