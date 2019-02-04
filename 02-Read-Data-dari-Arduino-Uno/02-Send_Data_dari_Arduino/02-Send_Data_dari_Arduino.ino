double kirimData;

void setup() {
  Serial.begin(9600);
}

void loop() {
  kirimData = kirimData + 10.1;  
  Serial.print(kirimData);
  Serial.print(",");
  Serial.flush();
  delay(1000);
}
