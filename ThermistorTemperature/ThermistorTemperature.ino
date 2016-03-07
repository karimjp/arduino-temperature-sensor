void setup() {
  Serial.begin(9600);
  Serial.println("Time Thermistor temperature measurement");
  Serial.println("\n   Vo    Rt");
}

void loop() {
  int decimalPlaces = 1;
  int time = millis()/1000;
  int measureTempRate = 10000;
  int ThermistorPin = 1;  //Analog input pin for thermistor voltage
  int Vo;                 //Integer value of voltage reading
  float R = 9860.0*5;     //Fixed resistance in the voltage divider
  float logRt,Rt,T;               //Resistance of the thermistor

  float c1 = -11.31205094e-03, c2 = 15.44802298e-04, c3 = -28.153182993e-07;
  Vo = analogRead(ThermistorPin

  Vo = analogRead(ThermistorPin);
  Rt = R*(1023.0 / float(Vo) - 1.0);
  logRt = log(Rt);

  //Steinhart Equation
  T = ( 1.0 / (c1 + c2*logRt + c3*logRt*logRt*logRt) ) - 273.15:
  
  Serial.print(" "); Serial.print(time);
  Serial.print(" "); Serial.print(Vo);
  Serial.print(" "); Serial.print(Rt);
  Serial.print(" "); Serial.print(T, decimalPlaces);
  
  delay(measureTempRate);
  
}
