#pragma once

typedef struct s_Sommet {
    char c;
    unsigned nbAretes;
    struct s_Sommet ** aretes;
} Sommet;

Sommet creer_sommet(char c, unsigned nbAretes);
void detruire_sommet(Sommet * s);
