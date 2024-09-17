int tempPin = A0;      // Pino de leitura do sensor de temperatura
int motorPin = 9;      // Pino de controle do motor
int ledPin = 8;       // Pino de controle do LED
int buzzerPin = 7;    // Pino de controle da buzina

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);  // Inicializa a comunicação serial
}

void loop() {
  int analogValue = analogRead(tempPin);  // Lê o valor analógico do sensor de temperatura
  float voltage = (analogValue / 1024.0) * 5.0;  // Converte o valor analógico para voltagem
  float temperature = voltage * 100;  // Converte a voltagem para temperatura (em °C para LM35)

  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Aciona o motor se a temperatura for >= 30°C
  if (temperature >= 30) {
    digitalWrite(motorPin, HIGH);
  } else {
    digitalWrite(motorPin, LOW);
  }

  // Aciona LED e buzina se a temperatura for > 50°C
  if (temperature > 50) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);  // Aguarda 1 segundo antes da próxima leitura
}
