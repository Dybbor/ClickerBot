#pragma once
#include <array>
#include "UtilityHelper.h"

class ClickBot
{
private: 
    UtilityHelper utility;
    std::array<POINT, 11> m_workers;
    POINT m_upgrade_worker;
    POINT m_open_m_restart_office; //menu restart office
    POINT m_restart_office; // restart button office
    POINT m_invite_workers;
    int m_count_restart_scene;
    bool m_exit;
public:
    ClickBot();
    ClickBot(std::array<POINT, 11> workers, POINT upgrade_workers, POINT ascend);
    void start();
    ~ClickBot();
private:
    void getPointsFromClick();
    void inviteWorkers();
    void restartOffice();
    void upgradeWorker(POINT worker, int count_click = 30);
    //must be delete
    void Printworkers();
};

