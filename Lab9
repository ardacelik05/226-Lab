int LED0 = 43;
int LED1 = 44;
int LED2 = 45;
int LED3 = 46;

int SW0 = 38;
int SW1 = 39;
int SW2 = 40;
int SW3 = 41;

bool led1State = false;
int lastSW1State = LOW;

bool systemState = true;
int lastSW3State = LOW;

int mode = 0;              // 0 = normal, 1 = mode1, 2 = mode2, 3 = mode3
int lastSW2State = LOW;

int prevMode = -1;
int modeStep = 0;
unsigned long lastModeTime = 0;
bool blinkState = false;

void allLedsOff() {
  digitalWrite(LED0, LOW);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
}

void setup() {
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(SW0, INPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
}

void loop() {

  // SW3 -> whole system ON/OFF toggle
  int currentSW3State = digitalRead(SW3);

  if (currentSW3State == LOW && lastSW3State == HIGH) {
    systemState = !systemState;
  }

  lastSW3State = currentSW3State;

  // sistem kapalıysa tüm LED'leri söndür
  if (systemState == false) {
    allLedsOff();
    return;
  }

  // SW2 -> mode change on click
  int currentSW2State = digitalRead(SW2);

  if (currentSW2State == LOW && lastSW2State == HIGH) {
    mode++;
    if (mode > 3) {
      mode = 0;
    }
  }

  lastSW2State = currentSW2State;

  // mode değişince timerları sıfırla
  if (mode != prevMode) {
    prevMode = mode;
    modeStep = 0;
    lastModeTime = millis();
    blinkState = false;
    allLedsOff();
  }

  // MODE 0: normal çalışma
  if (mode == 0) {

    // SW0 -> LED0 normal
    if (digitalRead(SW0) == HIGH) {
      digitalWrite(LED0, HIGH);
    } else {
      digitalWrite(LED0, LOW);
    }

    // SW1 -> LED1 toggle
    int currentSW1State = digitalRead(SW1);

    if (currentSW1State == LOW && lastSW1State == HIGH) {
      led1State = !led1State;
    }

    lastSW1State = currentSW1State;
    digitalWrite(LED1, led1State);

    // mode 0'da diğer LED'ler kapalı
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);

    return;
  }

  // MODE 1: all LEDs blink together, 1 second intervals
  if (mode == 1) {
    if (millis() - lastModeTime >= 1000) {
      lastModeTime = millis();
      blinkState = !blinkState;
    }

    digitalWrite(LED0, blinkState);
    digitalWrite(LED1, blinkState);
    digitalWrite(LED2, blinkState);
    digitalWrite(LED3, blinkState);
  }

  // MODE 2: left to right
  else if (mode == 2) {
    if (millis() - lastModeTime >= 1000) {
      lastModeTime = millis();
      modeStep = (modeStep + 1) % 4;
    }

    allLedsOff();

    if (modeStep == 0) digitalWrite(LED0, HIGH);
    if (modeStep == 1) digitalWrite(LED1, HIGH);
    if (modeStep == 2) digitalWrite(LED2, HIGH);
    if (modeStep == 3) digitalWrite(LED3, HIGH);
  }

  // MODE 3: right to left
  else if (mode == 3) {
    if (millis() - lastModeTime >= 1000) {
      lastModeTime = millis();
      modeStep = (modeStep + 1) % 4;
    }

    allLedsOff();

    if (modeStep == 0) digitalWrite(LED3, HIGH);
    if (modeStep == 1) digitalWrite(LED2, HIGH);
    if (modeStep == 2) digitalWrite(LED1, HIGH);
    if (modeStep == 3) digitalWrite(LED0, HIGH);
  }
}
