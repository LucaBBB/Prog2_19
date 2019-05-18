#define _GNU_SOURCE   // permette di usare estensioni GNU
#include <stdio.h>    // permette di usare scanf printf
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // permette di usare le funzioni per le stringhe strlen, strcmp
#include <math.h>     // permette di usare sin cos e altre funzioni matematiche avanzate
#include "citta.h"

void die(const char *s);


citta **leggi_array_citta_da_file(FILE *f, int *n)
{
  *n=0;
  return NULL;
}

int main(int argc, char *argv[])
{
  if(argc!=2) {
    printf("Uso: %s nome_file\n",argv[0]);
    return 1;
  }
  // ---- lettura 
  FILE *f = fopen(argv[1],"rt");
  if(f==NULL) die("Errore lettura");
  int n;
  citta **a = leggi_array_citta_da_file(f,&n);
  fclose(f);
  // --- stampa
  for(int i=0;i<n;i++)
    stampa_citta(a[i],stdout);
  // --- deallocazione
  for(int i=0;i<n;i++)
    distruggi_citta(a[i]);
  free(a);
  return 0;
}


// stampa messaggio d'errore e termina
void die(const char *s)
{
  perror(s);
  exit(1);
}    

