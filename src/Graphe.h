#pragma once

#include "Sommet.h"

typedef struct s_Vecteur2i {
    int x;
    int y;
} Vecteur2i;

typedef struct s_graphe {
    Sommet haut, bas, gauche, droite;
    Sommet * plateau;
    unsigned taille;
} * Graphe;

/** Constructeur de Graphe **/
Graphe creer_graphe(int n);
/** Destructeur de Graphe **/
void detruire_graphe(Graphe g);
/** Getteur de la case [pos.x:pos.y] **/
char get_case(Graphe g, Vecteur2i pos);
/** Setteur de la case [pos.x:pos.y] **/
void set_case(Graphe g, Vecteur2i pos, char c);

/** Getteur pour l'IA **/
Sommet* get_sommet(Graphe g, Vecteur2i pos);

Graphe creer_graphe_reduit(Graphe g);
void detruire_graphe_reduit(Graphe g);
