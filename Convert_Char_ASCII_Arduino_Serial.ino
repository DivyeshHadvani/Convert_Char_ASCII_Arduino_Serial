String incoming;   // for incoming serial data

void setup() {
    Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
}

void loop() {

    // send data only when you receive data:
    if (Serial.available() > 0) 
    {
            // read the incoming byte:
            incoming = Serial.read();
            String mysrr = String(incoming);
            // say what you got:
            Serial.print("I received: ");
            Serial.println(mysrr);
    }
}
