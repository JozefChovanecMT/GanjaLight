//test code

#define PWM_OUT_PIN 5 // pin na riadenie lediek
#define WORKING_DELAY 600 // delay čítania zmien, pracovný delay

void setup() {
  pinMode(PWM_OUT_PIN, OUTPUT);
}

void loop() {

analogWrite(PWM_OUT_PIN, (255 * .1));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .2));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .3));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .4));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .5));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .6));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .7));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .8));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .9));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .10));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .11));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .12));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .13));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .14));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .15));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .16));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .17));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .18));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .19));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .21));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .22));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .23));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .24));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .25));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .26));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .27));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .28));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .29));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .30));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .31));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .32));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .33));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .34));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .35));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .36));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .37));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .38));
delay(1000);
analogWrite(PWM_OUT_PIN, (255 * .39));
delay(1000);
  delay(WORKING_DELAY);
}
