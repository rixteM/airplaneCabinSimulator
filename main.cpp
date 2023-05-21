#include "Server.hpp"
#include "Sensor.hpp"
#include "Humidity.hpp"
#include "Scheduler.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <variant>
#include <chrono>

using namespace std;

/**
* @brief Permet d'activer l'écriture dans la console des valeurs générées pas les capteurs
* @param Server serv_p 
*/
void activateConsol(Server serv_p)
{
    char isActivate;
    bool activation;
    do
    {
        cout << "Voulez vous afficher les données dans la console ? (o/n) ";
        cin >> isActivate; cin.ignore();
    }
    while(isActivate != 'o'&& isActivate != 'n');
    
    if (isActivate == 'o')
    {
      activation = true;
      serv_p.setConsolActivation(activation);
    }
     
    else
    {
      activation = false;
      serv_p.setLogActivation(activation);
    }
}

/**
* @brief Permet d'activer l'écriture dans un fichier des valeurs générées pas les capteurs
* @param Server serv_p 
*/
void activateLog(Server serv_p)
{
    char isActivate;
    bool activation;
    do
    {
        cout << "Voulez vous enregistrer les données des capteurs dans un fichier ? (o/n) ";
        cin >> isActivate; cin.ignore();
    }
    while(isActivate != 'o'&& isActivate != 'n');
        if (isActivate == 'o')
    {
      activation = true;
      serv_p.setConsolActivation(activation);
    }  
    else
    {
      activation = false;
      serv_p.setLogActivation(activation);
    }
}

int main ()
{
  cout << "Bienvenu sur le simulateur de cabine d'avion version 1.0." << endl << endl;
  Server serv1 = Server();

  activateConsol(serv1);
  activateLog(serv1);
  Scheduler scheduler = Scheduler();

  scheduler.activateTimer();
  
  return 0;
}
