// named constant for the pin the sensor is connected to
const int sensorPin = A0;
// room temperature in Celcius
const float baselineTemp = 20.0;


int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;



void setup() {
  // open a serial connection to display values
  Serial.begin(9600);


 // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }




}

void loop() {
  // read the value on AnalogIn pin 0
  // and store it in a variable
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal / 1024.0) * 5.0;

  float temperature = (voltage - .5) * 100;

  sensorValue = analogRead(A1);
  Serial.print("$");
  Serial.print(sensorValue);
  Serial.print("/");
  Serial.print(temperature);
  Serial.print("#");
  
  delay(500);
  }
