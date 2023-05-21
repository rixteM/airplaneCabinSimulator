/**
* @author rixte_marine
* @file scheduler.hpp
* @date 05/10/2020
* @brief Permet de gérer la fréquence à laquelle il récupère les données des capteurs. Il les transmet ensuite au server
*/

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "Sensor.hpp"
#include "Server.hpp"


/**
* @class Server
* @brief  Permet de gérer la fréquence à laquelle il récupère les données des capteurs. Il les transmet ensuite au server
*/

class Scheduler
{
  private:

    /**
		* @brief Tableau dynamique de type Sensor* qui contient les différents capteurs 
		*/
    std::vector<Sensor*> m_sensorTab;
    /**
		* @brief Tableau dynamique qui contient des floats les différentes fréquences qui permettent de récupérer les données des capteurs 
		*/
    std::vector<float> m_refreshTime;
    /**
    * @brief variable de type time_point qui permet de stocker la valeur l'heure actuelle du système
    */
    std::vector<std::chrono::high_resolution_clock::time_point> m_lastTime;
    /**
    * @brief variable de type Serveur qui permet de stocker les valeurs des capteurs envoyées par le scheduleur
    */
    Server m_logServer;
    /**
    * @brief booléen qui permet d'activer le début du simulateur 
    */
    bool m_isActive;
    /**
    * @brief Fonction récurcive qui permet de récupérer et d'envoyer au server les valeurs générées pas les capteurs à des fréquences différentes 
    */
    void schedule();
    

  public:

    /**
		* @brief Permet de créer une nouvelle instance d'un objet scheduler
		*/
    Scheduler();
        
    /**
    * @brief Destructeur
    */
    ~Scheduler(); 

    /**
    * @brief Permet à l'utilisateur de choisir ou non de mettre en route le simulateur
    */
    void activateTimer();     

};

#endif //SCHEDULER_HPP
