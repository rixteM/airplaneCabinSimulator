/**
* @author rixte_marine
* @file sensor.hpp
* @date 05/10/2020
* @brief Classe mère sur laquelle peuvent se baser les différentes classe capteurs
*/

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <fstream>
#include <variant>
#include <string>
#include <random>
/**
* @brief Enumeration qui permet de diférencier les capteurs
*/
enum e_sensorType{TEMPERATURE, HUMIDITY, LIGHT, SOUND};

/**
* @brief Structure qui permet de regrouper la valeur d'un capteur ainsi que son indentifiant
*/
typedef struct 
{ 
  /**
  * @brief variable qui peut être un entier, un réel ou bien un booléen, générée par les capteurs
  */
  std::variant<int, float, bool> sensorValue;
  /**
  * @brief variable de type e_sensorType qui identifie le genre du capteur
  */
  e_sensorType sensorId;
} sensorData;

/**
* @class Server
* @brief Classe mère sur laquelle peuvent se baser les différentes classe capteurs
*/

class Sensor
{
  public:
        /**
		    * @brief Permet de créer une nouvelle instance d'un objet sensor, un capteur
		    */
        Sensor();
        /**
        * @brief Destructeut
        */
        virtual ~Sensor();
        /**
        * @brief Fonction virtuelle qui est implémenté de manière différente dans chaque classe fille de sensor
        */
        virtual sensorData aleaGenVal() = 0;

  protected:
        /**
        * @brief permet de générer des nombre de manière aléatoire
        */
        std::default_random_engine m_re;   
};

#endif //SENSOR_HPP
