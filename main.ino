#include <Keypad.h>

#define PIN_POTEN A0

#define PIN_HC_TRIG 3
#define PIN_HC_ECHO 2

#define RESET_PIN 13

#define PIN_BUZZER 12

// 1 minute, 60 000ms
#define FORCE_TIME_THRESSHOLD 60000UL
// Detect 1% force changes
// this avoid falsey positives
#define FORCE_THRESSHOLD 1

// Echo timeout from the HC module
#define MEASURE_TIMEOUT 25000UL

// Send notif if open 5s
#define DEPTH_MESURE_THRESSHOLD 5000

// Mailbox distance = 500mm
#define MAIL_BOX_DEPTH 500

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;

unsigned long previous_force_time;
int previous_force;

// 0 = close
// 1 = openning
// 2 = oppenned
byte door_opening = 0;
unsigned long opening_time;

// Authentication PAD
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {7, 6, 5, 4};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS );

// 0 = not authenticated
// 1 = authenticating (typing password)
// 2 = authenticated
byte authentication = 0;
unsigned long auth_timer;
char password[4];
byte current_pos = 0;

const char secret_password[4] = { '1', '3', '5', '9'};

// 5 minutes
const unsigned long AUTH_DURATION = 60000 * 5;
const unsigned long BUZZER_DURATION = 50;

void resetAll() {
  pinMode(RESET_PIN, OUTPUT);
  digitalWrite(RESET_PIN, LOW);
}

int normalize(
  int value,
  int min_value, int max_value,
  int min_result, int max_result
) {
  int ratio = (max_result - min_result);
  float cursor = (float)(value - min_value) / (float)(max_value - min_value);

  return ratio * cursor + min_result;
}

bool matchPassword() {
  for(int i = 0; i < 4; ++i) {
    if(password[i] != secret_password[i]) { return false; }
  }
  return true;
}

void printPassword() {
  Serial.print("Current size : ");
  Serial.println(current_pos);
  Serial.print("Password : ");

  for(int i = 0; i < current_pos; ++i) {
  	Serial.print(password[i]);
  }

  Serial.println("");
}


int readForce(int pin) {
  int val = analogRead(pin);
  // Normalize to be more resilient when poten
  // will be changed to a FSR (force sensor)
  return normalize(val, 0, 1024, 0, 100);
}

void authenticatedManager() {
  if(millis() - auth_timer > BUZZER_DURATION) {
  	noTone(PIN_BUZZER);
  }

  if(millis() - auth_timer > AUTH_DURATION) {
    authentication = 0;
    Serial.println("Authentication ended");
    resetAll();
  }
}

bool authScenario() {
  char key = keypad.getKey();

  if(key != NO_KEY) {
    if(authentication == 0) {
      auth_timer = millis();
      authentication = 1;

      password[0] = key;
      current_pos = 1;
    } else if(authentication == 1) {
      auth_timer = millis();
      password[current_pos] = key;
      current_pos += 1;

      if(current_pos == 4) {
        current_pos = 0;
        if(matchPassword()) {
          Serial.println("Authenticated");
          authentication = 2;
          tone(PIN_BUZZER, 1000);
        } else {
          Serial.println("Wrong password");
          authentication = 0;
        }
      }
    } else {
      authenticatedManager();
    }

    printPassword();
  } else if(authentication == 2) {
  	authenticatedManager();
  }

  return authentication == 2; // Is Authenticated ?
}

void doorScenario() {
  // clean PIN
  digitalWrite(PIN_HC_TRIG, LOW);
  delayMicroseconds(2);

  // send signal
  digitalWrite(PIN_HC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_HC_TRIG, LOW);

  long measure = pulseIn(PIN_HC_ECHO, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;

  if(distance_mm > MAIL_BOX_DEPTH) {
    if(door_opening == 0) {
      door_opening = 1;
      opening_time = millis();
    } else if(door_opening == 1) {
      if(millis() - opening_time > DEPTH_MESURE_THRESSHOLD) {
        door_opening = 2;
        Serial.println("SMS - Door is open");
      }
    } else {
      // The door is open
    }
  } else {
    if(door_opening == 2) {
      Serial.println("SMS - Door is closed");
    }

  	door_opening = 0; // The door is closed
  }
}

void forceScenario() {
  int val = readForce(PIN_POTEN);

  if(millis() - previous_force_time >= FORCE_TIME_THRESSHOLD) {
	previous_force_time = millis();
    if(val - previous_force > FORCE_THRESSHOLD) {
      Serial.println("SMS - Nouveau Courier");
      previous_force = val;
    } else if(val - previous_force < -FORCE_THRESSHOLD) {
      Serial.println("SMS - Courier retirer");
      previous_force = val;
    }
  }
}

void setup() {
  Serial.begin(9600);

  // Buzzer
  pinMode(PIN_BUZZER, OUTPUT);

  // HC PIN
  pinMode(PIN_HC_TRIG, OUTPUT);
  pinMode(PIN_HC_ECHO, INPUT);

  // Initial mesures
  previous_force_time = millis();
  previous_force = readForce(PIN_POTEN);
}

void loop() {
  bool authenticated = authScenario();

  if(!authenticated) {
    doorScenario();
    forceScenario();
  }
  delay(16);
}
