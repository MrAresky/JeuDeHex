#include <malloc.h>
#include "Sommet.h"

/** Sommet **/

Sommet creer_sommet(char c, unsigned nbAretes) {
    Sommet s;
    s.c = c;
    s.nbAretes = nbAretes;
    s.aretes = (Sommet**) malloc(sizeof(Sommet*)*nbAretes);
    return s;
}
void detruire_sommet(Sommet * s) {
    free(s->aretes);
}
