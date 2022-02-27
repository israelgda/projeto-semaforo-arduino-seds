#define ledVermelhoTA 10
#define ledAmareloTA 9
#define ledVerdeTA 8
#define ledVermelhoTB 13
#define ledAmareloTB 12
#define ledVerdeTB 11

void setup() {
  
  pinMode(ledVermelhoTA, OUTPUT);
  pinMode(ledAmareloTA, OUTPUT);
  pinMode(ledVerdeTA, OUTPUT);
  pinMode(ledVermelhoTB, OUTPUT);
  pinMode(ledAmareloTB, OUTPUT);
  pinMode(ledVerdeTB, OUTPUT);
}

void loop() {

  //Semafóros
  do{
    digitalWrite(ledVerdeTA, HIGH);
    digitalWrite(ledVermelhoTB, HIGH);
    delay(10000);
  }while(digitalRead(2) == 1);
  
  digitalWrite(ledVerdeTA, LOW);
  digitalWrite(ledAmareloTA, HIGH);
  delay(5000);
  
  digitalWrite(ledAmareloTA, LOW);
  digitalWrite(ledVermelhoTB, LOW);

  do{
    digitalWrite(ledVermelhoTA, HIGH);
    digitalWrite(ledVerdeTB, HIGH);
    delay(10000);
  }while(digitalRead(3) == 1);
  
  digitalWrite(ledVerdeTB, LOW);
  digitalWrite(ledAmareloTB, HIGH);
  delay(5000);

  digitalWrite(ledVermelhoTA, LOW);
  digitalWrite(ledAmareloTB, LOW);

}
