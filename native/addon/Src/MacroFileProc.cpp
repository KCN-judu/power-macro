#include "MacroFileProc.h"

std::map<std::string, INTERACTION_TYPE> miMap;
std::map<std::string, INTERACTION_TYPE> kiMap;

void procInit()
{
    miMap.insert({"L_DOWN", L_DOWN});
    miMap.insert({"L_UP", L_UP});
    miMap.insert({"R_DOWN", R_DOWN});
    miMap.insert({"R_UP", R_UP});
    miMap.insert({"MID_DOWN", MID_DOWN});
    miMap.insert({"MID_UP", MID_UP});
    miMap.insert({"MOVE", MOVE});
    miMap.insert({"DRAG", DRAG});
    miMap.insert({"SCROLL_UP", SCROLL_UP});
    miMap.insert({"SCROLL_DOWN", SCROLL_DOWN});
    miMap.insert({"L_CLICK", L_CLICK});
    miMap.insert({"R_CLICK", R_CLICK});
    miMap.insert({"DBL_CLICK", DBL_CLICK});
    miMap.insert({"MID_CLICK", MID_CLICK});

    kiMap.insert({"PRESS", PRESS});
    kiMap.insert({"RELEASE", RELEASE});
    kiMap.insert({"TRIGGER", TRIGGER});
}

void miCmdProc(std::queue<std::string> &tokens, InteractionQueue &iq)
{
    MouseInteraction mi;
    std::string cmdHead = tokens.front();
    tokens.pop();
    if (tokens.empty())
    {
        if (cmdHead == "L_CLICK")
        {
            mi.setLeftClick();
        }
        else if (cmdHead == "R_CLICK")
        {
            mi.setRightClick();
        }
        else if (cmdHead == "MID_CLICK")
        {
            mi.setMidClick();
        }
        else if (cmdHead == "DBL_CLICK")
        {
            mi.setDblClick();
        }
        else
        {
            mi.setInterection(miMap[cmdHead]);
        }
    }
    else if (cmdHead == "MOVE" || cmdHead == "DRAG")
    {
        MV_TYPE type = (unsigned char)std::stoi(tokens.front());
        tokens.pop();
        int x = std::stoi(tokens.front());
        tokens.pop();
        int y = std::stoi(tokens.front());
        tokens.pop();
        if (tokens.empty())
        {
            if (cmdHead == "MOVE")
                mi.setMove(type, x, y);
            else
                mi.setDrag(type, x, y);
        }
        else
        {
            int step = std::stoi(tokens.front());
            tokens.pop();
            if (cmdHead == "MOVE")
                mi.setMove(type, x, y, step);
            else
                mi.setDrag(type, x, y, step);
        }
    }
    else if (cmdHead == "SCROLL_UP" || cmdHead == "SCROLL_DOWN")
    {
        int scrollLines = std::stoi(tokens.front());
        tokens.pop();
        if (cmdHead == "SCROLL_UP")
            mi.setScrollUp(scrollLines);
        else
            mi.setScrollDown(-scrollLines);
    }
    iq.pushMi(mi);
}

void kiCmdProc(std::queue<std::string> &tokens, InteractionQueue &iq)
{
    KeyboardInteraction ki;
    std::string cmdHead = tokens.front();
    tokens.pop();
    int key = std::stoi(tokens.front());
    tokens.pop();

    if (cmdHead == "PRESS")
        ki.setPress(key);
    else if (cmdHead == "RELEASE")
        ki.setRelease(key);
    else
        ki.setTrigger(key);

    iq.pushKi(ki);
}

void diCmdProc(std::queue<std::string> &tokens, InteractionQueue &iq)
{
    DelayInteraction di;
    tokens.pop();
    int delay = std::stoi(tokens.front());
    tokens.pop();
    di.setDelay(delay);
    iq.pushDi(di);
}
void readMacroFile(std::fstream &file, InteractionQueue &iq)
{
    std::queue<std::queue<std::string>> cmdQueue;
    while (!file.eof())
    {
        std::string cmd;
        std::queue<std::string> separatedCmd;
        if (readFile(file, cmd))
        {
            std::istringstream iss(cmd);
            std::string cmdElement;
            while (iss >> cmdElement)
            {
                separatedCmd.push(cmdElement);
            }
            cmdQueue.push(separatedCmd);
        }
    }
    while (!cmdQueue.empty())
    {
        if (miMap.find(cmdQueue.front().front()) != miMap.end())
        {
            miCmdProc(cmdQueue.front(), iq);
        }
        else if (kiMap.find(cmdQueue.front().front()) != kiMap.end())
        {
            kiCmdProc(cmdQueue.front(), iq);
        }
        else if (cmdQueue.front().front() == "DELAY")
        {
            diCmdProc(cmdQueue.front(), iq);
        }
        cmdQueue.pop();
    }
}
