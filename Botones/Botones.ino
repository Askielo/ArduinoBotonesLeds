const int buttonPin2 =  2; // número del pin para el botón
const int ledPin13 =  13;  // número del pin del LED
const int buttonPin3 =  3; // número del pin para el botón
const int ledPin12 =  12;  // número del pin del LED
const int buttonPin4 =  4; // número del pin para el botón
const int ledPin11 =  11;  // número del pin del LED
const int buttonPin5 =  5; // número del pin para el botón
const int ledPin10 =  10;  // número del pin del LED
const int buttonPin6 =  6; // número del pin para el botón


int buttonState2 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int buttonState3 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int buttonState4 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int buttonState5 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int buttonState6 = 0;  // estado del botón (0 ó LOW es apagado y 1 ó HIGH es encendido)
int start = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;
int b4 = 0;
int ledState = LOW;

unsigned long antMillis = 0;
const long intervalo = 1000;

void setup() {
  Serial.begin(9600);
  // Se identifica el pin 13 como salida
  pinMode(ledPin13, OUTPUT);
  // Se identifica el pin 2 como entrada
  pinMode(buttonPin2, INPUT);
  //
  //
  // Se identifica el pin 12 como salida
  pinMode(ledPin12, OUTPUT);
  // Se identifica el pin 3 como entrada
  pinMode(buttonPin3, INPUT);
  //
  //
  // Se identifica el pin 11 como salida
  pinMode(ledPin11, OUTPUT);
  // Se identifica el pin 4 como entrada
  pinMode(buttonPin4, INPUT);
  //
  //
  // Se identifica el pin 10 como salida
  pinMode(ledPin10, OUTPUT);
  // Se identifica el pin 5 como entrada
  pinMode(buttonPin5, INPUT);
  //
  //
  // Se identifica el pin 6 como entrada
  pinMode(buttonPin6, INPUT);
}

unsigned long offset = 0;
boolean setupEnded = false;


void loop() {

  Serial.print(start);

  unsigned long actualMillis = millis() + offset;
  buttonState6 = digitalRead(buttonPin6);
  if (buttonState6 == HIGH) {
    start = 1;
    setupEnded = true;
  }

  Serial.print(start);

  if (actualMillis - antMillis >= intervalo) {

    if (setupEnded != true) {

      offset += 1000ul * 60ul * 5ul;
    }
    antMillis = actualMillis;


    if (start == 1) {

      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }

      digitalWrite(ledPin13, ledState);

      // Leemos si el botón en pin2 está abierto o cerrado
      buttonState2 = digitalRead( buttonPin2 );

      // Si está siendo pulsado es HIGH
      if (buttonState2 == HIGH) {
        // Y el LED se enciende
        digitalWrite(ledPin13, HIGH);
        b1 = 1;
      }
      else {
        // Si no es asi, se apaga
        digitalWrite(ledPin13, LOW);
      }
      //
      //
      // Leemos si el botón en pin3 está abierto o cerrado
      buttonState3 = digitalRead( buttonPin3 );

      // Si está siendo pulsado es HIGH
      if (buttonState3 == HIGH) {
        // Y el LED se enciende
        digitalWrite(ledPin12, HIGH);
        b2 = 1;
      }
      else {
        // Si no es asi, se apaga
        digitalWrite(ledPin12, LOW);
      }
      //
      //
      // Leemos si el botón en pin4 está abierto o cerrado
      buttonState4 = digitalRead( buttonPin4 );

      // Si está siendo pulsado es HIGH
      if (buttonState4 == HIGH) {
        // Y el LED se enciende
        digitalWrite(ledPin11, HIGH);
        b3 = 1;
      }
      else {
        // Si no es asi, se apaga
        digitalWrite(ledPin11, LOW);
      }
      //
      //
      // Leemos si el botón en pin5 está abierto o cerrado
      buttonState5 = digitalRead( buttonPin5 );

      // Si está siendo pulsado es HIGH
      if (buttonState5 == HIGH) {
        // Y el LED se enciende
        digitalWrite(ledPin10, HIGH);
        b4 = 1;
      }
      else {
        // Si no es asi, se apaga
        digitalWrite(ledPin10, LOW);
      }
      //
      //
      if (b1 == 1) {
        if (ledState == LOW) {
          ledState = HIGH;
        } else {
          ledState = LOW;
        }

        digitalWrite(ledPin13, ledState);
        digitalWrite(ledPin12, ledState);

        // Leemos si el botón en pin2 está abierto o cerrado
        buttonState2 = digitalRead( buttonPin2 );

        // Si está siendo pulsado es HIGH
        if (buttonState2 == HIGH) {
          // Y el LED se enciende
          digitalWrite(ledPin13, HIGH);
          b1 = 1;
        }
        else {
          // Si no es asi, se apaga
          digitalWrite(ledPin13, LOW);
        }
        //
        //
        // Leemos si el botón en pin3 está abierto o cerrado
        buttonState3 = digitalRead( buttonPin3 );

        // Si está siendo pulsado es HIGH
        if (buttonState3 == HIGH) {
          // Y el LED se enciende
          digitalWrite(ledPin12, HIGH);
          b2 = 1;
        }
        else {
          // Si no es asi, se apaga
          digitalWrite(ledPin12, LOW);
        }
        //
        //
        // Leemos si el botón en pin4 está abierto o cerrado
        buttonState4 = digitalRead( buttonPin4 );

        // Si está siendo pulsado es HIGH
        if (buttonState4 == HIGH) {
          // Y el LED se enciende
          digitalWrite(ledPin11, HIGH);
          b3 = 1;
        }
        else {
          // Si no es asi, se apaga
          digitalWrite(ledPin11, LOW);
        }
        //
        //
        // Leemos si el botón en pin5 está abierto o cerrado
        buttonState5 = digitalRead( buttonPin5 );

        // Si está siendo pulsado es HIGH
        if (buttonState5 == HIGH) {
          // Y el LED se enciende
          digitalWrite(ledPin10, HIGH);
          b4 = 1;
        }
        else {
          // Si no es asi, se apaga
          digitalWrite(ledPin10, LOW);
        }
        //
        //

      }
    }

  }
}
