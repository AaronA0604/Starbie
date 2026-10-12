const int RED_LED = 8;
const int GREEN_LED = 9;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Start in the no-threat state.
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  // Communicate with the Python API.
  Serial.begin(9600);
}

void loop() {
  // Wait for a command from Python.
  while (Serial.available() > 0) {
    char command = Serial.read();

    if (command == '1') {
      // Collision predicted: red ON, green OFF.
      digitalWrite(RED_LED, HIGH);
      digitalWrite(GREEN_LED, LOW);
    }
    else if (command == '0') {
      // No collision predicted: green ON, red OFF.
      digitalWrite(RED_LED, LOW);
      digitalWrite(GREEN_LED, HIGH);
    }
  }
}