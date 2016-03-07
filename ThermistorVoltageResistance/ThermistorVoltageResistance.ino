void setup() {
  Serial.begin(9600);
  Serial.println("Thermistor voltage and resistance measurement");
  Serial.println("\n   Vo    Rt");
}

void loop() {
  int ThermistorPin = 1;  //Analog input pin for thermistor voltage
  int Vo;                 //Integer value of voltage reading
  float R = 9860.0*5;     //Fixed resistance in the voltage divider
  float Rt;               //Resistance of the thermistor

  Vo = analogRead(ThermistorPin);
  Rt = R*(1023.0 / float(Vo) - 1.0);

  Serial.print(" "); Serial.print(Vo);
  Serial.print(" "); Serial.print(Rt);
  Serial.print(" ");
  delay(1000);
  
}
