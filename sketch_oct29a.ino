#include <Servo.h>
Servo servoMotor;

int TRIG = 10;      // trigger en pin 10
int ECO = 9;      // echo en pin 9
int LED = 3;      // LED en pin 3
int DURACION;
int DISTANCIA;
int buttonState = LOW;

void setup()
{
  pinMode(TRIG, OUTPUT);  // trigger como salida
  pinMode(ECO, INPUT);    // echo como entrada
  pinMode(LED, OUTPUT);   // LED como salida
  Serial.begin(9600);     // inicializacion de comunicacion serial a 9600 bps
  // initialize the LED pin as an output:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(13, INPUT);

  Serial.begin(9600);

  // Iniciamos el servo para que empiece a trabajar con el pin 9
  servoMotor.attach(6);
}

void loop()
{

  digitalWrite(TRIG, HIGH);     // generacion del pulso a enviar
  delay(1);       // al pin conectado al trigger
  digitalWrite(TRIG, LOW);    // del sensor

  DURACION = pulseIn(ECO, HIGH);  // con funcion pulseIn se espera un pulso
  // alto en Echo
  DISTANCIA = DURACION / 58.2;    // distancia medida en centimetros
  Serial.println(DISTANCIA);    // envio de valor de distancia por monitor serial


  if (DISTANCIA <= 30 && DISTANCIA >= 0) { // si distancia entre 0 y 20 cms.
    digitalWrite(2, LOW);      // enciende LED
     delay(DISTANCIA * 50);
    digitalWrite(2, HIGH);     // apaga LED

    digitalWrite(3, LOW);      // enciende LED
     delay(DISTANCIA * 50);
    digitalWrite(3, HIGH);

    digitalWrite(4, LOW);      // enciende LED
    delay(DISTANCIA * 50);
    digitalWrite(4, HIGH);

    digitalWrite(5, LOW);      // enciende LED
     delay(DISTANCIA * 50);
    digitalWrite(5, HIGH);
    

    // Desplazamos a la posición 0º
    servoMotor.write(0);
    // Esperamos 1 segundo
    delay(1000);

    // Desplazamos a la posición 90º
    servoMotor.write(90);
    // Esperamos 1 segundo
    delay(1000);

    // Desplazamos a la posición 0º
    servoMotor.write(0);
    // Esperamos 1 segundo
    delay(1000);

  }

  //declaro boton
  buttonState = digitalRead(13);
Serial.println(buttonState);
  //button state al pulsar se encienden todas
  if (buttonState == LOW) {
    // turn LED on:

    digitalWrite(A0, LOW);
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(A3, LOW);
    delay(500);
  } else {
    // turn LED off:
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
    delay(500);
  }
}
