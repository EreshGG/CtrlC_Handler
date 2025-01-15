#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAX_SIGINT_COUNT 3

volatile sig_atomic_t sigint_count = 0;

// Funzione per ottenere il timestamp corrente
void get_date(char *buffer, size_t size) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

// Gestore del segnale SIGINT
void handler(int sig) {

    char timestamp[20];
    get_date(timestamp, sizeof(timestamp));

    // Apri il file di log in modalità append
    FILE *log_file = fopen("ctrlc_log.txt", "a");
    if (log_file == NULL) {
        perror("Errore nell'apertura del file di log");
        exit(EXIT_FAILURE);
    }

    // Scrivi nel file di log
    fprintf(log_file, "SIGINT ricevuto al timestamp: %s\n", timestamp);
    fclose(log_file);

    // Incrementa il conteggio di SIGINT
    sigint_count++;

    // Controlla se è stato raggiunto il massimo numero di pressioni
    if (sigint_count >= MAX_SIGINT_COUNT) {
        printf("Raggiunto il massimo numero di SIGINT (%d). Terminazione del programma.\n", MAX_SIGINT_COUNT);
        exit(EXIT_SUCCESS);
    }

    printf("Premuto Ctrl+C (%d/%d).\n", sigint_count, MAX_SIGINT_COUNT);
}

int main(int argc, char* argv[]) {

    signal(SIGINT, handler);

    printf("Premi Ctrl+C per testare la gestione del segnale. Il programma si chiuder\xE0 dopo %d pressioni consecutive.\n", MAX_SIGINT_COUNT);
    while (1) {
        printf("Il programma è in esecuzione...\n");
        sleep(2);
    }

    return 0;
}