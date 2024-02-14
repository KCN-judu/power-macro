#ifndef _INTERACTION_H_
#define _INTERACTION_H_

/*headers*/
#include <queue>
#include <Windows.h>
#include <map>
#include <string>

/*definitions*/
enum INTERACTION_TYPE
{
    L_DOWN,
    L_UP,
    R_DOWN,
    R_UP,
    MID_DOWN,
    MID_UP,
    MOVE,
    SCROLL,
    // MOUSE Interactions
    PRESS,
    RELEASE,
    // KEYBOARD Interactions
    DELAY_IT,
    // DELAY Interactions
    DRAG,
    L_CLICK,
    R_CLICK,
    MID_CLICK,
    DBL_CLICK,
    SCROLL_UP,
    SCROLL_DOWN,
    TRIGGER
    // preserved for MACRO
};

/*class*/
class Interaction
{
public:
    Interaction() = default;
    virtual void performInteraction();
    bool empty();
    INTERACTION_TYPE front();

protected:
    void push(const INTERACTION_TYPE &type);
    void pop();

private:
    std::queue<INTERACTION_TYPE> actions;
};

#endif