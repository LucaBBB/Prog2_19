#define _GNU_SOURCE   // permette di usare estensioni GNU
#include <stdio.h>    // permette di usare scanf printf
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // permette di usare le funzioni per le stringhe strlen, strcmp
#include <math.h>     // permette di usare sin cos e altre funzioni matematiche avanzate
#include "citta.h"

int main(int argc, char *argv[])
{
  if(argc!=4) {
    printf("Uso: %s nome lat lon\n",argv[0]);
    return 1;
  }
  citta *c = crea_citta(argv[1],atof(argv[2]),atof(argv[3]));
  stampa_citta(c,stdout);
  distruggi_citta(c);
  return 0;
}



