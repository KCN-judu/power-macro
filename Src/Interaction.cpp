#include "Interaction.h"
/*functions*/
void Interaction::performInteraction()
{
}

void Interaction::push(const INTERACTION_TYPE &type)
{
    actions.push(std::move(type));
}

void Interaction::pop()
{
    actions.pop();
}

bool Interaction::empty()
{
    return actions.empty();
}

INTERACTION_TYPE Interaction::front()
{
    return actions.front();
}