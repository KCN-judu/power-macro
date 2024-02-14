#include "FileOperations.h"

/*functions*/

bool openFile(
    std::fstream &file,
    const std::string &fileName,
    const std::ios_base::openmode &mode)
{
    file.open(fileName, mode);
    if (file.is_open())
        return true;
    return false;
}

bool closeFile(std::fstream &file)
{
    file.close();
    if (!file.is_open())
        return true;
    return false;
}

bool readFile(std::fstream &file, std::string &content)
{
    if (!file.eof())
    {
        std::getline(file, content);
        return true;
    }
    return false;
}

void writeFile(std::fstream &file, const std::string &content)
{
    file << content;
}

void writeFileln(std::fstream &file, const std::string &content)
{
    file << content << std::endl;
}