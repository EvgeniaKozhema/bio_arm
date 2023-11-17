#include <Servo.h>

const int NUM_READ = 50;
long sum = 0;

//инициализация сервомоторов
Servo servo1; //(пин 9)

//переменные для хранения необработанных значаний ЭМГ-сигнала
int emg1 = 0; 

//переменные для хранения пороговых значений (для определения сотояния мышцы - расслаблена/напряжена)
int threshold1 = 120; 

void calc()
{
   for(int i=0; i<NUM_READ; i++)
  {
    emg1 = analogRead(A0); 
    sum+=emg1;
  } 
  emg1=sum/ NUM_READ;
  emg1 = map(emg1, 0, 1023, 0, 255);
  Serial.println(emg1);
  Serial.println("     ");
  sum=0;
}

void setup() {
  pinMode(A0, INPUT_PULLUP);
  Serial.begin(9600);

  servo1.attach(9);
}

void loop() {
  calc();

  if(emg1>threshold1 )
  {
    servo1.write(0);
  }

  // разжатие
  else 
  {
    servo1.write(120);
  }
  delay(10);
}
