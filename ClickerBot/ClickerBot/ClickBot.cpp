#include "ClickBot.h"
#include <iostream>


ClickBot::ClickBot() {
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
    start();
   
}
ClickBot::ClickBot(std::array<POINT, 11> workers, POINT upgrade_workers, POINT ascend) {
    m_workers = workers;
    m_upgrade_worker = upgrade_workers;
    m_open_m_restart_office = ascend;
}


ClickBot::~ClickBot() {
 
}


/////////////////////////////////////////
// need to add all points!!!!!!!!!!!!
//////////////////////////////////////
void ClickBot::getPointsFromClick() {
    int i = 0;
    for (auto& table : m_workers) {
        table = utility.getClickPosMouse();
    }
    m_upgrade_worker = utility.getClickPosMouse();
    m_open_m_restart_office = utility.getClickPosMouse();
    Printworkers();
}

void ClickBot::inviteWorkers() {
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


void ClickBot::restartOffice() {
    utility.clickLeftMouse(m_open_m_restart_office, 20);
    utility.clickLeftMouse(m_restart_office, 20);
    m_count_restart_office++;
    std::cout << m_count_restart_office << std::endl;
}

void ClickBot::upgradeWorker(POINT worker, int count_click) {
    utility.clickLeftMouse(worker, 300);
    Sleep(200);
    utility.clickLeftMouse(m_upgrade_worker, 200);
    utility.clickLeftMouse(worker, 200);
    utility.clickLeftMouse(m_upgrade_worker, 200);
    utility.holdLeftMouse(m_upgrade_worker, 5000);
    for (int i = 0; (i < count_click) && (!m_exit); ++i) {
        utility.clickLeftMouse(worker, 20);
        if (GetAsyncKeyState(KEY_F)) {
            m_exit = true;
        }
    }
    for (int i = 0; (i < 5) && (!m_exit); ++i) {
        utility.clickLeftMouse(m_upgrade_worker, 20);
        if (GetAsyncKeyState(KEY_F)) {
            m_exit = true;
        }
    }
    if (GetAsyncKeyState(KEY_F)) {
        m_exit = true;
    }
}

void ClickBot::upgradeMaxLvlWorkers() {
    for (int i = 0; (i < 11) && (!m_exit); ++i) {
        utility.clickLeftMouse(m_workers.at(i), 20);
        utility.clickLeftMouse(m_upgrade_worker, 20);
        if (GetAsyncKeyState(KEY_F)) {
            m_exit = true;
        }
    }

}
void ClickBot::scriptOverfarm() {
    while (!m_exit) {
   /*     if (GetAsyncKeyState(KEY_G)) {
            upgradeWorker(m_workers.at(10), 20);
            upgradeWorker(m_workers.at(0), 20);
            upgradeMaxLvlWorkers();
            restartOffice();
            inviteWorkers();
        }*/
      //  upgradeWorker(m_workers.at(9), 20);
        upgradeWorker(m_workers.at(10), 20);
        upgradeWorker(m_workers.at(0), 20);
        upgradeMaxLvlWorkers();
        restartOffice();
        inviteWorkers();
        if (GetAsyncKeyState(KEY_F)) {
            m_exit = true;
        }
    }
}

void ClickBot::start() {
    scriptOverfarm();
}


//must be delete 
void ClickBot::Printworkers() {
    int i = 0;
    for (auto table : m_workers) {
        std::cout << i <<  ": " << table.x << " : " << table.y << std::endl;
        ++i;
    }
    std::cout << "upgrade workers " << m_upgrade_worker.x << ":" << m_upgrade_worker.y << std::endl;;
    std::cout << "upgrade company " << m_open_m_restart_office.x << ":" << m_open_m_restart_office.y << std::endl;;
}
