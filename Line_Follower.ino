
const int sensorPins[] = {A0, A1, A2, A3, A4};
const int numSensors = 5;


const int leftMotorPin1 = 4;
const int leftMotorPin2 = 5;
const int rightMotorPin1 = 6;
const int rightMotorPin2 = 7;

void setup() {
  
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);

  
  Serial.begin(9600);
}

void loop() {
  // Reading values
  int sensorValues[numSensors];
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPins[i]);
  }

 
  int total = 0;
  for (int i = 0; i < numSensors; i++) {
    total += sensorValues[i] * (i + 1);
  }
  int position = total / (sensorValues[0] + sensorValues[1] + sensorValues[2] + sensorValues[3] + sensorValues[4]);

  // Adjusting motor speed
  int leftSpeed = 255;
  int rightSpeed = 255;
  if (position < 3) {
    // Turn right
    leftSpeed = 255;
    rightSpeed = 200;
  } else if (position > 3) {
    // Turn left
    leftSpeed = 200;
    rightSpeed = 255;
  }

  // Adjustingn the motors
  analogWrite(leftMotorPin1, leftSpeed);
  analogWrite(leftMotorPin2, LOW);
  analogWrite(rightMotorPin1, rightSpeed);
  analogWrite(rightMotorPin2, LOW);


  Serial.print("Sensor Values: ");
  for (int i = 0; i < numSensors; i++) {
    Serial.print(sensorValues[i]);
    Serial.print(" ");
  }
  Serial.print("Position: ");
  Serial.println(position);

  // Add a delay to prevent rapid changes
  delay(100);
}
