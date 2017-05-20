#include <dht.h>

#define dht_dpin A1

dht DHT;
int microfone = A5; 

void setup()
{
  pinMode(microfone, INPUT);
  
  Serial.begin(9600);
  delay(1000);
}

void loop()
{
   if (digitalRead(microfone))
  {
    Serial.print("Micro=");
    Serial.println(analogRead(microfone));
  }

  
  DHT.read11(dht_dpin); 
  Serial.print("Umi=");
  Serial.print(DHT.humidity);
  Serial.print("% ");
  Serial.print("Temp=");
  Serial.print(DHT.temperature); 
  Serial.println("C");

  
  delay(2000);  
}



/*
 * 
 * const int AOUTpin=4;//the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
const int DOUTpin=8;//the DOUT pin of the CO sensor goes into digital pin D8 of the arduino
const int ledPin=13;//the anode of the LED connects to digital pin D13 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);//sets the baud rate
pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output of the arduino
}

void loop()
{
value= analogRead(AOUTpin);//reads the analaog value from the CO sensor's AOUT pin
limit= digitalRead(DOUTpin);//reads the digital value from the CO sensor's DOUT pin
Serial.print("CO value: ");
Serial.println(value);//prints the CO value
Serial.print("Limit: ");
Serial.print(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(100);
if (limit == HIGH){
digitalWrite(ledPin, HIGH);//if limit has been reached, LED turns on as status indicator
}
else{
digitalWrite(ledPin, LOW);//if threshold not reached, LED remains off
}
}
 */
