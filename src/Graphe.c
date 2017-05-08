#include <malloc.h>
#include <assert.h>
#include "Graphe.h"

/** -------------- **/
/** --- Graphe --- **/
/** -------------- **/

static char const bord1 = 'x';
static char const bord2 = 'o';

/** Renvoie l'indice du plateau correspondant aux coordonnées [pos.x:pos.y]
 *  NOTE: Fonction locale au fichier **/
unsigned get_ind(Graphe g, int y, int x) {
    assert(y >= 0 && y < g->taille && x >= 0 && x < g->taille);
    return (x + g->taille * y);
}
Graphe creer_graphe(int n) {
    assert(n > 1);
    Graphe g = (Graphe) malloc(sizeof(struct s_graphe));
    g->taille = n;
    g->haut = creer_sommet(bord1, n);
    g->bas = creer_sommet(bord1, n);
    g->gauche = creer_sommet(bord2, n);
    g->droite = creer_sommet(bord2, n);
    g->plateau = (Sommet*) malloc((n*n) * sizeof(Sommet));

    for (unsigned x = 0 ; x < n ; ++x) {
        for (unsigned y = 0 ; y < n ; ++y) {
            if ((x == 0 && y == 0) || (x == n-1 && y == n-1)) {
                g->plateau[get_ind(g, x, y)] = creer_sommet('.', 4);
            } else if ( (x == 0) ||
                        (y == 0) ||
                        (x == n-1) ||
                        (y == n-1) ) {
                g->plateau[get_ind(g, x, y)] = creer_sommet('.', 5);
            } else {
                g->plateau[get_ind(g, x, y)] = creer_sommet('.', 6);
            }
        }
    }

    unsigned ind = 1;
    for (int x = 0 ; x < n ; ++x) {
        for (int y = 0 ; y < n ; ++y) {
            ind = 0;

            /** Arete vers le haut gauche **/
            if (y >= 1)
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->plateau[get_ind(g, x, y-1)];
            else
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->haut;
            ++ind;

            /** Arete vers la gauche **/
            if (x >= 1)
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->plateau[get_ind(g, x-1, y)];
            else
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->gauche;
            ++ind;

            /** Arete vers le bas gauche **/
            if (x >= 1 && y < n-1) {
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->plateau[get_ind(g, x-1, y+1)];
                ++ind;
            }

             /** Arete vers le bas droit **/
            if (y < n-1)
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->plateau[get_ind(g, x, y+1)];
            else
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->bas;
            ++ind;

            /** Arete vers la droite **/
            if (x < n-1)
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->plateau[get_ind(g, x+1, y)];
            else
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->droite;
            ++ind;

            /** Arete vers le haut droit **/
            if (x < n-1 && y >= 1) {
                g->plateau[get_ind(g, x, y)].aretes[ind] = &g->plateau[get_ind(g, x+1, y-1)];
                ++ind;
            }
        }
    }

    return g;
}
void detruire_graphe(Graphe g) {
    for (unsigned x = 0 ; x < g->taille ; ++x) {
        for (unsigned y = 0 ; y < g->taille ; ++y) {
            detruire_sommet(&g->plateau[get_ind(g, x, y)]);
        }
    }
    detruire_sommet(&g->haut);
    detruire_sommet(&g->bas);
    detruire_sommet(&g->gauche);
    detruire_sommet(&g->droite);
    free(g->plateau);
    free(g);
}
char get_case(Graphe g, Vecteur2i pos){
    return get_sommet(g, pos)->c;
}
void set_case(Graphe g, Vecteur2i pos, char c) {
    g->plateau[get_ind(g, pos.x, pos.y)].c = c;
}
Sommet* get_sommet(Graphe g, Vecteur2i pos) {
    return &g->plateau[get_ind(g, pos.x, pos.y)];
}

/** TODO **/
Graphe creer_graphe_reduit(Graphe g) {
    Graphe cp = (Graphe) malloc(sizeof(struct s_graphe));

    return cp;
}
void detruire_graphe_reduit(Graphe g) {
    free(g);
}
/** -------------- **/
/** - Fin Graphe - **/
/** -------------- **/
