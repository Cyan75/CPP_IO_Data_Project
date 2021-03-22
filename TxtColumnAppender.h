#ifndef TXTCOLUMNAPPENDER_H
#define TXTCOLUMNAPPENDER_H
#include<string>

class TxtColumnAppender
{
private:
    std::string originalFileName;
    std::string additionalFileName;
    std::string combinedFileName;
    short getFileLines(std::string fileName);

    public:
    TxtColumnAppender(std::string firstFileName, std::string secondFileName, std::string newFileName);
};
#endif