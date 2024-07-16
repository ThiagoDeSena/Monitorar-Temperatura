#ifdef __cplusplus
extern "C" {
#endif
uint8_t temprature_sens_read();
#ifdef __cplusplus
}
#endif
uint8_t temprature_sens_read();

// --- Bibliotecas Auxiliares ---
#include <OneWire.h>
#include <DallasTemperature.h>

// --- Constantes Auxiliares ---
#define ONE_WIRE_BUS 15

// --- Declaração de Objetos ---
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer = { 0x28, 0xAA, 0x76, 0x94, 0x4B, 0x14, 0x01, 0xEA };

int intervalSensor = 2000;
long prevMillisThingSpeak = 0;
int intervalThingSpeak = 15000; // Intervalo minímo para escrever no ThingSpeak write é de 15 segundos


#include <WiFi.h>
const char ssid[] = "VITOR-2G";
const char password[] = "251717rvt";
WiFiClient client;

#include <ThingSpeak.h>
const long CHANNEL = 2596090;
const char *WRITE_API = "ZCFA5K4I5U1XJ286";
const int RelePin = 25; // pino ao qual o Módulo Relé está conectado

// --- Protótipo das Funções ---
void printTemperature(DeviceAddress deviceAddress);

void setup()
{
  pinMode(RelePin, OUTPUT); // seta o pino como saída
  digitalWrite(RelePin, LOW); // seta o pino com nivel logico ALTO
  Serial.begin(115200);
  sensors.begin();      //inicializa sensores
  sensors.setResolution(insideThermometer, 10); //configura para resolução de 10 bits
  Serial.println();
  Serial.println("Envia os dados do sensor para o ThingSpeak usando o ESP32");
  Serial.println();

  WiFi.mode(WIFI_STA); //Modo Station
  ThingSpeak.begin(client);  // Inicializa o ThingSpeak
}

void loop(){

  sensors.requestTemperatures();
  
    
    
 
  // Conecta ou reconecta o WiFi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("Atenção para conectar o SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid, password);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConectado");
  }

  printTemperature(insideThermometer);
  
}


// --- Desenvolvimento das Funções ---
void printTemperature(DeviceAddress deviceAddress)
{
  
  float tempC = sensors.getTempC(deviceAddress);
  
      Serial.print("Temperatura: ");
      Serial.print(tempC);
      Serial.print(" ºC ");

  Serial.print("\n\r");
  
  //Aciona a carga se a temperatura for maior que 32ºC
  if(tempC > 32.00){
    digitalWrite(RelePin,HIGH);
  }else{
    digitalWrite(RelePin,LOW);
  }

  delay(1000);

  if (millis() - prevMillisThingSpeak > intervalThingSpeak) {

    // Configura os campos com os valores
    ThingSpeak.setField(3,tempC);
    

    // Escreve no canal do ThingSpeak 
    int x = ThingSpeak.writeFields(CHANNEL, WRITE_API);
    if (x == 200) {
      Serial.println("Update realizado com sucesso");
    }
    else {
      Serial.println("Problema no canal - erro HTTP " + String(x));
    }

    prevMillisThingSpeak = millis();
  }
  
} //end printTemperature

