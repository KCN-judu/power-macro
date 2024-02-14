#ifndef _MACRO_FILE_PROC_H_
#define _MACRO_FILE_PROC_H_

/*headers*/
#include "FileOperations.h"
#include "InteractionQueue.h"
#include <sstream>
#include <iostream>
// #include <bits/stream_iterator.h>
/*functions*/

void procInit();

void miCmdProc(std::queue<std::string> &tokens, InteractionQueue &iq);
void kiCmdProc(std::queue<std::string> &tokens, InteractionQueue &iq);
void diCmdProc(std::queue<std::string> &tokens, InteractionQueue &iq);

void readMacroFile(std::fstream &file, InteractionQueue &iq);
#endif