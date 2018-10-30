/*
Arduino     Touch Sensor
  5V         VCC
  GND        GND
  D3         SIG
*/

int TouchSensor = 3; //connected to Digital pin D3
int onLed = 6; //connected to pin 6
int offLed = 13; //connected to pin 13
const int pBuzzer = 12; //connected to pin 12
void setup(){
  Serial.begin(9600); // Communication speed
  pinMode(onLed, OUTPUT);
  pinMode(offLed, OUTPUT);
  pinMode(TouchSensor, INPUT);
  pinMode(pBuzzer, OUTPUT);
}

void loop(){
  if(digitalRead(TouchSensor)==HIGH)       //Read Touch sensor signal
   { 
    digitalWrite(onLed, HIGH);   // if Touch sensor is HIGH, then turn on the onLed
    digitalWrite(offLed, LOW);    // if Touch sensor is HIGH, then turn off the offLed
    tone(pBuzzer, 1000);    // if Touch sensor is HIGH, then turn off the pBuzzer
    Serial.println("Led ON");
   }
  else
   {
    digitalWrite(onLed, LOW);    // if Touch sensor is LOW, then turn off the onLed
    digitalWrite(offLed, HIGH);    // if Touch sensor is LOW, then turn on the offLed
    noTone(pBuzzer);    // if Touch sensor is LOW, then turn off the pBuzzer
    Serial.println("Led OFF");
   }
}
