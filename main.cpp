#include "MacroFileProc.h"

int main()
{
    InteractionQueue interactionQueue;
    std::fstream file;
    procInit();
    openFile(file, "commands.txt", std::ios_base::in);
    readMacroFile(file, interactionQueue);
    int msPerTick = 10;
    closeFile(file);
    while (!interactionQueue.empty())
    {
        interactionQueue.autoPerform();
        Sleep(msPerTick);
    }
}