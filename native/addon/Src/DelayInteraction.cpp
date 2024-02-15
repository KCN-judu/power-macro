#include "DelayInteraction.h"
#include <iostream>
/*functions*/
void DelayInteraction::setDelay(const int &delay)
{
    delay_ms = delay;
    this->push(DELAY_IT);
}

void DelayInteraction::performInteraction()
{
    delay();
}

void DelayInteraction::delay()
{
    if (this->front() == DELAY_IT)
    {
        Sleep(delay_ms);
        this->pop();
    }
}