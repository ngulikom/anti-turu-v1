const int buzzerPin = D2;
const int switchPin = D7;

// Untuk test cepat dulu.
// Ubah durasi intervalBetweenWindows ke 60000 biar jadi 1 menit waktunya mau coba
const unsigned long intervalBetweenWindows = 10000; // 10 detik
const unsigned long windowDuration = 1000;          // 1 detik

enum State {
  WAITING,
  WINDOW_OPEN,
  FAILED_STATE
};

State state = WAITING;

unsigned long stateStartTime = 0;

// true  = tombol ditekan saat HIGH
// false = tombol ditekan saat LOW
const bool pressedIsHigh = true;

bool isButtonPressed() {
  int sw = digitalRead(switchPin);

  if (pressedIsHigh) {
    return sw == HIGH;
  } else {
    return sw == LOW;
  }
}

void buzzerOn() {
  tone(buzzerPin, 2000); // passive buzzer
}

void buzzerOff() {
  noTone(buzzerPin);
}

void enterWaiting() {
  state = WAITING;
  stateStartTime = millis();
  buzzerOff();

  Serial.println("WAITING");
}

void enterWindow() {
  state = WINDOW_OPEN;
  stateStartTime = millis();
  buzzerOn();

  Serial.print("WINDOW_OPEN_DURATION_MS_");
  Serial.println(windowDuration);
}

void enterFailed() {
  state = FAILED_STATE;
  stateStartTime = millis();
  buzzerOff();

  Serial.println("FAILED");
  Serial.println("PRESS_BUTTON_TO_RESET");
}

void setup() {
  Serial.begin(115200);

  pinMode(buzzerPin, OUTPUT);
  pinMode(switchPin, INPUT);

  buzzerOff();

  Serial.println("ESP_ANTI_TURU_1_READY");

  enterWaiting();
}

void loop() {
  unsigned long now = millis();

  if (state == WAITING) {
    if (now - stateStartTime >= intervalBetweenWindows) {
      enterWindow();
    }
  }

  else if (state == WINDOW_OPEN) {
    if (isButtonPressed()) {
      buzzerOff();

      Serial.println("SUCCESS");

      delay(250); // debounce sederhana

      enterWaiting();
    }

    else if (now - stateStartTime >= windowDuration) {
      buzzerOff();

      Serial.println("MISSED_WINDOW");

      enterFailed();
    }
  }

  else if (state == FAILED_STATE) {
    if (isButtonPressed()) {
      Serial.println("RESET_AFTER_FAILED");

      delay(250); // debounce sederhana

      enterWaiting();
    }
  }
}
