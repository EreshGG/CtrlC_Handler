#include <stdio.h>
#include <signal.h>
//#include <windows.h>
#include <unistd.h>
#define GNU_SOURCE

void handler(int sig) {
    printf("Caught signal %d\n", sig);
}

int main(int argc, char* argv[]) {
    signal(SIGINT, handler);

    // Ciclo principale
    printf("Premi Ctrl+C per testare la gestione del segnale.\n");
    while (1) {
        printf("Il programma è in esecuzione...\n");
        sleep(2); // Simula un lavoro in corso
    }

    return 0;
}