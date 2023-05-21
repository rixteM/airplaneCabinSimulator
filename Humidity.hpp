/**
 * @author rixte_marine
 * @file Humidity.hpp
 * @date 05/10/2020
 * @brief Permet de gérer les capteurs d'humidité
 *
*/

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP

#include "Sensor.hpp"
#include <variant>
#include <string>

/**
* @class Humidity
* @brief Permet de gérer les capteurs d'humidité
*/
class Humidity : public Sensor
{
    private:

        /**
		* @brief Variable qui permet de générer une valeur de type double de manière uniforme selon l'interval choisit
		*/
        std::uniform_real_distribution<double>m_distrib;
        /**
        * @brief Variable de type sensor Data qui contient un boolen et l'identifiant du capteur humidité
        */
        sensorData m_sensorHumidity;
    
    public:

        /**
	    * @brief Permet de créer une nouvelle instance d'un objet capteur d'humidité
		*/
        Humidity();

        /**
	    * @brief Destructeur
		*/
        ~Humidity();

        /**
	    * @brief Permet de générer une valeur aléatoire comprise entre 0 et 100 qui correspond au pourcentage d'humidité dans l'air de la cabine
        * @return Retourne une variable de type sensorData
		*/
        sensorData aleaGenVal() override;
 
};

#endif // HUMIDITY_HPP
