#include <ESP8266WiFi.h> // Importa a Biblioteca ESP8266WiFi
#include <PubSubClient.h> // Importa a Biblioteca PubSubClient
#include "StringSplitter.h"


//****************************************
//  Dispositivo de Controle de Iluminação
//  Sub -> (Comando = 1, Comando = 0) -> Se (Comando == 1) Liga Lampada, Se (Comando == 0) Desliga Lampada
//  Pub -> (Comando = 1, Comando = 0) -> Se (Comando == 1) Respota "On", Se (Comando == 0) Respota "Off"
//****************************************


#define TOPICO_SUB  "/house/iluminacao/01"
#define TOPICO_PUB  "/house/confirma/01"

// REDE WIFI

const char* SSID = "Moura";           //Nome da Minha rede Wifi
const char* PASSWORD  = "1q2w3r4t";   // Senha da Minha rede Wifi
//const char* SSID = "autohome"; 
//const char* PASSWORD  = "comida05"; 



//MQTT
const char* BROKER_MQTT ="test.mosquitto.org"; //"10.0.0.198";  // Endereço do Servidor Broker;
int BROKER_PORT = 1883;                         // Porta do Servidor

// USER/PASSWORD MQTT

const char* User_MQTT = "Moura";           // Usuario MQTT
const char* Pass_MQTT = "1q2w3r4t";         // Senha MQTT
//const char* User_MQTT = "autohome";
//const char* Pass_MQTT = "comida05";    


int Rele1 = 5; //R
int Rele2 = 12; //G
int Rele3 = 4; //B
int Contagem = 0;

WiFiClient espClient; // Cria o objeto espClient
PubSubClient MQTT(espClient); // Instancia o Cliente MQTT passando o objeto espClient

void mqtt_callback(char* topic, byte* payload, unsigned int length);

void setup() {
  // put your setup code here, to run once:
  InitPinos();
  InitSerial();
  initWiFi();
  initMQTT();
}

void loop() {
  // put your main code here, to run repeatedly:
//func_Teste();
  verificaConexaoWIFIMQTT();
  MQTT.loop();
//delay(1000);
}
