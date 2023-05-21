/**
 * @author rixte_marine
 * @file Sound.hpp
 * @date 25/10/2020
 * @brief Permet de gérer les capteurs de lumière
 *
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include "Sensor.hpp"
#include <variant>
#include <string>

/**
* @class Sound
* @brief Permet de gérer les capteurs de son
*/
class Sound : public Sensor
{
    private:

        /**
		* @brief Variable qui permet de générer une valeur de type int de manière uniforme selon l'interval choisit
		*/
        std::uniform_int_distribution<int>m_distrib;
        /**
        * @brief Variable de type sensor Data qui contient un entier et l'identifiant du capteur qui gère la lumière
        */
        sensorData m_sensorSound;
    
    public:

        /**
	    * @brief Permet de créer une nouvelle instance d'un objet capteur de son 
		*/
        Sound();

        /**
	    * @brief Destructeur
		*/
        ~Sound();

        /**
	    * @brief Permet de générer une valeur aléatoire entre 20 et 120 décibels, mesure le son que l'on entend dans la cabine de l'avion
        * @return Retourne une variable de type sensorData
		*/
        sensorData aleaGenVal() override;
 
};

#endif // SOUND_HPP
