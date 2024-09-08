


const int HALLSEN_A = 18; 


volatile long encoderValue = 0;

int interval = 1000;
long previousMillis = 0;
long currentMillis = 0;

int rpm = 0;
boolean measureRpm = false;

void setup() {

  Serial.begin(9600);//Initialize the serial port
  EncoderInit();//Initialize the module
   encoderValue = 0;
   previousMillis = millis();
}

void loop() {
  
  // Update RPM value on every second
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    encoderValue=encoderValue/6;
    // Revolutions per minute (RPM) =
    // (total encoder pulse in 1s / motor encoder output) x 60s
    rpm = ((encoderValue /(float)interval)*60000.0);

int speed = rpm * 0.0933;
    // Only update display when there have readings
    
      

     /* Serial.print(encoderValue);
      Serial.print(" pulse / ");
      Serial.print(ENCODEROUTPUT);
      Serial.print(" pulse per rotation x 60 seconds = ");*/
      Serial.print(speed);
      Serial.println("km/h");
    
    
    encoderValue = 0;
  previousMillis = currentMillis;
  }

}

void EncoderInit()
{
 // Attach interrupt at hall sensor A on each rising signal
  attachInterrupt(digitalPinToInterrupt(HALLSEN_A), updateEncoder, RISING);
}


void updateEncoder()
{
  // Add encoderValue by 1, each time it detects rising signal
  // from hall sensor A
  encoderValue++;
}