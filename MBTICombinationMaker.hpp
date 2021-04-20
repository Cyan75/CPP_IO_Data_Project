#ifndef MBTICOMBINATIONMAKER_HPP
#define MBTICOMBINATIONMAKER_HPP
#include <iostream>
#include <vector>
#include <fstream>
namespace pio
//generic form for MBTI types : should generate every type
/*use dynamic allocation to prevent using all 16 'slots' for 16 types
repeate the sequence in an order
(allocate -> store a generated one -> cout -> deallocate)
Time to make some ideas for MBTI generation algorithm!!!
*/
{
    class MBTICombinationMaker
    {
    public:
        MBTICombinationMaker(void)
        {
            std::ofstream mbti;
        }
    };
}
#endif