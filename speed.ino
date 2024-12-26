
volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;
int rpm = 0;
boolean measureRpm = false;

int speed = 0;

void setup() {
  Serial.begin(9600);
  
  EncoderInit();
  encoderValue = 0;
  previousMillis = millis();
}

void loop() {
  
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    encoderValue=encoderValue/6; // number depends on how many interrupt in 1 rev 
    rpm = ((encoderValue /(float)interval)*60000.0);

       speed = rpm * 0.0933;  //rpm to km/h
   
      Serial.print(speed);
      Serial.println("km/h");
    
    
  encoderValue = 0;
  previousMillis = currentMillis;
  }
}



void EncoderInit()
{
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);
}


void updateEncoder()
{
  encoderValue++;
}
