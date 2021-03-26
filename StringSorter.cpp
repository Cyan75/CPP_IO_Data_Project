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
        pivotCandidateNum = 3;
        *(this->inputFileName) = inputFileName;
        *(this->outputFileName) = outputFileName;
        std::ifstream inputFile(*(this->inputFileName));
        if (inputFile.is_open())
        {
            std::string line;
            while (std::getline(inputFile, line))
            {
                unsortedVector.push_back(line);
                sortedVector.push_back(line);
            }
        }
        else
        {
            std::cout << "unable to open the text file" << std::endl;
        }
        /*
            sort
        */
    }
    ~StringSorter()
    {
        delete inputFileName;
        delete outputFileName;
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
    void setPivotCandidateNum(short setPivotCandidateNum)
    {
        pivotCandidateNum = setPivotCandidateNum;
    }

private:
    std::string *inputFileName = new std::string;
    std::string *outputFileName = new std::string;
    short pivotCandidateNum;
    std::vector<std::string> unsortedVector;
    std::vector<std::string> sortedVector;
    bool letItBe(std::string primary, std::string secondary)
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
        if (primaryGoesFirst(itP, itS))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    //special characters? ¿, ú, á, ô ... s???
    bool primaryGoesFirst(std::string::iterator it1, std::string::iterator it2)
    {
        short numP = static_cast<short>(*it1);
        short numS = static_cast<short>(*it2);
        if (numP < numS) // in right order
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
    short getPivotIndex(std::vector<std::string> vectorToBeSorted) //for quicksort
    {
        short max = vectorToBeSorted.size();
        std::vector<short> pivotCandidates;
        /* this vector stores indices of pivot canndidates */
        for (short i = 0; i < pivotCandidateNum; ++i)
        {
            std::srand(std::time(nullptr));
            short *pickRandom = new short;
            *pickRandom = (std::rand() % max);
            pivotCandidates.push_back(*pickRandom);
            delete pickRandom;
        }
        std::sort(pivotCandidates.begin(), pivotCandidates.end());
        return (((*pivotCandidates.begin() + *(pivotCandidates.end() - 1)) >> 1) / 2);
    }
    /*
        what type should the pivot have???? 
        ?? pivot = ????
        */
    std::vector<std::string> sortVector(void)
    {
        //what is the meaning of const?
        std::vector<std::string>::iterator itL = sortedVector.begin();
        std::vector<std::string>::iterator const itP = sortedVector.begin() + getPivotIndex(sortedVector);
        std::vector<std::string>::iterator itR = sortedVector.end() - 1;
        //EXCEPTION WARNING! consider when itR or itL points the same address as itP
        //letItBe(itR,itP)
        do
        {
            /*  if (*itL>*itP){swap!} */
            std::swap(*itL, *itP);
            itL++;
        } while (!letItBe(*itL, *itP));
    }
     /*
    LLLLLLLLLLLLLRRRRRRRRRRRRRRRRRRRRRRR
        LLLLLLLLLLLL -> LLLLLLLLLLL ->  LLLLLLLLRRR 
                                                        -> LLLLLLLL -> ...
                                                        -> RRR -> ...
                                                        
        RRRRRRRRRRRRRRRRRRRRRRR ->  RRRRRRRRRRRRRRRRRRRRRR -> LLLLLRRRRRRRRRRRRRRRRR  
                                                                                        -> LLLLL -> ...
                                                                                        -> RRRRRRRRRRRRRRRRR -> ...
    */
};
