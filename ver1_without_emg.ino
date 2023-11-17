#include <Servo.h>


//инициализация сервомоторов
Servo servo1; //(пин 9)

static bool buttonState = false;

void setup() {
  pinMode(A0, INPUT);

  servo1.attach(9);
}

void loop() {

  if (digitalRead(A0) == HIGH && !buttonState) { // Если кнопка нажата и это первый раз
    buttonState = true; // Устанавливаем флаг, что кнопка нажата
    servo1.write(0); 
  } else if (digitalRead(A0) == LOW) {
    buttonState = false; // Сбрасываем флаг, когда кнопка отпущена
    servo1.write(120);
  }
  delay(10);

}
