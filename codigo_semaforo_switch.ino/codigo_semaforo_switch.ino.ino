#define ledVermelhoTA 10
#define ledAmareloTA 9
#define ledVerdeTA 8
#define ledVermelhoTB 13
#define ledAmareloTB 12
#define ledVerdeTB 11

int estado = 0;
boolean activeTA = false;
boolean activeTB = false;

void setup() {
  pinMode(ledVermelhoTA, OUTPUT);
  pinMode(ledAmareloTA, OUTPUT);
  pinMode(ledVerdeTA, OUTPUT);
  pinMode(ledVermelhoTB, OUTPUT);
  pinMode(ledAmareloTB, OUTPUT);
  pinMode(ledVerdeTB, OUTPUT);
}

void loop() {

  if(digitalRead(2) == 1 && digitalRead(3) == 0){
    estado = 1;
  } else if (digitalRead(2) == 0 && digitalRead(3) == 1){
    estado = 2;
  } else {
    estado = 3;
  }

  switch(estado){
    case 1:
      digitalWrite(ledVerdeTA, HIGH);
      digitalWrite(ledVermelhoTB, HIGH);
      activeTA = true;
      activeTB = false;
      delay(10000);
      break;
    case 2:
      digitalWrite(ledVermelhoTA, HIGH);
      digitalWrite(ledVerdeTB, HIGH);
      activeTB = true;
      activeTA = false;
      delay(10000);
      break;
    case 3:
        //Semafóros
        digitalWrite(ledVerdeTA, HIGH);
        digitalWrite(ledVermelhoTB, HIGH);
        delay(10000);
   
        digitalWrite(ledVerdeTA, LOW);
        digitalWrite(ledAmareloTA, HIGH);
        delay(5000);
        
        digitalWrite(ledAmareloTA, LOW);
        digitalWrite(ledVermelhoTB, LOW);
      
        digitalWrite(ledVermelhoTA, HIGH);
        digitalWrite(ledVerdeTB, HIGH);
        delay(10000);
        
        digitalWrite(ledVerdeTB, LOW);
        digitalWrite(ledAmareloTB, HIGH);
        delay(5000);
      
        digitalWrite(ledVermelhoTA, LOW);
        digitalWrite(ledAmareloTB, LOW);
      }
      break;
  }
}
