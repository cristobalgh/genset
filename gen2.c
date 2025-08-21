#include <stdio.h>
#include <wiringPi.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

#define PIN     7   // Pin que controla el generador
#define AM      8   // Hora de inicio (24H)
#define PM      20  // Hora de término (24H)
#define ARCHIVO "carrete.txt"

int leerCarrete(void) {
    FILE *f = fopen(ARCHIVO, "r");
    int valor = 0;

    if (f == NULL) {
        // Si no existe, lo crea con valor 0
        f = fopen(ARCHIVO, "w");
        if (f) {
            fprintf(f, "0\n");
            fclose(f);
        }
        return 0;
    }

    fscanf(f, "%d", &valor);
    fclose(f);

    // Asegurar que sea 0 o 1
    if (valor != 0) valor = 1;

    return valor;
}

// Manejo de señal para apagar al salir
void salir(int sig) {
    digitalWrite(PIN, LOW);
    printf("\n[INFO] Programa detenido, pin apagado.\n");
    exit(0);
}

int main(void) {
    wiringPiSetup();
    pinMode(PIN, OUTPUT);
    signal(SIGINT, salir);   // Captura Ctrl+C

    while (1) {
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        int hour = tm_struct->tm_hour;
        int carrete = leerCarrete();

        printf("Hora actual: %02d:00 | Activo desde %02d:00 hasta %02d:00 | Modo carrete: %s\n",
               hour, AM, PM, carrete ? "Sí" : "No");

        if (carrete == 1 || (hour >= AM && hour < PM)) {
            digitalWrite(PIN, HIGH);
        } else {
            digitalWrite(PIN, LOW);
        }

        delay(5000); // cada 5 segundos
    }
    return 0;
}
