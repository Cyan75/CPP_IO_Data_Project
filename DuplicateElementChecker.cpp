#include<iostream>
#include<string>
#include<fstream>

int main(void)
{
    std::string s="hello";
    ;
    for (std::string::iterator it =s.begin(); it != s.end(); ++it)
    {
        std::cout<<*it<<" ";
    }
    
    return 0;
}


