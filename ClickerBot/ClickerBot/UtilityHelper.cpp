#include "UtilityHelper.h"

UtilityHelper::UtilityHelper() {}


void  UtilityHelper::clickLeftMouse(POINT point, int sleep_time) {
    SetCursorPos(point.x, point.y);
    Sleep(100);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    Sleep(sleep_time);
}

void UtilityHelper::holdLeftMouse(POINT point, int hold_time) {
    SetCursorPos(point.x, point.y);
    Sleep(100);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(hold_time);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
    Sleep(100);
}

POINT UtilityHelper::getPosMouse() {
    POINT p;
    GetCursorPos(&p);
    return p;
}


POINT UtilityHelper::getClickPosMouse() {
    POINT p{-1,-1};
    while (p.x == -1) {
        if (GetAsyncKeyState(VK_LBUTTON)) {
            p = getPosMouse();
            Sleep(300);
        }
    }
    return p;
}