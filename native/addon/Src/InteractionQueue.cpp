#include "InteractionQueue.h"
#include <iostream>
/*functions*/

void InteractionQueue::pushMi(MouseInteraction mi)
{
    mis.push(mi);
    iq.push(MOUSE);
}

void InteractionQueue::pushKi(KeyboardInteraction ki)
{
    kis.push(ki);
    iq.push(KEYBOARD);
}

void InteractionQueue::pushDi(DelayInteraction di)
{
    dis.push(di);
    iq.push(DELAY);
}

void InteractionQueue::autoPop()
{
    if (iq.front() == MOUSE) {
		if (mis.front().empty())
		{
			mis.pop();
			iq.pop();
		}
    }
    else if (iq.front() == KEYBOARD) {
        if (kis.front().empty())
        {
            kis.pop();
            iq.pop();
        }
    }
	else if (iq.front() == DELAY) {
		if (dis.front().empty())
		{
			dis.pop();
			iq.pop();
		}
	}
}

void InteractionQueue::autoPerform()
{
    autoPop();
    if (iq.front() == MOUSE)
        mis.front().performInteraction();
    else if (iq.front() == KEYBOARD)
        kis.front().performInteraction();
    else if (iq.front() == DELAY)
    {
        dis.front().performInteraction();
    }
}

bool InteractionQueue::empty()
{
    return iq.empty();
}