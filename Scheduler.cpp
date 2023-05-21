#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Sound.hpp"
#include <chrono>
#include <unistd.h>
#include <ctime>
using namespace std;

Scheduler::Scheduler() : m_logServer(), m_isActive(true)
{
    this->m_sensorTab.push_back(new Temperature());
    this->m_sensorTab.push_back(new Humidity());
    this->m_sensorTab.push_back(new Light());
    this->m_sensorTab.push_back(new Sound());

    this->m_refreshTime.push_back(1.0);
    this->m_refreshTime.push_back(1.0);
    this->m_refreshTime.push_back(2.0);
    this->m_refreshTime.push_back(3.0);

    for (unsigned i(0); i < this->m_sensorTab.size(); i++)
    {
        this->m_lastTime.push_back(chrono::high_resolution_clock::now());  
    }   
}

Scheduler::~Scheduler()
{
    for (unsigned i(0); i < (this->m_sensorTab).size(); i++)
    {
        delete this->m_sensorTab[i];
    }
}

void Scheduler::schedule()
{
    auto rightNow = std::chrono::high_resolution_clock::now();   
    time_t tt;   
    for(unsigned i = 0; i < (this->m_sensorTab).size(); i++)
    { 
        std::chrono::duration<double> elapsed_seconds = rightNow - this->m_lastTime[i]; // Nombre de secondes qui se sont écoulées depuis la dernière fois que le capteur i s'est allumé  
        if (this->m_refreshTime[i] < elapsed_seconds.count())
        {
            tt = chrono::high_resolution_clock::to_time_t (rightNow);
            cout << ctime(&tt);
            this->m_logServer.dataRcv((this->m_sensorTab[i])->aleaGenVal());  
            this->m_lastTime[i] = rightNow;         
        }
    }
    sleep(1);
    this->schedule(); 
}

void Scheduler::activateTimer()
{
    char isActivate;
    do
    {
        cout << "Pour arrêter le simulateur, faire un Crtl C" << endl;
        cout << "Voulez vous lancer le simulateur ? (o/n) ";
        cin >> isActivate; cin.ignore();
        
    }
    while(isActivate != 'o' && isActivate != 'n');
    
    if (isActivate == 'o')
    {
        this->m_isActive = true;
        schedule();
    } 
    else this->m_isActive = false;
}

