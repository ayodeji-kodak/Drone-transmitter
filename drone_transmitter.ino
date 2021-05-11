
const int throttle = A0; //pin A0 to read analog input
const int yaw = A1;
const int pitch = A2;
const int roll = A3;
//Variables:
struct MyData {
  byte THROTTLE;
  byte YAW;
  byte PITCH;
  byte ROLL;
};
MyData data;

void setup() {
  //Input or output?

  pinMode(throttle, INPUT);//Optional
  pinMode(yaw, INPUT);
  pinMode(pitch, INPUT);
  pinMode(roll, INPUT);

  Serial.begin(9600);
}

void loop() {

  data.THROTTLE = analogRead(throttle);//Read and save analog value from potentiometer
  //THROTTLE = constrain (map(THROTTLE, 170, 799, 0, 255), 0, 255);
  data.THROTTLE = mapJoystickValue(data.THROTTLE, 170, 501, 810, true);

  data.YAW = analogRead(yaw);
  data.YAW = mapJoystickValue(data.YAW, 113, 437, 745, true);

  data.PITCH = analogRead(pitch);
  data.PITCH = mapJoystickValue(data.PITCH, 255, 589, 900, true);

  data.ROLL = analogRead(roll);
  data.ROLL = mapJoystickValue(data.ROLL, 283, 590, 920, true);

  Serial.print("Throttle: ");
  Serial.print(data.THROTTLE);

  Serial.print(" Yaw: ");
  Serial.print(data.YAW);

  Serial.print(" Pitch: ");
  Serial.print(data.PITCH);

  Serial.print(" Roll: ");
  Serial.println(data.ROLL);


  delay(500);                          //Small delay

}

int mapJoystickValue(int value, int min, int mid, int max, bool reverse) {
  value = constrain (value, min, max);
  if (value < mid) {
    value = map(value, min, mid, 0, 127);

  }
  else {
    value = map(value, mid, max, 128, 255);
  }
  return (reverse ? value : 255 - value);

}
