#pragma once
#include <Windows.h>
/**

   This class contain mouse and keybord utility.

*/
#define KEY_0 0x30	//ключ 0
#define KEY_1 0x31	//1 ключ
#define KEY_2 0x32	//2 ключ
#define KEY_3 0x33	//3 ключ
#define KEY_4 0x34	//4 ключа
#define KEY_5 0x35	//5 ключей
#define KEY_6 0x36	//6 ключ
#define KEY_7 0x37	//7 ключ
#define KEY_8 0x38	//8 ключей
#define KEY_9 0x39	//9 ключ
                    //
#define KEY_A 0x41	//Ключ
#define KEY_B 0x42	//Ключ B
#define KEY_C 0x43	//Ключ C
#define KEY_D 0x44	//Ключ D
#define KEY_E 0x45	//Клавиша E
#define KEY_F 0x46	//Клавиша F
#define KEY_G 0x47	//Ключ G
#define KEY_H 0x48	//Клавиша H
#define KEY_I 0x49	//Клавиша I
#define KEY_J 0x4A	//Ключ J
#define KEY_K 0x4B	//Ключ K
#define KEY_L 0x4C	//Ключ L
#define KEY_M 0x4D	//Ключ M
#define KEY_N 0x4E	//Ключ N
#define KEY_O 0x4F	//Ключ O
#define KEY_P 0x50	//Ключ P
#define KEY_Q 0x51	//Клавиша Q
#define KEY_R 0x52	//Клавиша R
#define KEY_S 0x53	//Ключ S
#define KEY_T 0x54	//Ключ T
#define KEY_U 0x55	//Ключ U
#define KEY_V 0x56	//Ключ V
#define KEY_W 0x57	//Клавиша W
#define KEY_X 0x58	//Ключ X
#define KEY_Y 0x59	//Клавиша Y
#define KEY_Z 0x5A	//Клавиша Z


class UtilityHelper {
    public: 
        UtilityHelper();
        void clickLeftMouse(POINT point, int sleep_time = 100);
        void holdLeftMouse(POINT point, int hold_time = 1000);
        POINT getPosMouse();
        POINT getClickPosMouse();
        
};