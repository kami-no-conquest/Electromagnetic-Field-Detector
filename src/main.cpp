#include <Arduino.h>
#define NUMREADINGS 25
int senselimit = 1023;
int antenna = 5;
int val = 0;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;
int readings[NUMREADINGS];
int index = 0;
int total = 0;
int average = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
for (int i = 0; i < NUMREADINGS; i++)
 readings[i] = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(antenna);
  if (val >= 1) {
    val = constrain(val, 1, senselimit);
    val = map(val, 1, senselimit, 1, 1023);
    total -= readings [index];
    readings[index] = val;
    total += readings[index];
    index = (index + 1);
    if (index >= NUMREADINGS)
     index = 0;
    average = total / NUMREADINGS;
    if (average > 50) {
      digitalWrite (led1, HIGH);
    }
    else {
      digitalWrite (led2, LOW);
    }
    if (average > 150) {
      digitalWrite (led2, HIGH);
    }
    else {
      digitalWrite (led2, LOW);
    }
    if (average > 250) {
      digitalWrite (led3, HIGH);
    }
    else {
      digitalWrite (led3, LOW);
    }
    if (average > 350) {
      digitalWrite (led4, HIGH);
    }
    else {
      digitalWrite (led4, LOW);
    }
    if (average > 450) {
      digitalWrite (led5, HIGH);
    }
    else {
      digitalWrite (led5, LOW);
    }
    if (average > 550) {
      digitalWrite (led6, HIGH);
    }
    else {
      digitalWrite (led6, LOW);
    }
    if (average > 650) {
      digitalWrite (led7, HIGH);
    }
    else {
      digitalWrite (led7, LOW);
    }
    if (average > 750) {
      digitalWrite (led8, HIGH);
    }
    else {
      digitalWrite (led8, LOW);
    }
    if (average > 850) {
      digitalWrite (led9, HIGH);
    }
    else {
      digitalWrite (led9, LOW);
    }
    if (average > 950) {
      digitalWrite (led10, HIGH);
    }
    else {
      digitalWrite (led10, LOW);
    }
    Serial.println(val);
    delay (100);
  }
}