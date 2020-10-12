bool leituraSensor;
int LeituraAnalog;
bool leituraAnterior;
#define SensorD A0

void setup() {

  //Sensor
  pinMode(SensorD, INPUT);

  //Atuador
  pinMode(11, OUTPUT);

  Serial.begin(9600);
  //LEDs
  pinMode(5, OUTPUT);  //vermelho
  pinMode(6, OUTPUT);  //amarelo
  pinMode(7, OUTPUT);  //verde
}

void loop() {
  LeituraAnalog = analogRead(SensorD);
  leituraSensor = digitalRead(SensorD);
  
  Serial.print(LeituraAnalog);
  Serial.print("\n");
  delay(800);


  if (/* leituraSensor == HIGH*/ LeituraAnalog > 700) {
    //ESTADO SECO
    //   Serial.print("ESTADO SECO: ");
    //  Serial.print(leituraSensor);
    //Serial.print("\n SINAL ANALOGICO: ");
    //Serial.print(LeituraAnalog);
    //Serial.print("\n");
    digitalWrite(5, HIGH);  //vermelho
    digitalWrite(6, LOW); // Amarelo
    digitalWrite(7, LOW);   //verde
  } else {
    //ESTADO ÚMIDO
    // Serial.print("\nESTADO UMIDO //// ");
    //  Serial.print("\n SINAL ANALOGICO: ");
    //Serial.print(LeituraAnalog);
    //Serial.print("\n");
    digitalWrite(5, LOW);   //vermelho
    digitalWrite(7, HIGH);  //verde
  }

  //ENTRAR NO ESTADO SECO
  if (leituraSensor && !leituraAnterior) {
    delay(5000);
    digitalWrite(6, LOW); // Amarelo
    digitalWrite(5, LOW);   //vermelho
    digitalWrite(6, HIGH);  //amarelo


    while (digitalRead(SensorD)) {
      digitalWrite(11, LOW);   //RELÊ
      delay(5000);
      digitalWrite(11, HIGH);   //RELÊ

      delay(5000);
    }
    digitalWrite(6, LOW);  //amarelo
  }


  leituraAnterior = leituraSensor;
}
