//
//              __  ____/__    |__  | / /_____  /__    |
//              _  / __ __  /| |_   |/ /___ _  /__  /| |
//              / /_/ / _  ___ |  /|  / / /_/ / _  ___ |
//              \____/  /_/  |_/_/ |_/  \____/  /_/  |_|
//              ___________________________  _________  
//              ___  /____  _/_  ____/__  / / /__  __/  
//              __  /  __  / _  / __ __  /_/ /__  /     
//              _  /____/ /  / /_/ / _  __  / _  /      
//              /_____/___/  \____/  /_/ /_/  /_/  
//            
//           DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//                Copyright (C) 2020 Jozef Chovanec
// 
//  Everyone is permitted to copy and distribute verbatim or modified 
//  copies of this work, and changing it is allowed as long as the name is changed. 
//  
//             DO WHAT THE FUCK YOU WANT TO PUBLIC LICENSE 
//    TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION 
// 
//  0. You just DO WHAT THE FUCK YOU WANT TO.                                   
//

#define A_MODE_BRIGHT .40 // svietivosť v % za bodkou.

#define PWM_OUT_PIN 5 // pin na riadenie lediek

#define STATUS_LED_PIN 6 // pin na riadenie status žiarovky
#define STATUS_LED_ON_MODE digitalWrite(STATUS_LED_PIN, 255)
#define STATUS_LED_OFF_MODE analogWrite(STATUS_LED_PIN, 0)

#define SWITCHPOS_A_PIN 3 // pin na pozíciu A
#define SWITCHPOS_B_PIN 4 // pin na pozíciu B
#define READ_SWITCHPOS_A digitalRead(SWITCHPOS_A_PIN)
#define READ_SWITCHPOS_B digitalRead(SWITCHPOS_B_PIN)

#define STROBESWITCH_IN_PIN 2 // pin na spínač stroboskopu
#define READ_STROBESWITCH digitalRead(STROBESWITCH_IN_PIN)

#define A_MODE analogWrite(PWM_OUT_PIN, (255 * A_MODE_BRIGHT))
#define B_MODE digitalWrite(PWM_OUT_PIN, 255)
#define OFF_MODE analogWrite(PWM_OUT_PIN, 0)

#define WORKING_DELAY 600 // delay čítania zmien, pracovný delay

int switch_state = 0;
int predosly_stav = 0;
long cas = 0;
long dostlacenie = 1000;

void setup() {
  pinMode(PWM_OUT_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  pinMode(SWITCHPOS_A_PIN, INPUT);
  pinMode(SWITCHPOS_B_PIN, INPUT);
  pinMode(STROBESWITCH_IN_PIN, INPUT);
}

void loop() {
  READ_SWITCHPOS_A;
  READ_SWITCHPOS_B;
  READ_STROBESWITCH;

  if (READ_STROBESWITCH == HIGH && millis() - cas > dostlacenie) {
    if (switch_state == 1) {
      switch_state = 0;
    } else {
      switch_state = 1;
    }
    cas = millis();
  }
  
  while (READ_SWITCHPOS_A == HIGH && READ_STROBESWITCH == LOW) {
    STATUS_LED_OFF_MODE;
    A_MODE;
  }

  while (READ_SWITCHPOS_B == HIGH && READ_STROBESWITCH == LOW) {
    STATUS_LED_ON_MODE;
    B_MODE;
  }

  while (READ_SWITCHPOS_A == LOW && READ_SWITCHPOS_B == LOW) {
    STATUS_LED_OFF_MODE;     
    OFF_MODE;
  }

  while (switch_state == 1) {
    B_MODE;
    STATUS_LED_ON_MODE;
    delay(80);
    OFF_MODE;
    STATUS_LED_OFF_MODE;
    delay(80);
    B_MODE;
    STATUS_LED_ON_MODE;
    delay(80);
    OFF_MODE;
    STATUS_LED_OFF_MODE;
    delay(80);
    B_MODE;
    STATUS_LED_ON_MODE;
    delay(80);
    OFF_MODE;
    STATUS_LED_OFF_MODE;
    delay(300);
    B_MODE;
    STATUS_LED_ON_MODE;
    delay(600);
    OFF_MODE;
    STATUS_LED_OFF_MODE;
    delay(80);
    if (READ_STROBESWITCH == HIGH && millis() - cas > dostlacenie) {
    if (switch_state == 1) {
      switch_state = 0;
    } else {
      switch_state = 1;
    }
    cas = millis();
  }
}
  delay(WORKING_DELAY);
}
