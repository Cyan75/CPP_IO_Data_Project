#ifndef DATAAPPENDER_HPP
#define DATAAPPENDER_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
namespace pio
{
    class DataAppender
    {
    private:
        short getFileLines(std::string fileName);

    public:
        DataAppender(std::string originalFileName, std::string additionalFileName, std::string combinedFileName);
        //DataAppender(std::string& originalFileName, std::string& additionalFileName, std::string& combinedFileName) {}
    };
}
#endif