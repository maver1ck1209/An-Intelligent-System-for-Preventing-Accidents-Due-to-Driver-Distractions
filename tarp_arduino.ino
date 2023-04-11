int buzzer=5;
char data;
int alco_S=A3;
int alco_v;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(alco_S,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  alco_v=analogRead(alco_S);
  Serial.print(alco_v);
  while(Serial.available()>0 || alco_v<80){
    alco_v=analogRead(alco_S);
    data=Serial.read();
    Serial.println(data);
    if(data=='1' || alco_v<80){
      tone(buzzer,261);
      Serial.print("Buzzer is On");
      Serial.print("Car wont Start");
      delay(200);
      noTone(buzzer);
    }
  }

}