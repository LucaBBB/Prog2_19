Esercitazione del 16/5: compilazione separata, qsort_r, strtok

Si considerino le struct viste nella lezione del 15/5:

typedef struct {
  double lat;
  double lon;
} coordinate;

typdef struct {
  char *nome;
  coordinate coord;
} citta;

1) Utilizzando il codice visto ieri a lezione scrivere un programma che legge il file capitali.txt contenente nomi di città con le loro coordinate geografiche, e con il suo contenuto crea un array di citta * (nel file capitali.txt i nomi delle città non contengono spazi quindi possono essere letti con fscanf).

2) Scrivere una funzione void stampa_array_generico(void *a[ ], int n, void (*stampa)(void *, FILE *), FILE *f) che prende in input un array a[ ] di puntatori a void e la sua lunghezza n, e chiama la funzione stampa su tutti gli elementi dell'array passando come secondo argomento alla funzione stampa il file f. Si usi poi la funzione stampa_array_generico per stampare su stderr tutti gli elementi dell'array di città costruito al punto 1. Per fare questo è necessario passare a stampa_array_generico una funzione stampa_citta(void *a, FILE *f) che trasforma il puntatore a void a in un puntatore a città, con un casting, e scrive il suo nome e coordinate nel file f.

3) Scrivere una funzione void ordina_per distanza(citta *a[], int n, citta *o) che dato un array di puntatori a città a[ ], la sua lunghezza n, e il puntatore ad una città o esegue l'ordinamento delle città di a[ ] sulla base della distanza dalla città o.
L'esercizio va risolto utilizzando la funzione di libreria qsort_r. Tale funzione è analoga al qsort tranne che la funzione di confronto prende tre argomenti: i due elementi dell'array da ordinare e un terzo parametro che coincide con l'ultimo argomento passato alla funzione qsort_r Ad esempio, possiamo definire una funzione del tipo

int confronta_distanze_con_c(void *a, void *b, void *c) {
  if(distanza(a,c)<distanza(b,c)) return -1;
  if(distanza(a,c)>distanza(b,c)) return 1;
  return 0;
}

(ho volutamente ignorato la problematica del casting) e ordinare un array di città secondo la distanza da Sidney con la chiamata

qsort_r(array, n ,sizeof(citta *), confronta_distanze_con_c, sidney);

in quanto ogni volta che qsort_r deve eseguire un confronto tra due elementi dell'array, invoca la funzione confronta_distanze_con_c passando i due elementi da confrontare come parametri a e b e sidney come parametro c.

Successivamente scrivere un main che invoca ordina_per_distanza sull'array letto al punto 1) passando come parametro o le città

Novosibirsk 54.990145, 82.919166
Sidney -33.857251 151.208747
Waterloo 50.717469 4.397911

e stampi i rispettivi risultati.

4) Modificare la soluzione del punto 1) in modo che i dati delle città vengano letti dal file latlon.txt dove i nomi delle città possono contenere spazi e il nome e le coordinate sono separate da un carattere \t. Le linee del file devono quindi essere lette mediante la funzione getline e i singoli campi ottenuti mediante la funzione strtok.
Ultime modifiche: mercoledì, 15 maggio 2019, 14:56
