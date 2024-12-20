#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int LED = 6;
const int LED1 = 7;
const int LED2 = 8;
const int LED3 = 9;
const int LED4 = 10;
const int BNT = 11;
const int REACTION_BTN = 12;
const int Buzzer = 5;
bool state;
unsigned long startTime;
bool timerStarted = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(LED, OUTPUT);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(BNT, INPUT_PULLUP);
    pinMode(REACTION_BTN, INPUT_PULLUP);
    pinMode(Buzzer, OUTPUT);

    Serial.begin(9600);
    lcd.init();
    lcd.setBacklight(HIGH);
    lcd.backlight();

    lcd.clear();
    lcd.print("Sistema iniciado");
    delay(2000);
    lcd.clear();
    lcd.print("Pressione inicio");
}

void loop() {
    state = digitalRead(BNT);

    if (state == HIGH && !timerStarted) {
        lcd.clear();
        lcd.print("1...");
        digitalWrite(LED, HIGH);
        tone(Buzzer, 1000);
        delay(500);
        noTone(Buzzer);
        delay(500);

        lcd.clear();
        lcd.print("2...");
        digitalWrite(LED1, HIGH);
        tone(Buzzer, 1000);
        delay(500);
        noTone(Buzzer);
        delay(500);

        lcd.clear();
        lcd.print("3...");
        digitalWrite(LED2, HIGH);
        tone(Buzzer, 1000);
        delay(500);
        noTone(Buzzer);
        delay(500);

        lcd.clear();
        lcd.print("4...");
        digitalWrite(LED3, HIGH);
        tone(Buzzer, 1000);
        delay(500);
        noTone(Buzzer);
        delay(500);

        lcd.clear();
        lcd.print("5...");
        digitalWrite(LED4, HIGH);
        tone(Buzzer, 1000);
        delay(500);
        noTone(Buzzer);
        delay(500);

        lcd.clear();
        lcd.print("Vai!");
        digitalWrite(LED, LOW);
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        digitalWrite(LED4, LOW);

        startTime = millis();
        timerStarted = true;
    }

    if (timerStarted && digitalRead(REACTION_BTN) == HIGH) {
        unsigned long reactionTimeMs = millis() - startTime;
        float reactionTimeSec = reactionTimeMs / 1000.0;
        Serial.print("Tempo de reação: ");
        Serial.print(reactionTimeSec);
        Serial.println(" segundos");

        lcd.clear();
        lcd.print("Tempo de reacao:");
        lcd.setCursor(0, 1);
        lcd.print(reactionTimeSec, 3);  
        lcd.print(" s");

        timerStarted = false;
        delay(2000);
    }
}
