/**
 * @author rixte_marine
 * @file Humidity.cpp
 * @date 05/10/2020
 * @brief Permet de gérer les capteurs d'humidité
*/
#include "Humidity.hpp"
#include <variant>
#include <string>

using namespace std;

Humidity::Humidity() :m_distrib(0,100)
{
  this->m_sensorHumidity.sensorValue = 0;
  this->m_sensorHumidity.sensorId = HUMIDITY;
}

Humidity::~Humidity()
{   
}

sensorData Humidity::aleaGenVal()
{
  m_sensorHumidity.sensorValue = (float) this->m_distrib(this->m_re);  
  return m_sensorHumidity;
}