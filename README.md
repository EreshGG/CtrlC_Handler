# Gestione Segnali SIGINT - Esempio di Programma

Questo programma dimostra come gestire il segnale `SIGINT` (Ctrl+C) in un'applicazione C. Include una funzionalità di logging che registra i timestamp delle interruzioni e termina l'esecuzione dopo un numero massimo di segnalazioni consecutive.

---

## Funzionalità principali

1. **Gestione del segnale SIGINT**: 
   - Registra i dettagli di ogni pressione di `Ctrl+C` in un file di log chiamato `ctrlc_log.txt`.
   - Mostra un messaggio in console per ogni segnale ricevuto.

2. **Limitazione al numero di interruzioni**:
   - Il programma termina automaticamente dopo **3 pressioni consecutive di Ctrl+C** (configurabile modificando la costante `MAX_SIGINT_COUNT`).

3. **Logging con timestamp**:
   - Ogni interruzione viene registrata con data e ora in formato `YYYY-MM-DD HH:MM:SS`.

---

## Requisiti

- **Sistema operativo**: Unix-like (Linux, macOS) o Windows con ambiente compatibile con `unistd.h`.
- **Compilatore**: GCC o compatibile.
- **File di log**: Il programma crea un file `ctrlc_log.txt` nella directory corrente per registrare i dettagli delle interruzioni.

---

## Uso

1. **Compilazione**:
   ```bash
   gcc -o gestore_sigint progettosigint2.c
   ```

2. **Esecuzione**:
   ```bash
   ./progettosigint2
   ```

3. **Interazione**:
   - Durante l'esecuzione, premere `Ctrl+C` per simulare l'interruzione.
   - Il programma si chiuderà dopo 3 pressioni consecutive di `Ctrl+C`.

---

## Struttura del Codice

1. **Gestore del segnale**:
   - Funzione `handler(int sig)` per gestire il segnale `SIGINT`.
   - Scrive un log e verifica se il limite massimo di segnalazioni è stato raggiunto.

2. **Timestamp**:
   - Funzione `get_date(char *buffer, size_t size)` per ottenere il timestamp corrente.

3. **Esecuzione principale**:
   - Ciclo `while (1)` che mantiene il programma attivo fino al raggiungimento del limite.

---

## Personalizzazioni

- Modificare `MAX_SIGINT_COUNT` per cambiare il numero massimo di interruzioni consentite prima della chiusura del programma.
- Il nome del file di log può essere modificato nella funzione `handler`.

---

## Esempio di Output

```plaintext
Premi Ctrl+C per testare la gestione del segnale. Il programma si chiuderà dopo 3 pressioni consecutive.
Il programma è in esecuzione...
^CPremuto Ctrl+C (1/3).
Il programma è in esecuzione...
^CPremuto Ctrl+C (2/3).
Il programma è in esecuzione...
^CPremuto Ctrl+C (3/3).
Raggiunto il massimo numero di SIGINT (3). Terminazione del programma.
```

---

## Autore

Sviluppato per scopi educativi. Sentiti libero di modificarlo e migliorarlo!
