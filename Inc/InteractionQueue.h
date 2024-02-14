#ifndef _INTERACTION_QUEUE_H_
#define _INTERACTION_QUEUE_H_

#include "KeyboardInteraction.h"
#include "MouseInteraction.h"
#include "DelayInteraction.h"
/*definitions*/

enum INTERACTION_QUEUE_TYPE
{
    MOUSE,
    KEYBOARD,
    DELAY
};
/*class*/

class InteractionQueue
{
public:
    void pushMi(MouseInteraction mi);
    void pushKi(KeyboardInteraction ki);
    void pushDi(DelayInteraction di);
    void autoPop();
    void autoPerform();
    bool empty();

private:
    std::queue<MouseInteraction> mis;
    std::queue<KeyboardInteraction> kis;
    std::queue<DelayInteraction> dis;
    std::queue<INTERACTION_QUEUE_TYPE> iq;
};

#endif