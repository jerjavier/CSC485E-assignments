#include<LiquidCrystal.h>
#include<Wire.h>

LiquidCrystal lcd (2, 3, 4, 5, 6, 7); 

const int AirValue = 600;   //you need to replace this value with Value_1
const int WaterValue = 350;  //you need to replace this value with Value_2
int soilMoistureValue = 0;
int soilmoisturepercent=0;
int BH1750address = 0x23;

byte buff[2];

void setup(){
  Wire.begin();
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
  lcd.begin(16,2);
  lcd.print("Light & Moisture");
  lcd.setCursor(0,1);
  lcd.print("     Meter  ");
  delay(2000);
  lcd.clear();
}
 
void loop(){
  int i;
  uint16_t value=0;
  BH1750_Init(BH1750address);
  delay(200);
 soilMoistureValue = analogRead(A0);  //put Sensor insert into soil
Serial.println(soilMoistureValue);
soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  if(2==BH1750_Read(BH1750address) && soilmoisturepercent >= 100){
    value=((buff[0]<<8)|buff[1])/1.2;
    Serial.println("100 %");
    lcd.setCursor(0,0);
    lcd.print("Light: ");
    lcd.print(value);
    lcd.print("LUX");
    lcd.setCursor(0, 1);
    lcd.print("Moisture: 100%");
    delay(150);
    //lcd.clear();
      //delay(150);
  }
else if(2==BH1750_Read(BH1750address) && soilmoisturepercent <=0){
    value=((buff[0]<<8)|buff[1])/1.2;
    Serial.println("0 %");
    lcd.setCursor(0,0);
    lcd.print("Light: ");
    lcd.print(value);
    lcd.print("LUX");
    lcd.setCursor(0,1);
    lcd.print("Moisture: 0%");
    delay(150);
    //lcd.clear();

  //delay(150);
}
else if(2==BH1750_Read(BH1750address) && soilmoisturepercent >0 && soilmoisturepercent < 100){
    value=((buff[0]<<8)|buff[1])/1.2;
    Serial.println("%");
    lcd.setCursor(0,0);
    lcd.print("Light: ");
    lcd.print(value);
    lcd.print("LUX");
    lcd.setCursor(0,1);
    lcd.print("Moisture: ");
    lcd.print(soilmoisturepercent);
    lcd.print("%");
    delay(150);
    //lcd.clear();
}
//delay(150);
 
}
int BH1750_Read(int address) {
  int i=0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address, 2);
  while(Wire.available()) 
  {
    buff[i] = Wire.read();
    i++;
  }
  Wire.endTransmission();  
  return i;
}
 
void BH1750_Init(int address) {
  Wire.beginTransmission(address);
  Wire.write(0x10);
  Wire.endTransmission();
}
