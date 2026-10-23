const int relayPin = 23;      
const int tdsSensorPin = 34;  

const int tdsThreshold = 500; 

void setup() {
  Serial.begin(115200);
  
  pinMode(relayPin, OUTPUT);
  pinMode(tdsSensorPin, INPUT);
  
  digitalWrite(relayPin, LOW);
  Serial.println("System ready, monitoring TDS level...");
}

void loop() {
  int tdsValue = analogRead(tdsSensorPin);
  
  Serial.print("Current TDS Value: ");
  Serial.println(tdsValue);

  if (tdsValue > tdsThreshold) {
    Serial.println("Alert: High TDS level! Activating pump to recycle water...");
    digitalWrite(relayPin, HIGH); 
  } else {
    Serial.println("Water is clean and within acceptable limits. Pump is off.");
    digitalWrite(relayPin, LOW);  
  }
  
  delay(2000); 
}
