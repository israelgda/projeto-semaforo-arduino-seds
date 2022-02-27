#define ledVermelhoTA 10
#define ledAmareloTA 9
#define ledVerdeTA 8
#define ledVermelhoTB 13
#define ledAmareloTB 12
#define ledVerdeTB 11

int estado = 0;
int inicial = 0;
boolean activeTA = false;
boolean activeTB = false;

void setup() {
  pinMode(ledVermelhoTA, OUTPUT);
  pinMode(ledAmareloTA, OUTPUT);
  pinMode(ledVerdeTA, OUTPUT);
  pinMode(ledVermelhoTB, OUTPUT);
  pinMode(ledAmareloTB, OUTPUT);
  pinMode(ledVerdeTB, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(ledVerdeTA) == 0 && digitalRead(ledVerdeTB) == 0 && digitalRead(ledAmareloTA) == 0 && digitalRead(ledAmareloTB) == 0){
    inicial = 1;
  }

  if(digitalRead(2) == 1 && digitalRead(3) == 0){
    estado = 1;
  } else if (digitalRead(2) == 0 && digitalRead(3) == 1){
    estado = 2;
  } else {
    estado = 3;
  }

  switch(estado){
    case 1:
      if(digitalRead(ledVerdeTA) == 1){
        digitalWrite(ledVermelhoTB, HIGH);
        digitalWrite(ledVerdeTA, HIGH);
        activeTB = false;
        activeTA = true;
        delay(3000);
      } else {
        digitalWrite(ledVerdeTB, LOW);
        digitalWrite(ledAmareloTB, HIGH);
        delay(1000);
        digitalWrite(ledAmareloTB, LOW);
        digitalWrite(ledVermelhoTB, HIGH);
        digitalWrite(ledVerdeTA, HIGH);
        digitalWrite(ledVermelhoTA, LOW);
        delay(3000);
      }
      break;
    case 2:
      if(digitalRead(ledVerdeTB) == 1){
        digitalWrite(ledVermelhoTA, HIGH);
        digitalWrite(ledVerdeTB, HIGH);
        delay(3000);
      } else {
        digitalWrite(ledVerdeTA, LOW);
        digitalWrite(ledAmareloTA, HIGH);
        delay(1000);
        digitalWrite(ledAmareloTA, LOW);
        digitalWrite(ledVermelhoTA, HIGH);
        digitalWrite(ledVerdeTB, HIGH);
        digitalWrite(ledVermelhoTB, LOW);
        delay(3000);
      }
      break;
    case 3:
      if(digitalRead(ledVerdeTA) == 1 || inicial == 1){
        digitalWrite(ledVerdeTA, LOW);
        digitalWrite(ledAmareloTA, HIGH);
        delay(1000);
        digitalWrite(ledAmareloTA, LOW);
        digitalWrite(ledVermelhoTA, HIGH);
        digitalWrite(ledVerdeTB, HIGH);
        digitalWrite(ledVermelhoTB, LOW);
        delay(3000);
        inicial = 0;
      }
      if(digitalRead(ledVerdeTB) == 1){
        digitalWrite(ledVerdeTB, LOW);
        digitalWrite(ledAmareloTB, HIGH);
        delay(1000);
        digitalWrite(ledAmareloTB, LOW);
        digitalWrite(ledVermelhoTB, HIGH);
        digitalWrite(ledVerdeTA, HIGH);
        digitalWrite(ledVermelhoTA, LOW);
        delay(3000);
      }
  }
}
