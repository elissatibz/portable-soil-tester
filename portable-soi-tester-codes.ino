#include <LiquidCrystal.h>
#include <DallasTemperature.h>
#include<OneWire.h>

#define DS18B20 6

OneWire onewire(DS18B20);
DallasTemperature sensor(&onewire);

LiquidCrystal lcd(12,11,5,4,3,2);
int moisturepin = 1;
int pHpin = 2;
int sensoredpH = 0;
int sensoredMoisture = 0;
float moisture = 0.0;
float pH = 0.0;

void setup(void) {
  sensor.begin();
  lcd.begin(20,4);  
}

void readTemp(){
  sensor.requestTemperatures();
  lcd.setCursor(0,0);
  float temp = sensor.getTempCByIndex(0); 
 if(temp == -127.00){
  lcd.print("CAN'T READ TEMP!");
 }else{
  lcd.print("Temperature: ");
   lcd.print(temp);
  lcd.print(" C");
 }
}



void readMoisture(){
 lcd.setCursor(0,1);
 lcd.print("Moisture: ");
 sensoredMoisture = analogRead(moisturepin);
 moisture = sensoredMoisture/10.24;
 lcd.print(moisture);
 lcd.print("%");
}
void readpH(){
  lcd.setCursor(0,2);
  lcd.print("pH value: ");
  sensoredpH = analogRead(pHpin);
  pH = sensoredpH/(1024.0/14.0);
  lcd.print(pH);
  
}

void loop(void) {
  readTemp();
  readMoisture();
  readpH();
  delay(20);
}
