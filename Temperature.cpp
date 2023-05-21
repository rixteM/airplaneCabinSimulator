/**
 * @author rixte_marine
 * @file Temperature.cpp
 * @date 05/10/2020
 * @brief Permet de gérer les capteurs de température
*/
#include "Temperature.hpp"
#include <variant>
#include <string>

using namespace std;

Temperature::Temperature() :m_distrib(15,30)
{
  this->m_sensorTemperature.sensorValue = 0;
  this->m_sensorTemperature.sensorId = TEMPERATURE;
}

Temperature::~Temperature()
{   
}

sensorData Temperature::aleaGenVal()
{
  m_sensorTemperature.sensorValue = (float) this->m_distrib(this->m_re);
  return m_sensorTemperature;
}