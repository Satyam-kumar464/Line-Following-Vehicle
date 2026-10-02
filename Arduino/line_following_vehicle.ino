// =====================================================
// Line Following Vehicle
// Basic Arduino Control
//
// IR Sensors + Motor Driver + 2 DC Motors
// =====================================================

// -----------------------------
// IR SENSOR PINS
// -----------------------------
#define LEFT_SENSOR  2
#define RIGHT_SENSOR 3

// -----------------------------
// LEFT MOTOR
// -----------------------------
#define ENA 5
#define IN1 8
#define IN2 9

// -----------------------------
// RIGHT MOTOR
// -----------------------------
#define ENB 6
#define IN3 10
#define IN4 11

// Motor speed
int motorSpeed = 150;


// =====================================================
// SETUP
// =====================================================

void setup()
{
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  stopMotors();

  Serial.begin(9600);
}


// =====================================================
// MAIN LOOP
// =====================================================

void loop()
{
  int leftSensor = digitalRead(LEFT_SENSOR);
  int rightSensor = digitalRead(RIGHT_SENSOR);

  Serial.print("Left: ");
  Serial.print(leftSensor);

  Serial.print("  Right: ");
  Serial.println(rightSensor);

  /*
     Assumption:

     LOW  = black line
     HIGH = white surface
  */

  if (leftSensor == LOW && rightSensor == LOW)
  {
    moveForward();
  }

  else if (leftSensor == LOW && rightSensor == HIGH)
  {
    turnLeft();
  }

  else if (leftSensor == HIGH && rightSensor == LOW)
  {
    turnRight();
  }

  else
  {
    stopMotors();
  }
}


// =====================================================
// MOTOR FUNCTIONS
// =====================================================

void moveForward()
{
  // Left motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, motorSpeed);
}


void turnLeft()
{
  // Stop left motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Right motor forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, motorSpeed);
}


void turnRight()
{
  // Left motor forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Stop right motor
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, motorSpeed);
  analogWrite(ENB, 0);
}


void stopMotors()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
