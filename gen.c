#include <stdio.h>
#include <wiringPi.h>
#include <time.h>

#define	PIN	7
#define am	8	//hora a la que empieza a funcionar el generador
#define pm	20	//hasta esta hora funciona el gen, en formato 24H
#define carrete 0	//modo carrete, siempre listo para partir

int main (void)
{
  wiringPiSetup ();
  pinMode (PIN, OUTPUT);
  while(1){
    time_t now = time(NULL);
    struct tm *tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    printf("La hora es %d, parte desde las %d hasta las %d. Carrete es %d.\n",hour, am, pm, carrete);

    if (hour >= am && hour < pm) {
      digitalWrite(PIN, 1); //1 deja listo para partir el genset
    }
    else {
      digitalWrite(PIN, 0);
    }
    if (carrete == 1) {
      digitalWrite(PIN, 1);
    }
    delay(5000);	//cada 5s
  }
  return 0;
}
