// Remplacer "2142752" par votre numéro d'étudiant
const int ledPin = 13;
const int delayDuration = 2000; // Délai de 2 secondes
const int studentNumber[] = {2, 1, 4, 2, 7, 5, 2}; // Numéro d'étudiant, à adapter

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Initialisation de la communication série
}

void loop() {
  // État 1 : Allumé
  digitalWrite(ledPin, HIGH);
  Serial.println("Allume - 2142752");
  delay(delayDuration);

  // État 2 : Clignotement
  int avantDernierChiffre = studentNumber[5];
  int clignotements = ceil(avantDernierChiffre / 2.0) + 1;
  if (avantDernierChiffre == 0) clignotements = 10;
  Serial.println("Clignotement - 2142752");
  for (int i = 0; i < clignotements; i++) {
    digitalWrite(ledPin, HIGH);
    delay(250); // 250 ms allumé
    digitalWrite(ledPin, LOW);
    delay(250); // 250 ms éteint
  }

  // État 3 : Variation d'intensité
  int dernierChiffre = studentNumber[6];
  Serial.println("Variation - 2142752");
  if (dernierChiffre % 2 == 0) {
    for (int i = 0; i <= 255; i++) { // Augmente l'intensité graduellement
      analogWrite(ledPin, i);
      delay(8); // 2048 ms divisé par 256 niveaux
    }
  } else {
    for (int i = 255; i >= 0; i--) { // Diminue l'intensité graduellement
      analogWrite(ledPin, i);
      delay(8); // 2048 ms divisé par 256 niveaux
    }
  }

  // État 4 : Éteint
  digitalWrite(ledPin, LOW);
  Serial.println("Eteint - 2142752");
  delay(delayDuration);
}
