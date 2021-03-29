/* 
    AS SUCCINT AS POSSIBBLE
 */
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <ctime>
#include <vector>
#include <random>
#include <iterator>
#include <algorithm>

/*
    MODULISATION PLAN
    √• reader(constructor) : reads vector of shorts
    √• maxNumCounter : gets the size of any (sub-)vector
    √• pivotCandidate Number setter :  sets the number of potential elements one of which will be a pivot.
    √• RNG : random number generator
    ∆• swapSwitch(virtual): determines wheater the two elements which are being investigated should be changed
    x• pivot selector : picks some (one?,three?) elements randomly and set the most neutral value as the pivot
    x• sorter(main?) : while the size of the all the remant vector is one.

    ¡¡¡¡¡¡ As the base class has the most generic form of the hierarchy, it has to available for any vector of any type!!!!!!
*/

class QuickSortAlgorithm
{
private:
    std::vector<short> vec;
    /* 
    do i need to declare the iterator for pivot here? 
    if so, I need to initialise in the constructor 
    */
    std::vector<short>::iterator itP;
    short sizeOfVec;
    short pivotCandNum;

public:
    QuickSortAlgorithm(std::string fileName)
    {
        sizeOfVec = 0;
        pivotCandNum = 1; //the number of candidates one of them can be the pivot
        itP = vec.begin() + getPivotIndex();
        std::ifstream unsorted(fileName);
        if (unsorted.is_open())
        {
            std::string line;
            while (std::getline(unsorted, line))
            {
                vec.push_back(stoi(line));
                sizeOfVec++;
            }
            unsorted.close();
        }
        else
        {
            std::cout << "Oops!" << std::endl;
        }
    }
    virtual bool letItBe(short a, short b)
    {
        /** this is the part that specifies a rule for sort using pivot **/
        if (a < b)
        {
            return true;
        }
        else //a==b?
        {
            return false;
        }
    }
    short getSizeOfaVec(std::vector<short> aVec)
    {
        return aVec.size();
    }
    void setPivotCandNum(short numOfCand)
    {
        pivotCandNum = numOfCand;
    }
    short ranNumGen(void)
    {
        std::srand(std::time(nullptr));
        if (std::rand() < 0)
        {
            return ((-std::rand()) % pivotCandNum);
        }
        else
        {
            return ((std::rand()) % pivotCandNum);
        }
    }
    /*
    • pivot candidates are randomly selected
    */
    short getPivotIndex(void)
    {
        std::vector<short> candidates;
        for (short i = 0; i < pivotCandNum; ++i)
        {
            short *random = new short;
            *random = ranNumGen();
            candidates.push_back(*random);
            delete random;
        }
        /*
        choose the random()-th element
        */
        return *(candidates.begin() + ranNumGen());
    }
    void sort(void)
    {
        std::vector<short>::iterator iP = vec.begin() + getPivotIndex();
        std::vector<short> vecL(vec.begin(), iP - 1);
        std::vector<short>::iterator iL = vecL.begin();
        std::vector<short> vecR(iP + 1, vec.end() - 1);
        std::vector<short>::iterator iR = vecR.begin();
//---------PROPAGATING ITERATION UNIT---------------------------------------------------------------------------------------
        std::vector<short> *leftBuffer = new std::vector<short>;

        for (std::vector<short>::iterator iL = vecL.begin(); iL != vecL.end(); ++iL)
        {
            if (!letItBe(*iL, *iP))
            {
                leftBuffer->push_back(*iL);
                vecL.erase(iL);
            }
        }

        for (std::vector<short>::iterator iR = vecL.begin(); iR != vecL.end(); ++iR)
        {
            if (!letItBe(*iP, *iR))
            {
                vecL.push_back(*iR);
                vecR.erase(iR);
                vecR.insert(vecR.end(), leftBuffer->begin(), leftBuffer->end());
            }
        }
        delete leftBuffer;
//------------------------------------------------------------------------------------------------
        /* how to determine if the sort is finished? 
        : the size of the all the remant vector is one
        */
    }
};

/* 
std::random_device rd;
std::mt19937 mt(rd());

template <typename T>
void quickSort(vector<T> &vec, const int &left, const int &right)
{
    if (right <= left)
    {
        return;
    }
    uniform_int_distribution<int> randInt(left, right);
    int leftArrow = left + 1;
    int rightArrow = right;
    swap(vec[left], vec[randInt(mt)]);
    int current = left;
    bool focusedOnRight = true;
    do
    {
        if (focusedOnRight)
        {
            if (vec[current] >= vec[rightArrow])
            {
                swap(vec[current], vec[rightArrow]);
                current = rightArrow;
                focusedOnRight = !focusedOnRight;
            }
            --rightArrow;
        }
        else
        {
            if (vec[current] <= vec[leftArrow])
            {
                swap(vec[current], vec[leftArrow]);
                current = leftArrow;
                focusedOnRight = !focusedOnRight;
            }
            ++leftArrow;
        }
    } while (rightArrow >= leftArrow);
    quickSort(vec, left, current - 1);
    quickSort(vec, current + 1, right);
}
 
 */