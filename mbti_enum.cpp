#include <iostream>
//generic form for MBTI types : should generate every single type
class MBTI
{
public:
    MBTI();
    ~MBTI();
private:
    bool e = true;
    bool n = true;
    bool t = true;
    bool p = true;
    std::string &s;
};
/*use dynamic allocation to prevent using all 16 'slots' for 16 types
repeate the sequence in an order
(allocate -> store a generated one -> cout -> deallocate)
Time to make some ideas for MBTI generation algorithm!!!
*/
int main(void)
{
}