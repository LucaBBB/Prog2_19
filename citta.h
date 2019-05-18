#include "coordinate.h" 

// definisce il tipo citta composto dai campi nome e popolazione e 
// da un campo next da usare per le liste
typedef struct cit {
  char *nome;
  coordinate coord;
} citta;

citta *crea_citta(char *nome, double lat, double lon);
void distruggi_citta(citta *c);
void stampa_citta(citta *c, FILE *f);

// confronta a e b restituendo -1 se a e' piu' a nord di b
int citta_piuanord(citta *a, citta *b);

// confronta a e b restituendo -1 se a e' piu' vicina ad Alessandria di b
int vicinoAL(citta *a, citta *b);


