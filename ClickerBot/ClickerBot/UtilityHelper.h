#pragma once
#include <Windows.h>
/**

   This class contain mouse and keybord utility.

*/
#define KEY_F 0x46
#define KEY_G 0x47


class UtilityHelper {
    private: POINT m_point;
    public: 
        UtilityHelper();
        void clickLeftMouse(POINT point, int sleep_time = 100);
        void holdLeftMouse(POINT point, int hold_time = 1000);
        POINT getPosMouse();
        POINT getClickPosMouse();
        
};