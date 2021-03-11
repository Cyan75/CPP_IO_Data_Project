#include <iostream>
#include <vector>
#include <fstream>
//generic form for MBTI types : should generate every type
/*use dynamic allocation to prevent using all 16 'slots' for 16 types
repeate the sequence in an order
(allocate -> store a generated one -> cout -> deallocate)
Time to make some ideas for MBTI generation algorithm!!!
*/
class MBTICombinationMaker
{
private:
    std::vector<char> entp = {'E', 'N', 'T', 'P'};
    std::vector<char> isfj = {'I', 'S', 'F', 'J'};

public:
    MBTICombinationMaker(void)
    {
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
    }
};

int main(void)
{
    MBTICombinationMaker *obj = new MBTICombinationMaker;
    delete obj;
    return 0;
}