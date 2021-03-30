void setup(){
  Serial.begin(9600);
}

void loop() {
    int level =  analogRead(A0);
    //level = (level-20/10);
    Serial.println(level);
    delay(100);
}
