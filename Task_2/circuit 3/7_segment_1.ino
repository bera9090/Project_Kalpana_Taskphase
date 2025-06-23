
int digit[10] = {
  B1000000, 
  B1111001, 
  B0100100, 
  B0110000, 
  B0011001, 
  B0010010,
  B0000010, 
  B1111000, 
  B0000000,
  B0010000  
};

// Segment pins a to g
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};

const int digit1 = 9;   // Tens 
const int digit2 = 10;  // Ones 

int countstate = 1;           
const int maxCount = 40;      
const int displayDelay = 10;  // Delay per digit in multiplexing
const int stepDelay = 800;    
void setup() {
  // Set segment pins as outputs
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Set digit control pins as outputs
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);

  // Initialize digits OFF
  digitalWrite(digit1, LOW);
  digitalWrite(digit2, LOW);
}

void loop() {
  int tens = countstate / 10;
  int ones = countstate % 10;

 
  unsigned long start = millis();
  while (millis() - start < stepDelay) {
    // Show ones digit
    digitalWrite(digit1, LOW);     
    digitalWrite(digit2, LOW);
    setSegments(digit[ones]);      
    digitalWrite(digit2, HIGH);    
    delay(displayDelay);

    // Show tens digit
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, LOW);
    setSegments(digit[tens]);      
    digitalWrite(digit1, HIGH);    
    delay(displayDelay);
  }


  countstate++;
  if (countstate > maxCount) {
    countstate = 1; 
  }
}

void setSegments(int value) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], bitRead(value, i));
  }
}
