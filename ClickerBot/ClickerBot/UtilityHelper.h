#pragma once
#include <Windows.h>
/**

   This class contain mouse and keybord utility.

*/
#define KEY_0 0x30	//���� 0
#define KEY_1 0x31	//1 ����
#define KEY_2 0x32	//2 ����
#define KEY_3 0x33	//3 ����
#define KEY_4 0x34	//4 �����
#define KEY_5 0x35	//5 ������
#define KEY_6 0x36	//6 ����
#define KEY_7 0x37	//7 ����
#define KEY_8 0x38	//8 ������
#define KEY_9 0x39	//9 ����
                    //
#define KEY_A 0x41	//����
#define KEY_B 0x42	//���� B
#define KEY_C 0x43	//���� C
#define KEY_D 0x44	//���� D
#define KEY_E 0x45	//������� E
#define KEY_F 0x46	//������� F
#define KEY_G 0x47	//���� G
#define KEY_H 0x48	//������� H
#define KEY_I 0x49	//������� I
#define KEY_J 0x4A	//���� J
#define KEY_K 0x4B	//���� K
#define KEY_L 0x4C	//���� L
#define KEY_M 0x4D	//���� M
#define KEY_N 0x4E	//���� N
#define KEY_O 0x4F	//���� O
#define KEY_P 0x50	//���� P
#define KEY_Q 0x51	//������� Q
#define KEY_R 0x52	//������� R
#define KEY_S 0x53	//���� S
#define KEY_T 0x54	//���� T
#define KEY_U 0x55	//���� U
#define KEY_V 0x56	//���� V
#define KEY_W 0x57	//������� W
#define KEY_X 0x58	//���� X
#define KEY_Y 0x59	//������� Y
#define KEY_Z 0x5A	//������� Z


class UtilityHelper {
    public: 
        UtilityHelper();
        void clickLeftMouse(POINT point, int sleep_time = 100);
        void holdLeftMouse(POINT point, int hold_time = 1000);
        POINT getPosMouse();
        POINT getClickPosMouse();
        
};