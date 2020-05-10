//test code

#define PWM_OUT_PIN 5 // pin na riadenie lediek
#define A_MODE analogWrite(PWM_OUT_PIN, (255 * A_MODE_BRIGHT))
#define WORKING_DELAY 600 // delay čítania zmien, pracovný delay

int i = 1;

void setup() {
Serial.begin(9600);
  pinMode(PWM_OUT_PIN, OUTPUT);
}

void loop() {

analogWrite(PWM_OUT_PIN, (255 * i++));
Serial.println(i++);
  delay(WORKING_DELAY);
}
