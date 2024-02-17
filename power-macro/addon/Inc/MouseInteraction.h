#ifndef _MOUSE_INTERACTION_H_
#define _MOUSE_INTERACTION_H_

/*headers*/
#include "Interaction.h"
#include "Midware.h"

/*definitions*/
typedef unsigned char MV_TYPE;
#define MV_STRAIGHT 0x01
#define MV_SMOOTH 0x02
#define MV_ABSOLUTE 0x04

/*class*/
class MouseInteraction : public Interaction
{
public:
    void setInterection(const INTERACTION_TYPE &type);
    void setMove(const MV_TYPE &type, const int &x, const int &y, const int &step = 1);
    void setDrag(const MV_TYPE &type, const int &x, const int &y, const int &step = 1);
    void setScrollUp(const int &scrollLines = 1);
    void setScrollDown(const int &scrollLines = 1);
    void setLeftClick();
    void setRightClick();
    void setMidClick();
    void setDblClick();
    void performInteraction() override;

private:
    void leftDown();
    void leftUp();
    void rightDown();
    void rightUp();
    void middleDown();
    void middleUp();
    void move();
    void scroll();
    void getPosition();

    std::queue<MV_TYPE> moveType;
    std::queue<Position> delta;
    Position position;
    std::queue<int> step;
};

#endif