/**
 * @author rixte_marine
 * @file Light.cpp
 * @date 05/10/2020
 * @brief Permet de gérer les capteurs de lumière
*/
#include "Light.hpp"
#include <variant>
#include <string>

using namespace std;

Light::Light() :m_distrib(0,1)
{
  this->m_sensorLight.sensorValue = false;
  this->m_sensorLight.sensorId = LIGHT;
}

Light::~Light()
{   
}

sensorData Light::aleaGenVal()
{
  
  int genValue(this->m_distrib(this->m_re));
  
  if (genValue == 0)  m_sensorLight.sensorValue = false;
  else  m_sensorLight.sensorValue = true;
  return m_sensorLight;
}