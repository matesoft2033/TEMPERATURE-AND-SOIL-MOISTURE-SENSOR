// RED LEDS
#define RED1 2
#define RED2 3
#define RED3 4
#define RED4 5
#define RED5 6

// BLUE LEDS
#define BLUE1 8
#define BLUE2 9
#define BLUE3 10 
#define BLUE4 11
#define BLUE5 12

// Ranges
#define RANGE1 20
#define RANGE2 40
#define RANGE3 60
#define RANGE4 80
#define RANGE5 100
//
#define MAX_ANALOG 876
#define DEFAULT 0
#define MAX_PERCENTAGE 100
#define MAX_ANALOG1 358
#define LOW_ANALOG1 20
#define MAX_DEGREE 125
#define LOW_DEGREE -40
// Delay
#define TIME 800
// 2 Objects
float temp;
int humidity;
float analog_value;
float analog_value1;
void setup(){
  
  Serial.begin(9600);
  
  for (int red = 2; red <=6; red++) {
  	pinMode(red, OUTPUT);
  }
  
  for (int blue = 8; blue <=12; blue++) {
  	pinMode(blue, OUTPUT);
  }
  
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop()
{
  // Process Of Checking Humidity
  
  analog_value = analogRead(A0);
  humidity = map(analog_value, DEFAULT, MAX_ANALOG, DEFAULT, MAX_PERCENTAGE);
  
  
  Serial.print("Now Humidity is: ");
  Serial.print(humidity);
  Serial.println("%");
  delay(TIME);
  if (humidity <= RANGE1) {
    digitalWrite(BLUE1, HIGH);
    digitalWrite(BLUE2, LOW);
    digitalWrite(BLUE3, LOW);
    digitalWrite(BLUE4, LOW);
    digitalWrite(BLUE5, LOW);
  }

  if (humidity > RANGE2 && humidity <= RANGE3) {
  	digitalWrite(BLUE1, HIGH);
  	digitalWrite(BLUE2, HIGH);
  	digitalWrite(BLUE3, HIGH);
    digitalWrite(BLUE4, LOW);
    digitalWrite(BLUE5, LOW);
  }
  if (humidity > RANGE3 && humidity <= RANGE4) {
  	digitalWrite(BLUE1, HIGH);
  	digitalWrite(BLUE2, HIGH);
  	digitalWrite(BLUE3, HIGH);
  	digitalWrite(BLUE4, HIGH);
    digitalWrite(BLUE5, LOW);
  }
  if (humidity > RANGE4 && humidity <= RANGE5) {
  	digitalWrite(BLUE1, HIGH);
  	digitalWrite(BLUE2, HIGH);
  	digitalWrite(BLUE3, HIGH);
  	digitalWrite(BLUE4, HIGH);
  	digitalWrite(BLUE5, HIGH);
  }
  
  // Process Of Checking Temperature
  
  analog_value1 = analogRead(A1);
  temp = map(analog_value1, LOW_ANALOG1, MAX_ANALOG1, LOW_DEGREE, MAX_DEGREE);
  
  Serial.print("Now Temperature is: ");
  Serial.print(temp);
  Serial.println("C");
  delay(TIME);
  if (temp <= RANGE1) {
  	digitalWrite(RED1, HIGH);
    digitalWrite(RED2, LOW);
    digitalWrite(RED3, LOW);
    digitalWrite(RED4, LOW);
    digitalWrite(RED5, LOW);
  }
  if (temp > RANGE1 && humidity <= RANGE2) {
  	digitalWrite(RED1, HIGH);
  	digitalWrite(RED2, HIGH);
    digitalWrite(RED3, LOW);
    digitalWrite(RED4, LOW);
    digitalWrite(RED5, LOW);
  }
  if (temp > RANGE2 && humidity <= RANGE3) {
  	digitalWrite(RED1, HIGH);
  	digitalWrite(RED2, HIGH);
    digitalWrite(RED3, HIGH);
    digitalWrite(RED4, LOW);
    digitalWrite(RED5, LOW);
  }
  if (temp > RANGE3 && humidity <= RANGE4) {
  	digitalWrite(RED1, HIGH);
  	digitalWrite(RED2, HIGH);
    digitalWrite(RED3, HIGH);
    digitalWrite(RED4, HIGH);
    digitalWrite(RED5, LOW);
  }
  if (temp > RANGE4 && humidity <= RANGE5) {
  	digitalWrite(RED1, HIGH);
  	digitalWrite(RED2, HIGH);
    digitalWrite(RED3, HIGH);
    digitalWrite(RED4, HIGH);
    digitalWrite(RED5, HIGH);
  }
  
}
