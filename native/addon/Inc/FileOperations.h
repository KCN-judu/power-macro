#ifndef _FILEOPERATIONS_H_
#define _FILEOPERATIONS_H_

/*headers*/
#include <iostream>
#include <fstream>
#include <string>

/*functions*/
bool openFile(
    std::fstream &file,
    const std::string &fileName,
    const std::ios_base::openmode &mode =
        std::ios_base::in | std::ios_base::out);

bool closeFile(std::fstream &file);

bool readFile(std::fstream &file, std::string &content);

void writeFile(std::fstream &file, const std::string &content);
void writeFileln(std::fstream &file, const std::string &content);

#endif
