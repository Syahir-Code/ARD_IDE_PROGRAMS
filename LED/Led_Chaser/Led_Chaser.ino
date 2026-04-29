void setup() {
  pinMode (5, OUTPUT);
  pinMode (6, OUTPUT);
  pinMode (7, OUTPUT);
  pinMode (8, OUTPUT);
  pinMode (9, OUTPUT);
}

void loop() {
  digitalWrite (5, HIGH);
  digitalWrite (6, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, HIGH);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, HIGH);
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, HIGH);
  digitalWrite (9, LOW);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  digitalWrite (9, HIGH);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, LOW);
  digitalWrite (8, HIGH);
  digitalWrite (9, LOW);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, LOW);
  digitalWrite (7, HIGH);
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  delay (200);

  digitalWrite (5, LOW);
  digitalWrite (6, HIGH);
  digitalWrite (7, LOW);
  digitalWrite (8, LOW);
  digitalWrite (9, LOW);
  delay (200);
}
