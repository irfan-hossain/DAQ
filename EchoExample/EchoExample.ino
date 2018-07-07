

void setup()
{
  // Start serial communication.
  Serial.begin(9600);
}


void loop()
{
    // Check to see if there is data in serial buffer.
    if (Serial.available())
    {
      // Read data from serial buffer and write it back over
      // serial connection.
      Serial.write(Serial.read());
    }
}
