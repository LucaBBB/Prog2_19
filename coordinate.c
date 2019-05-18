#define _GNU_SOURCE   // permette di usare estensioni GNU
#include <stdio.h>    // permette di usare scanf printf
#include <stdlib.h>   // conversioni stringa/numero rand() abs() exit() etc ...
#include <stdbool.h>  // gestisce tipo bool (per variabili booleane)
#include <assert.h>   // permette di usare la funzione assert
#include <string.h>   // permette di usare le funzioni per le stringhe strlen, strcmp
#include <math.h>     // permette di usare sin cos e altre funzioni matematiche avanzate
#include "coordinate.h"

coordinate crea_coordinate(double lat, double lon)
{
  coordinate c;
  
  c.lat = lat; c.lon = lon;
  return c;
}

void stampa_coordinate(coordinate c, FILE *f)
{
  fprintf(f, "<%f,%f> ",c.lat,c.lon);
}

int latitudinepiuanord(coordinate a, coordinate b)
{
  if(a.lat>b.lat) return -1;
  if(a.lat<b.lat) return 1;
  return 0;
}

// restituisce distanza in km tra p e q 
#define RaggioTerra 6371
#define InRadianti (3.1415926536 / 180)
double distanza(coordinate p, coordinate q)
{ 
  double lat1 = p.lat*InRadianti;
  double lat2 = q.lat*InRadianti;
  double dlon = (q.lon - p.lon)*InRadianti;
  double dlat = lat2-lat1;
  
  double a = pow(sin(dlat / 2), 2) + 
             cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
  double c = 2 * asin(sqrt(a));
  return c*RaggioTerra;
}

