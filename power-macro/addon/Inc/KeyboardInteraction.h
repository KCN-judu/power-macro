#ifndef _KEYBOARD_INTERACTION_H_
#define _KEYBOARD_INTERACTION_H_

/*headers*/
#include "Interaction.h"

/*definitions*/

/*class*/
class KeyboardInteraction : public Interaction
{
public:
    void setPress(const WORD &key);
    void setRelease(const WORD &key);
    void setTrigger(const WORD &key);
    void performInteraction() override;

private:
    void press();
    void release();

    std::queue<WORD> key;
};

#endif
