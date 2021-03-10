#include <iostream>
#include <vector>
#include <fstream>
//generic form for MBTI types : should generate every single type
/*use dynamic allocation to prevent using all 16 'slots' for 16 types
repeate the sequence in an order
(allocate -> store a generated one -> cout -> deallocate)
Time to make some ideas for MBTI generation algorithm!!!
*/
int main(void)
{
    std::vector<char> entp = {'E', 'N', 'T', 'P'};
    std::vector<char> isfj = {'I', 'S', 'F', 'J'};
    std::ofstream mbti("MBTICombination.txt");
    for (short it = 0; it < 16; ++it)
    {
        std::string *pStr = new std::string;
        for (short itMode = 0; itMode < 4; ++itMode)
        {
            if (((it >> itMode) & 1) == 1)
            {
                *pStr = *pStr + entp[itMode];
            }
            else
            {
                *pStr = *pStr + isfj[itMode];
            }
        }
        mbti << *pStr;
        if (it != 15)
        {
            mbti << std::endl;
        }
        delete pStr;
    }
    mbti.close();
    return 0;
}