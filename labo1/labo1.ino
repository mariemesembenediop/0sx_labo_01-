const int LED_PIN = 13;
const int NUMBER_OF_FLASHES = 4;
const int DELAY_FLASHES = 250;
const int DELAY_DURATION = 2000;
const int INTENSITY_VARIATION = 2048 / 256;

void EtatAllumer() {
  digitalWrite(LED_PIN, HIGH);
  Serial.println("Allume - 2415655");
  delay(DELAY_DURATION);
}

void EtatClignotement() {
  for (int i = 0; i < NUMBER_OF_FLASHES; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(DELAY_FLASHES);
    digitalWrite(LED_PIN, LOW);
    delay(DELAY_FLASHES);
    
  }
   Serial.println("Clignotement - 2415655");
}

void EtatVariation() {
  
  for (int i=255; i >= 0; i--) {
    analogWrite(LED_PIN, i);
    delay(INTENSITY_VARIATION);
     
  }
  Serial.println("variation - 2415655");
}

void EtatEteint() {
  digitalWrite(LED_PIN, LOW);
  Serial.println("Eteint - 2415655");
  delay(DELAY_DURATION);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  EtatAllumer();
   EtatClignotement();
  EtatVariation();
  EtatEteint();
}
