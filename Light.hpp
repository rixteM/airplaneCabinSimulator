/**
 * @author rixte_marine
 * @file Light.hpp
 * @date 25/10/2020
 * @brief Permet de gérer les capteurs de lumière
 *
*/

#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Sensor.hpp"
#include <variant>
#include <string>

/**
* @class Light
* @brief Permet de gérer les capteurs de lumière
*/
class Light : public Sensor
{
    private:

        /**
		* @brief Variable qui permet de générer une valeur de type int de manière uniforme selon l'interval choisit
		*/
        std::uniform_int_distribution<int>m_distrib;
        /**
        * @brief Variable de type sensor Data qui contient un boolen et l'identifiant du capteur qui gère la lumière
        */
        sensorData m_sensorLight;
    
    public:

        /**
	    * @brief Permet de créer une nouvelle instance d'un objet capteur de lumière
		*/
        Light();

        /**
	    * @brief Destructeur
		*/
        ~Light();

        /**
	    * @brief Permet de générer une valeur aléatoire bool vraie ou fausse en fonction de si la lumière est allumée ou non dans la cabine
        * @return Retourne une variable de type sensorData
		*/
        sensorData aleaGenVal() override;
 
};

#endif // LIGHT_HPP
