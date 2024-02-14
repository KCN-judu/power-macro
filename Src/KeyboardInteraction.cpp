#include "KeyboardInteraction.h"
/*functions*/

void KeyboardInteraction::setPress(const WORD &key)
{
    this->push(PRESS);
    this->key.push(key);
}

void KeyboardInteraction::setRelease(const WORD &key)
{
    this->push(RELEASE);
    this->key.push(key);
}

void KeyboardInteraction::setTrigger(const WORD &key)
{
    setPress(key);
    setRelease(key);
}

void KeyboardInteraction::press()
{
    INPUT ip = {0};
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = key.front();
    ip.ki.dwFlags = 0;
    SendInput(1, &ip, sizeof(INPUT));
    key.pop();
    this->pop();
}

void KeyboardInteraction::release()
{
    INPUT ip = {0};
    ip.type = INPUT_KEYBOARD;
    ip.ki.wVk = key.front();
    ip.ki.dwFlags = KEYEVENTF_KEYUP;
    SendInput(1, &ip, sizeof(INPUT));
    key.pop();
    this->pop();
}

void KeyboardInteraction::performInteraction()
{

    if (this->front() == PRESS)
        press();
    else
        release();
}