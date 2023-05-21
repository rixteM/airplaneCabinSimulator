/**
* @author rixte_marine
* @file Server.hpp
* @date 25/09/2020
* @ Permet de recevoir, de stocker, et d'afficher des données qui proviennent des capteurs
*/

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <variant>
#include <string>
#include <vector>
#include "Sensor.hpp"


/**
* @class Server
* @brief Permet de recevoir, de stocker, et d'afficher des données qui proviennent des capteurs
*/
class Server
{
	private:
		/**
		* @brief Variable de type ostream qui récupère les informations des capteurs pour le envoyer vers la console
		*/
		std::ostream m_consolStream;
		/**
		* @brief Variables de type ofstream qui récupère les informations des capteurs et les envoye vers un fichier
		*/
		std::ofstream m_temperatureStream;
		std::ofstream m_humidityStream;
		std::ofstream m_lightStream;
		std::ofstream m_soundStream;
		/**
		* @brief Variable de type sensorData
		*/
		sensorData  m_sensor;
		
		/**
		* @brief Booléen qui permet de savoir si les données seront affichées sur la consoles
		*/
		bool m_consolActivation;
		/**
		* @brief Booléen qui permet de savoir si les données sont enregistrées dans un fichier
		*/
		bool m_logActivation;

		/**
		* @brief Permet d'écrire les données de Server dans un fichier
		* @param ofstream& file Donne les informations du Server
		*/
		void fileWrite(std::ofstream& stream_p) const;

		/**
		* @brief Permet d'écrire les données de Server sur la console
		* @param ofstream& file Récupère les informations du Server dans un fichier
		*/
		void consolWrite(std::ostream& stream_p) const;


	public:
		/**
		* @brief Permet de créer une nouvelle instance d'un objet server
		*/
		Server();

		/**
		* @brief Permet de créer une nouvelle instance d'un objet en copiant les données un objet de type Serveur
		* @param Server const& serv Référence constante à copier dans la nouvelle instance
		*/
		Server(Server const& serv_p);

		/**
		* @brief Destructeur
		*/
		virtual ~Server();

		/**
		* @brief Surcharge de l'affectation
		* @return Retourne une référence du serveur affecté
		* @param Server& serv Objet de type Server
		*/
		Server& operator=(Server& serv_p);

		/**
		* @brief Surcharge de l'opérateur << de redirection vers la consoles
		* @return Retourne un ostream qui contient les données du Server
		* @param ostream&stream_p Donne les informations du Server
		* @param Server const& serv Référence du fichier dont on veut afficher les données
		*/
		friend std::ostream& operator<<(std::ostream&stream_p, Server const& serv_p);

		/**
		* @brief Surcharge de l'opérateur << de redirection vers un fichier
		* @return Retourne un ofstream qui contient les données du Server
		* @param ofstream&stream_p Donne les informations du Server
		* @param Server const& serv Référence du fichier dont on veut afficher les données
		*/
		friend std::ofstream& operator<<(std::ofstream&stream_p, Server const& serv_p);

		/**
		* @brief Permet de recevoir et de stocker les données envoyées par le scheduler et généré par le capteur
		* @param sensorData value_p Prend en paramètre un sensorData envoyé pas le schduler
		*/
		void dataRcv(sensorData value_p); 
		/**
		* @brief Permet de modifier l'attribut privé m_consolActivation
		* @param bool isActive_p Prend en paramètre un booléen
		*/
		void setConsolActivation(bool isActive_p);
		/**
		* @brief Permet de modifier l'attribut privé m_logActivation
		* @param bool isActive_p Prend en paramètre un booléen
		*/
		void setLogActivation(bool isActive_p);
};

#endif //SERVER_H
