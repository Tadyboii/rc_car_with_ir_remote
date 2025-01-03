#include <Arduino.h>
#include <IRremote.hpp>
#include <StopWatch.h>

const int IR_RECEIVER_PIN = 8;
const int LEFT_MOTOR_PIN1 = 3;
const int LEFT_MOTOR_PIN2 = 5;
const int RIGHT_MOTOR_PIN1 = 6;
const int RIGHT_MOTOR_PIN2 = 9;
const int ENA_PIN = 10;
const int ENB_PIN = 11; 

const String MOVE_FORWARD_BUTTON_CODE = "e718ff00";
const String MOVE_BACKWARD_BUTTON_CODE = "ad52ff00";
const String MOVE_RIGHT_BUTTON_CODE = "a55aff00";
const String MOVE_LEFT_BUTTON_CODE = "f708ff00";

String previousButtonCode;
StopWatch timeElapsed;

void setup() {
  timeElapsed.start();
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);
  pinMode(ENA_PIN, OUTPUT);
  pinMode(ENB_PIN, OUTPUT);
  pinMode(LEFT_MOTOR_PIN1, OUTPUT);
  pinMode(LEFT_MOTOR_PIN2, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN1, OUTPUT);
  pinMode(RIGHT_MOTOR_PIN2, OUTPUT);
  previousButtonCode = "0";
}
void forward();
void backward();
void left();
void right();
void stop();

void loop() {
  if(IrReceiver.decode()){
    timeElapsed.reset();
    timeElapsed.start();
    String buttonCode = String(IrReceiver.decodedIRData.decodedRawData, HEX);
    Serial.println(buttonCode);
    // Serial.println(BUTTON_CODE);
    if(buttonCode == MOVE_FORWARD_BUTTON_CODE || (buttonCode == "0" && previousButtonCode == MOVE_FORWARD_BUTTON_CODE)){
      Serial.println("UP!");
      forward();

    }else if(buttonCode == MOVE_BACKWARD_BUTTON_CODE || (buttonCode == "0" && previousButtonCode == MOVE_BACKWARD_BUTTON_CODE)){
      Serial.println("DOWN!");
      backward();

    }else if(buttonCode == MOVE_RIGHT_BUTTON_CODE || (buttonCode == "0" && previousButtonCode == MOVE_RIGHT_BUTTON_CODE)){
      Serial.println("RIGHT!");
      right();

    }else if(buttonCode == MOVE_LEFT_BUTTON_CODE || (buttonCode == "0" && previousButtonCode == MOVE_LEFT_BUTTON_CODE)){
      Serial.println("LEFT!");
      left();
    }

    if(buttonCode != "0"){
      previousButtonCode = buttonCode;
    }
    IrReceiver.resume();
  } 
  if (timeElapsed.elapsed() > 100){
    stop();
  }
}

void forward(){
  analogWrite(ENA_PIN, 100);
  analogWrite(ENB_PIN, 100);
  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
}

void backward(){
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void right(){
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, HIGH);
}

void left(){
  digitalWrite(LEFT_MOTOR_PIN1, HIGH);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, HIGH);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

void stop(){
  digitalWrite(LEFT_MOTOR_PIN1, LOW);
  digitalWrite(LEFT_MOTOR_PIN2, LOW);
  digitalWrite(RIGHT_MOTOR_PIN1, LOW);
  digitalWrite(RIGHT_MOTOR_PIN2, LOW);
}

