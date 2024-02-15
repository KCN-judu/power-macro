#ifndef _DELAY_INTERACTION_H_
#define _DELAY_INTERACTION_H_

/*headers*/
#include "Interaction.h"

/*class*/
class DelayInteraction : public Interaction
{
public:
    void setDelay(const int &delay);
    void performInteraction() override;

private:
    void delay();
    int delay_ms;
};

#endif