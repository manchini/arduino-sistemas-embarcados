/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float a1 = map(analogRead(A0),0,1023,0,5.0);
  // print out the value you read:
  Serial.print("a1=");
  Serial.println(a1);
  Serial.println("troca pra resistenci");
  delay(5000);        // delay in between reads for stability

  float a2 = map(analogRead(A0),0,1023,0,5.0);
  Serial.print("a2="); 
  Serial.println(a2);
  float ir = float(a2)/float(330);
  Serial.print("IR=");
  Serial.println(ir);
  
  float ri= (float(a1-a2)) / ir;

  Serial.print("RI= ");
  Serial.println(ri);

  Serial.println("FIM .... vou denovo em 5 ");
  delay(5000);
  
/**
 * 
a1 = 83 
a2=17
IR=0.05


 */
  
}
