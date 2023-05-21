/**
 * @author rixte_marine
 * @file Sound.cpp
 * @date 05/10/2020
 * @brief Permet de gérer les capteurs de lumière
*/
#include "Sound.hpp"
#include <variant>
#include <string>

using namespace std;

Sound::Sound() :m_distrib(20,120)
{
  this->m_sensorSound.sensorValue = 0;
  this->m_sensorSound.sensorId = SOUND;
}

Sound::~Sound()
{   
}

sensorData Sound::aleaGenVal()
{
    m_sensorSound.sensorValue = this->m_distrib(this->m_re);
    return m_sensorSound;
}