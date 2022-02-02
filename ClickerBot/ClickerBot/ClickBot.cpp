#include "ClickBot.h"
#include <iostream>


ClickBot::ClickBot() {
    //default points for fullscreen 1920 x 1080
    m_workers.at(0) = POINT{ 621,550 };
    m_workers.at(1) = POINT{ 771,438 };
    m_workers.at(2) = POINT{ 737,620 };
    m_workers.at(3) = POINT{ 881,546 };
    m_workers.at(4) = POINT{ 1059,443 };
    m_workers.at(5) = POINT{ 870,714 };
    m_workers.at(6) = POINT{ 1031,612 };
    m_workers.at(7) = POINT{ 1191,503 };
    m_workers.at(8) = POINT{ 1020,780};
    m_workers.at(9) = POINT{ 1171,699};
    m_workers.at(10) = POINT{ 1337,602};
    m_upgrade_worker = POINT{1445,882};
    m_open_m_restart_office = POINT{947,253};
    m_restart_office = POINT{1080,800};
    m_invite_workers = POINT{ 1302, 292 };
    m_exit = false;
    m_count_restart_office = 0;   
}



ClickBot::~ClickBot() {
 
}


void ClickBot::getPointsFromClick() {
    int i = 0;
    std::cout << "click to 11 workers" << std::endl;
    for (auto& table : m_workers) {
        table = utility.getClickPosMouse();
    }
    std::cout << "button upgrade worker" << std::endl;
    m_upgrade_worker = utility.getClickPosMouse();
    std::cout << "open menu restart office" << std::endl;
    m_open_m_restart_office = utility.getClickPosMouse();
    std::cout << "button restart office" << std::endl;
    m_restart_office = utility.getClickPosMouse();
    std::cout << "Are u ready to write point invite_workers ?   \n1-YEEEEEEEEEEEEEEEP" << std::endl;
    while (1) {
        if (GetAsyncKeyState(KEY_1)) {
            m_invite_workers = utility.getClickPosMouse();
            break;
        }
    }
    system("cls");
    std::cout << "invite point was writed!" << std::endl;
    Printworkers();
}

void ClickBot::inviteWorkers() {
    if (!m_exit) {
        Sleep(2000);
        utility.clickLeftMouse(m_workers.at(10), 20);
        utility.clickLeftMouse(m_invite_workers, 20);
        //need to click anywhere to hide ads
        utility.clickLeftMouse(m_workers.at(10), 1000);
        //need to invite 2 times, because not enough money on start level
        utility.clickLeftMouse(m_workers.at(10), 20);
        utility.clickLeftMouse(m_invite_workers, 20);
        Sleep(500);
        utility.clickLeftMouse(m_workers.at(10), 20);
    }
}


void ClickBot::restartOffice() {
    if (!m_exit) {
        utility.clickLeftMouse(m_open_m_restart_office, 20);
        utility.clickLeftMouse(m_restart_office, 20);
        m_count_restart_office++;
        std::cout << "restart office " << m_count_restart_office << " times" << std::endl;
    }
}

void ClickBot::upgradeWorker(POINT worker, int count_click) {
    if (!m_exit) {
        utility.clickLeftMouse(worker, 300);
        Sleep(200);
        utility.clickLeftMouse(m_upgrade_worker, 200);
        utility.clickLeftMouse(worker, 200);
        utility.clickLeftMouse(m_upgrade_worker, 200);
        utility.holdLeftMouse(m_upgrade_worker, 5000);
        for (int i = 0; (i < count_click) && (!m_exit); ++i) {
            utility.clickLeftMouse(worker, 20);
        }
        for (int i = 0; (i < 5) && (!m_exit); ++i) {
            utility.clickLeftMouse(m_upgrade_worker, 20);
        }
    }
}

void ClickBot::upgradeMaxLvlWorkers() {
    if (!m_exit) {
        for (int i = 0; (i < 11) && (!m_exit); ++i) {
            utility.clickLeftMouse(m_workers.at(i), 20);
            utility.clickLeftMouse(m_upgrade_worker, 20);
        }
    }

}
void ClickBot::scriptOverfarm() {
    while (!m_exit) {
        upgradeWorker(m_workers.at(10), 20);
        upgradeWorker(m_workers.at(0), 20);
        upgradeMaxLvlWorkers();
        restartOffice();
        inviteWorkers();
    }
}

void ClickBot::start() {
    std::cout << "Used default points ?   \n1-YES   \n2-NO "<< std::endl;
    while (1) {
        if (GetAsyncKeyState(KEY_1)) {
            std::cout << "will be used default points" << std::endl;
            break;
        }
        if (GetAsyncKeyState(KEY_2)) {
            std::cout << "start to click " << std::endl;
            getPointsFromClick();
            break;
        }
    }

    std::cout << "G - start bot\nF -  stop bot" << std::endl;
    // async thread for tracking key exit
    std::future<bool> triggerExit = std::async(std::launch::async, [&m_exit = m_exit]() {
        while (1) {
            if (GetKeyState(KEY_F)) {
                std::cout << "exit ..." << std::endl;
                m_exit = true;
                break;
            }
        }
        return true;
        });
    while (!m_exit) {
        if (GetAsyncKeyState(KEY_G)) { // start bot
            std::cout << "bot working" << std::endl;
            scriptOverfarm();
            triggerExit.wait();
        }
    }
    std::cout << "bot stoped" << std::endl;
}

//must be delete 
void ClickBot::Printworkers() {
    int i = 0;
    for (auto table : m_workers) {
        std::cout << i <<  ": " << table.x << " : " << table.y << std::endl;
        ++i;
    }
    std::cout << "upgrade workers " << m_upgrade_worker.x << ":" << m_upgrade_worker.y << std::endl;;
    std::cout << "open restart office " << m_open_m_restart_office.x << ":" << m_open_m_restart_office.y << std::endl;;
    std::cout << "restart office " << m_restart_office.x << m_restart_office.x << " : " << m_restart_office.y << std::endl;
    std::cout << "invite workers " << m_invite_workers.x << " : " << m_invite_workers.y << std::endl;
}
