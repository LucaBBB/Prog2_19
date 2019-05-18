
#define Upo_lat 44.922667
#define Upo_lon 8.616993

// ---- oggetto coordinate 
typedef struct {
  double lat;
  double lon;
} coordinate;

coordinate crea_coordinate(double lat, double lon);
void stampa_coordinate(coordinate c, FILE *f);
int latitudinepiuanord(coordinate a, coordinate b);
double distanza(coordinate p, coordinate q);

