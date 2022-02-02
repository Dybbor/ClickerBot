#include <iostream>

#include "UtilityHelper.h"
#include "ClickBot.h"
#include <thread>
#include <chrono>
#include <future>

bool check;

void func(std::array <int, 5> arr) {
    for (auto it : arr) {
        std::cout << it << std::endl;
    }
}


void f() {
    while (1) {
        if (GetKeyState(KEY_F)) {
            std::cout << "endl" << std::endl;
            check = true;
            break;
        }
    }
}
int main() {
    ClickBot bot;
    //check = false;
    //std::future<bool> func = std::async(std::launch::async, [] { 
    //    while (1) {
    //        if (GetKeyState(KEY_F)) {
    //            std::cout << "endl" << std::endl;
    //            check = true;
    //            break;
    //        }
    //    }
    //    return true;
    //    });
    //while (!check) {
    //    std::cout << "i can write" << std::endl;;
    //    std::this_thread::sleep_for(std::chrono::seconds(1));
    //}
    //func.get();


    //std::thread t(f);
    //t.detach();
    //while (!check) {
    //
    //    std::cout << "i can write" << std::endl;;
    //    std::this_thread::sleep_for(std::chrono::seconds(1));
    //    
    //}
    /*ClickBot bot;*/
  /*  UtilityHelper uh;
    while (1) {
        POINT p = uh.getPosMouse();
        std::cout << p.x << " " << p.y << std::endl;
    }*/
    //while (1) {

    //    if (GetAsyncKeyState(KEY_G)) {
    //        std::cout << "asdf" << std::endl;
    //    }
    //    if (GetAsyncKeyState(KEY_F)) {
    //        std::cout << "opa" << std::endl;
    //    }
    //}
    //std::cout << "end" << std::endl;
    return 0;
}