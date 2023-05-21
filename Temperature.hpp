/**
 * @author rixte_marine
 * @file Temperature.hpp
 * @date 05/10/2020
 * @brief Permet de gérer les capteurs de température
 *
*/

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP

#include "Sensor.hpp"
#include <variant>
#include <string>

/**
* @class Temperature
* @brief Permet de gérer les capteurs de température
*/
class Temperature : public Sensor
{
    private:

        /**
		* @brief Variable qui permet de générer une valeur de type double de manière uniforme selon l'interval choisit
		*/
        std::uniform_real_distribution<double>m_distrib;
        /**
        * @brief Variable de type sensor Data qui contient un boolen et l'identifiant du capteur de température
        */
        sensorData m_sensorTemperature;
    
    public:

        /**
	    * @brief Permet de créer une nouvelle instance d'un objet capteur d'humidité
		*/
        Temperature();

        /**
	    * @brief Destructeur
		*/
        ~Temperature();

        /**
	    * @brief Permet de générer une valeur aléatoire comprise entre 15 et 30 qui correspond à la température en degré l'air de la cabine
        * @return Retourne une variable de type sensorData
		*/
        sensorData aleaGenVal() override;
 
};

#endif // TEMPERATURE_HPP
