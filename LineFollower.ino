 #include <QTRSensors.h>

#define CALIBRATION_INTERVAL 400
#define STOP_INTERVAL 800

const int m11Pin = 7;
const int m12Pin = 6;
const int m21Pin = 5;
const int m22Pin = 4;
const int m1Enable = 11;
const int m2Enable = 10;

const int maxSpeed = 255;
const int minSpeed = -255;
const int baseSpeed = 255;
const int calibrationSpeed = 150;

const int sensorCount = 6;

int m1Speed = 0;
int m2Speed = 0;
int motorSpeed;

float kp = 30;
float ki = 0.08;
float kd = 150;

int p = 0;
int i = 0;
int d = 0;

int error = 0;
int lastError = 0;

QTRSensors qtr;

int sensorValues[sensorCount];
int sensors[sensorCount] = {0, 0, 0, 0, 0, 0};


void setup() {
  pinMode(m11Pin, OUTPUT);
  pinMode(m12Pin, OUTPUT);
  pinMode(m21Pin, OUTPUT);
  pinMode(m22Pin, OUTPUT);
  pinMode(m1Enable, OUTPUT);
  pinMode(m2Enable, OUTPUT);
  
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5}, sensorCount);

  delay(500);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  // calibrate the sensor. For maximum grade the line follower should do the movement itself, without human interaction.
  setMotorSpeed(calibrationSpeed, -calibrationSpeed);
  for (uint16_t i = 0; i < 250; i++) {
    qtr.calibrate();
    qtr.read(sensorValues);

    if (sensorValues[0] > 600 && sensorValues[1] < 500) {
      setMotorSpeed(-calibrationSpeed, calibrationSpeed);
    }
    if (sensorValues[sensorCount - 1] > 600 && sensorValues[sensorCount - 2] < 500) {
      setMotorSpeed(calibrationSpeed, -calibrationSpeed);
    }
  }

  digitalWrite(LED_BUILTIN, LOW);
}


void loop() {
  pidControl(kp, ki, kd);
  motorPidControl();
  setMotorSpeed(m1Speed, m2Speed);
}


void pidControl(float kp, float ki, float kd) {
  error = map(qtr.readLineBlack(sensorValues), 0, 5000, -45, 45);

  p = error;
  i = i + error;
  d = error - lastError;
  lastError = error;

  motorSpeed = kp * p + ki * i + kd * d; // = error in this case
}


void motorPidControl() {
  m1Speed = baseSpeed;
  m2Speed = baseSpeed;

  if (error < 0) {
    m1Speed += motorSpeed;
  }
  else if (error > 0) {
    m2Speed -= motorSpeed;
  }

  m1Speed = constrain(m1Speed, minSpeed, maxSpeed);
  m2Speed = constrain(m2Speed, minSpeed, maxSpeed);
}


void setMotorSpeed(int motor1Speed, int motor2Speed) {
   motor1Speed = -motor1Speed;
   motor2Speed = -motor2Speed;
  if (motor1Speed == 0) {
    digitalWrite(m11Pin, LOW);
    digitalWrite(m12Pin, LOW);
    analogWrite(m1Enable, motor1Speed);
  }
  else {
    if (motor1Speed > 0) {
      digitalWrite(m11Pin, HIGH);
      digitalWrite(m12Pin, LOW);
      analogWrite(m1Enable, motor1Speed);
    }
    if (motor1Speed < 0) {
      digitalWrite(m11Pin, LOW);
      digitalWrite(m12Pin, HIGH);
      analogWrite(m1Enable, -motor1Speed);
    }
  }
  if (motor2Speed == 0) {
    digitalWrite(m21Pin, LOW);
    digitalWrite(m22Pin, LOW);
    analogWrite(m2Enable, motor2Speed);
  }
  else {
    if (motor2Speed > 0) {
      digitalWrite(m21Pin, HIGH);
      digitalWrite(m22Pin, LOW);
      analogWrite(m2Enable, motor2Speed);
    }
    if (motor2Speed < 0) {
      digitalWrite(m21Pin, LOW);
      digitalWrite(m22Pin, HIGH);
      analogWrite(m2Enable, -motor2Speed);
    }
  }
}