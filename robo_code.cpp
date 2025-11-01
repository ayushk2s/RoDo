#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define PIR_PIN 8
#define SERVO_PIN 6

#define LED_YELLOW 2
#define LED_GREEN 3
#define LED_RED 4
#define BUZZER 5

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  servo.attach(SERVO_PIN);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED_YELLOW, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("System Starting...");
  delay(1500);
  lcd.clear();

  servo.write(90);
  delay(500);
}

void loop() {
  // Scan 0° → 180° → 0° continuously (safe range)
  for (int angle = 0; angle <= 180; angle += 5) {
    scan(angle);
  }
  for (int angle = 180; angle >= 0; angle -= 5) {
    scan(angle);
  }
}

void scan(int angle) {
  servo.write(angle);
  delay(80);  // faster response

  // Ultrasonic measurement
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout added
  long distance = duration * 0.034 / 2;

  bool human = digitalRead(PIR_PIN);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Angle:");
  lcd.print(angle);
  lcd.print((char)223);

  if (distance > 0 && distance < 200) {
    lcd.setCursor(0, 1);
    lcd.print("Dist:");
    lcd.print(distance);
    lcd.print("cm");
    digitalWrite(LED_GREEN, HIGH);
  } else {
    digitalWrite(LED_GREEN, LOW);
  }

  // Faster human detection display
  if (human) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("HUMAN DETECTED!");
    lcd.setCursor(0, 1);
    lcd.print(distance);
    lcd.print(" cm");
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER, HIGH);
    delay(300); // reduced delay for quicker refresh
  } else {
    digitalWrite(LED_RED, LOW);
    digitalWrite(BUZZER, LOW);
  }
}
