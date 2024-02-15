#include "MouseInteraction.h"
/*functions*/
void MouseInteraction::setInterection(const INTERACTION_TYPE &type)
{
    this->push(type);
}

void MouseInteraction::setMove(const MV_TYPE &type, const int &x, const int &y, const int &step)
{
    setInterection(MOVE);
    delta.push({x, y});
    this->step.push(step);
    moveType.push(type);
}

void MouseInteraction::setDrag(const MV_TYPE &type, const int &x, const int &y, const int &step)
{
    setInterection(L_DOWN);
    setMove(type, x, y, step);
    setInterection(L_UP);
}

void MouseInteraction::setScrollUp(const int &scrollLines)
{
    setInterection(SCROLL);
    step.push(scrollLines);
}

void MouseInteraction::setScrollDown(const int &scrollLines)
{
    setInterection(SCROLL);
    step.push(std::move(-scrollLines));
}

void MouseInteraction::setLeftClick()
{
    setInterection(L_DOWN);
    setInterection(L_UP);
}

void MouseInteraction::setRightClick()
{
    setInterection(R_DOWN);
    setInterection(R_UP);
}

void MouseInteraction::setMidClick()
{
    setInterection(MID_DOWN);
    setInterection(MID_UP);
}

void MouseInteraction::setDblClick()
{
    setLeftClick();
    setLeftClick();
}
void MouseInteraction::move()
{
    if (delta.front().x == 0 && delta.front().y == 0 && (moveType.front() & MV_ABSOLUTE) == 0)
    {
        this->pop();
        moveType.pop();
        delta.pop();
        step.pop();
        return;
    }
    getPosition();
    if (moveType.front() & MV_ABSOLUTE)
    {
        if (moveType.front() & MV_STRAIGHT)
        {
            SetCursorPos(delta.front().x, delta.front().y);
            this->pop();
            moveType.pop();
            delta.pop();
            step.pop();
        }
        else
        {
            if (position.x == delta.front().x && position.y != delta.front().y)
            {
                char stepy = step.front() * ((delta.front().y - position.y) > 0 ? 1 : -1);
                SetCursorPos(position.x, position.y + step.front() * stepy);
            }
            else if (position.x != delta.front().x)
            {
                char stepx = step.front() * ((delta.front().x - position.x) > 0 ? 1 : -1);
                SetCursorPos(position.x + step.front() * stepx, position.y);
            }
            else
            {
                this->pop();
                moveType.pop();
                delta.pop();
                step.pop();
                return;
            }
        }
    }
    else
    {
        if (moveType.front() & MV_STRAIGHT)
        {
            SetCursorPos(position.x + delta.front().x, position.y + delta.front().y);
            delta.front().x = 0;
            delta.front().y = 0;
        }
        else
        {
            char stepx = step.front() * delta.front().x > 0 ? 1 : -1;
            char stepy = step.front() * delta.front().y > 0 ? 1 : -1;
            SetCursorPos(position.x + stepx, position.y + stepy);
            delta.front().x -= stepx;
            delta.front().y -= stepy;
        }
    }
}

void MouseInteraction::leftDown()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &ip, sizeof(INPUT));
    this->pop();
}

void MouseInteraction::leftUp()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &ip, sizeof(INPUT));
    this->pop();
}

void MouseInteraction::rightDown()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_RIGHTDOWN;
    SendInput(1, &ip, sizeof(INPUT));
    this->pop();
}

void MouseInteraction::rightUp()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_RIGHTUP;
    SendInput(1, &ip, sizeof(INPUT));
    this->pop();
}

void MouseInteraction::middleDown()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_MIDDLEDOWN;
    SendInput(1, &ip, sizeof(INPUT));
    this->pop();
}

void MouseInteraction::middleUp()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_MIDDLEUP;
    SendInput(1, &ip, sizeof(INPUT));
    this->pop();
}

void MouseInteraction::scroll()
{
    INPUT ip = {0};
    ip.type = INPUT_MOUSE;
    ip.mi.dwFlags = MOUSEEVENTF_WHEEL;
    ip.mi.mouseData = WHEEL_DELTA * step.front();
    SendInput(1, &ip, sizeof(INPUT));
    step.pop();
    this->pop();
}

void MouseInteraction::getPosition()
{
    POINT pos;
    GetCursorPos(&pos);
    position.x = pos.x;
    position.y = pos.y;
}

void MouseInteraction::performInteraction()
{
    switch (this->front())
    {
    case L_DOWN:
        leftDown();
        break;

    case L_UP:
        leftUp();
        break;

    case R_DOWN:
        rightDown();
        break;

    case R_UP:
        rightUp();
        break;

    case MID_DOWN:
        middleDown();
        break;

    case MID_UP:
        middleUp();
        break;

    case MOVE:
        move();
        break;

    case SCROLL:
        scroll();
        break;
    }
}