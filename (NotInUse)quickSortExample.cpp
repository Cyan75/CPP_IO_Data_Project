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
    std::vector<short>::iterator itP;
    short sizeOfVec;
    short pivotCandNum;

public:
    QuickSortAlgorithm(std::string fileName)
    {
        sizeOfVec = 0;
        pivotCandNum = 1; //the number of candidates one of them can be the pivot
        itP = vec.begin();
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
    virtual bool swapOn(short a, short b)
    {
        /** this is the part that specifies a rule for sort using pivot **/
        if (a > b)
        {
            return true;
        }
        else
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
        std::vector<short>::iterator itL = vec.begin();
        std::vector<short>::iterator itR = vec.begin();
        std::vector<short>::iterator itP = vec.begin() + getPivotIndex();
        do
        {
            /* code */
        } while (/* condition */);

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