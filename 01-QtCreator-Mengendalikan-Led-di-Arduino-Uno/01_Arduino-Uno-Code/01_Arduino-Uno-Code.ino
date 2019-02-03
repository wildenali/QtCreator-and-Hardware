#define led_1 9
#define led_2 10
#define led_3 11

void setup() {
  // put your setup code here, to run once:
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

  analogWrite(led_1, 0);
  analogWrite(led_2, 0);
  analogWrite(led_3, 0);

  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available()) {
    char pilih_led = Serial.read();
    int kecerahan_led = Serial.parseInt();
    eksekusi_led(pilih_led, kecerahan_led);
  }
  
}

void eksekusi_led(char led, int kecerahan) {
  if(led == 'a'){
    analogWrite(led_1, kecerahan);
    return;
  }
  if(led == 'b'){
    analogWrite(led_2, kecerahan);
    return;
  }
  if(led == 'c'){
    analogWrite(led_3, kecerahan);
    return;
  }

  return;
}
