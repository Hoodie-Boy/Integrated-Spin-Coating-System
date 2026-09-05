int Relay_Pin = 8; // Pin connected to the SSR relay
    
void setup() {
  // put your setup code here, to run once:
  pinMode(Relay_Pin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(Relay_Pin, HIGH); // Turn on the relay
    delay(1000); // Wait for 1 second
    digitalWrite(Relay_Pin, LOW); // Turn off the relay
    delay(1000); // Wait for 1 second
}
