int btnPin = 9;
int ledPin = 13;
int state = 0;

void setup()
{
  pinMode(btnPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
	state = digitalRead(btnPin);	
  	if (state == HIGH) {
      digitalWrite(ledPin, HIGH);
    } else {
      digitalWrite(ledPin, LOW);
    }
}