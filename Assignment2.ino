int buttonPin = A0;     //Button and LED pin numbers
const int LED_PIN1 = 3;
const int LED_PIN2 = 5;
const int LED_PIN3 = 6;

void setup() 
{
   pinMode(LED_PIN1, OUTPUT);
   pinMode(LED_PIN2, OUTPUT);
   pinMode(LED_PIN3, OUTPUT);

    Serial.begin(9600);           //Serial monitor used to determine limit values
}

void loop() {
  int temp = analogRead(buttonPin);   //Read the analogue input
  Serial.println(temp);               //Display the read value in the Serial monitor

  if(temp < 100)
  { 
  analogWrite(LED_PIN1, 0);
  analogWrite(LED_PIN2, 0);
  analogWrite(LED_PIN3, 0);
  }
  else if (temp < 150)                //Fourth button limit
  {
  analogWrite(LED_PIN1, 18);
  analogWrite(LED_PIN2, 5);
  analogWrite(LED_PIN3, 33);
  }
  else if (temp < 300)                //Third button limit
  {
  analogWrite(LED_PIN1, 13);
  analogWrite(LED_PIN2, 0);
  analogWrite(LED_PIN3, 41);
  }
  else if (temp < 500)                //second button limit
  {
  analogWrite(LED_PIN1, 28);
  analogWrite(LED_PIN2, 5);
  analogWrite(LED_PIN3, 74);
  }
   else                           //first button limit
  {
  analogWrite(LED_PIN1, 227);
  analogWrite(LED_PIN2, 247);
  analogWrite(LED_PIN3, 178);
  }
  delay(100);                         //Delay for stability
}
