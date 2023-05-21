/**
* @author rixte_marine
* @file Server.cpp
* @date 30/09/2020
* @brief Permet de recevoir, de stocker, et d'afficher des données qui proviennent des capteurs
*/

#include "Server.hpp"
#include "Sensor.hpp"
#include <variant>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

Server::Server() : m_consolStream(cout.rdbuf())//m_filestream("data.txt", ios::out)
{
  this->m_consolActivation = true;
  this->m_logActivation = true;
  this->m_temperatureStream.open("./data/sensorTemperature.txt");
  this->m_humidityStream.open("./data/sensorHumidity.txt");
  this->m_lightStream.open("./data/sensorLight.txt");
  this->m_soundStream.open("./data/sensorSound.txt");
  this->m_sensor.sensorValue = 0.f;
  this->m_sensor.sensorId = HUMIDITY;
}
  
Server::Server(Server const &serv_p) :  m_consolStream(NULL) 
{
  this->m_consolActivation = serv_p.m_consolActivation;
  this->m_logActivation = serv_p.m_logActivation;
  this->m_sensor.sensorValue = serv_p.m_sensor.sensorValue;
  this->m_sensor.sensorId = serv_p.m_sensor.sensorId;

}

Server::~Server()
{
  this->m_temperatureStream.close();
  this->m_humidityStream.close();
  this->m_lightStream.close();
  this->m_soundStream.close();
}

void Server::setConsolActivation(bool isActive_p)
{
  this->m_consolActivation = isActive_p;
}

void Server::setLogActivation(bool isActive_p)
{
  this->m_logActivation = isActive_p;
}

ostream& operator<<(ostream&stream_p, Server const& serv_p )
{
  serv_p.consolWrite(stream_p);
  return stream_p;
}

ofstream& operator<<(ofstream&stream_p, Server const& serv_p )
{
  serv_p.fileWrite(stream_p);
  return stream_p;
}

Server&  Server::operator=(Server& serv_p) 
{
  if (this != &serv_p)
  {
    this->m_consolActivation = serv_p.m_consolActivation;
    this->m_logActivation = serv_p.m_logActivation;
    this->m_sensor.sensorValue = serv_p.m_sensor.sensorValue;
    this->m_sensor.sensorId = serv_p.m_sensor.sensorId;
  }
  return *this;
}

void Server::fileWrite(ofstream& stream_p) const
{
  if (m_logActivation)
  {
    switch(this->m_sensor.sensorId)
    {
    case TEMPERATURE:
     stream_p << "Temperature : " << to_string(get<float>((this->m_sensor).sensorValue))<< endl;
      break;

    case HUMIDITY:
     stream_p << "Humidity : " << to_string(get<float>((this->m_sensor).sensorValue))<< endl;
      break;

    case LIGHT:
     stream_p << "Light : " << to_string(get<bool>((this->m_sensor).sensorValue))<< endl;
      break;

    case SOUND:
     stream_p << "Sound : " << to_string(get<int>((this->m_sensor).sensorValue))<< endl;
      break;

    default:
       stream_p << "error";
    }
  }
}

void Server::consolWrite(ostream& stream_p) const
{
  
  if (m_consolActivation)
  {
    switch(this->m_sensor.sensorId)
    {
    case TEMPERATURE:
    
     stream_p << "Temperature : " << to_string(get<float>((this->m_sensor).sensorValue))<< endl;
      break;

    case HUMIDITY:
     stream_p << "Humidity : " << to_string(get<float>((this->m_sensor).sensorValue))<< endl;
      break;

    case LIGHT:
     stream_p << "Light : " << to_string(get<bool>((this->m_sensor).sensorValue))<< endl;
      break;

    case SOUND:
     stream_p << "Sound : " << to_string(get<int>((this->m_sensor).sensorValue))<< endl;
      break;

    default:
     stream_p << "error";
    }   
  }
}

void Server::dataRcv(sensorData value_p)
{
  this->m_sensor = value_p;

  switch(this->m_sensor.sensorId)
  {
    case TEMPERATURE:
      this->m_consolStream << *this << endl;   
      this->m_temperatureStream << *this << endl;
      
      break;

    case HUMIDITY:
      this->m_consolStream << *this << endl;
      this->m_humidityStream << *this << endl;
      break;

    case LIGHT:
      this->m_consolStream << *this << endl;
      this->m_lightStream << *this << endl;
      break;

    case SOUND:
      this->m_consolStream << *this << endl;
      this->m_soundStream << *this << endl;
      break;

    default:
      cout << "error dataRcv" << endl;
  }
  
}
