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

#define PWM_OUT_PIN 8 // pin na riadenie lediek

#define STATUS_LED_PIN 3 // pin na riadenie status žiarovky
#define STATUS_LED_A_MODE analogWrite(STATUS_LED_PIN, (255 * A_MODE_BRIGHT))
#define STATUS_LED_B_MODE digitalWrite(STATUS_LED_PIN, 255)
#define STATUS_LED_OFF_MODE analogWrite(STATUS_LED_PIN, 0)

#define SWITCHPOS_A_PIN 11 // pin na pozíciu A
#define SWITCHPOS_B_PIN 12 // pin na pozíciu B
#define READ_SWITCHPOS_A digitalRead(SWITCHPOS_A_PIN)
#define READ_SWITCHPOS_B digitalRead(SWITCHPOS_B_PIN)

#define STROBESWITCH_IN_PIN 10 // pin na spínač stroboskopu
#define READ_STROBESWITCH digitalRead(STROBESWITCH_IN_PIN)

#define A_MODE analogWrite(PWM_OUT_PIN, (255 * A_MODE_BRIGHT))
#define B_MODE digitalWrite(PWM_OUT_PIN, 255)
#define OFF_MODE analogWrite(PWM_OUT_PIN, 0)

#define FLASH_DELAY 50 // delay blikania stroboskopu
#define WORKING_DELAY 600 // delay čítania zmien, pracovný delay

byte switch_state = 0;
byte last_switch_state = 0;

void setup() {
  pinMode(PWM_OUT_PIN, OUTPUT);
  pinMode(STATUS_LED_PIN, OUTPUT);
  pinMode(SWITCHPOS_A_PIN, INPUT);
  pinMode(SWITCHPOS_B_PIN, INPUT);
  pinMode(STROBESWITCH_IN_PIN, INPUT);

  analogWrite(PWM_OUT_PIN, 0);
  analogWrite(STATUS_LED_PIN, 0);
}

void loop() {
  if (READ_SWITCHPOS_A == HIGH) switch_state = 1;
  if (READ_SWITCHPOS_B == HIGH) switch_state = 2;
  else switch_state = 0;
  
  while (READ_STROBESWITCH == HIGH) {
    STATUS_LED_B_MODE;
    B_MODE;
    delay(FLASH_DELAY);
    STATUS_LED_OFF_MODE;
    OFF_MODE;
    delay(FLASH_DELAY);
  }
  
  while (READ_SWITCHPOS_A == HIGH) {
    STATUS_LED_A_MODE;
    A_MODE;
  }

  if (switch_state != last_switch_state){
    last_switch_state = switch_state;
    switch(switch_state){
    case 2:
      STATUS_LED_B_MODE;
      B_MODE;
      break;
    case 0:
      STATUS_LED_OFF_MODE;     
      OFF_MODE;
      break;
    }
  }
  delay(WORKING_DELAY);
}
