#include <iostream>

#include "UtilityHelper.h"
#include "ClickBot.h"

void func(std::array <int, 5> arr) {
    for (auto it : arr) {
        std::cout << it << std::endl;
    }
}


int main() {

 
    ClickBot bot;
  /*  UtilityHelper uh;
    while (1) {
        POINT p = uh.getPosMouse();
        std::cout << p.x << " " << p.y << std::endl;
    }*/

    return 0;
}