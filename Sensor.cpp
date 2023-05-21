/**
 * @author rixte_marine
 * @file Sensor.cpp
 * @date 15/10/2020
 * @brief Permet de gérer les données renvoyées pas les différents capteurs
*/

#include "Sensor.hpp"
#include <variant>
#include <string>
#include <random>

using namespace std;


Sensor::Sensor() : m_re(time(0))
{
}

Sensor::~Sensor()
{
}


