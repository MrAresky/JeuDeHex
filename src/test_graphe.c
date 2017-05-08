#include "Graphe.h"
#include "Sommet.h"
#include <stdio.h>

#define TAILLE_GRAPHE 10

void aff_graphe(Graphe g) {
    for (unsigned y = 0 ; y < TAILLE_GRAPHE ; ++y) {
	for (unsigned x = 0 ; x < y ; ++x) {
            printf(" ");
        }
        for (unsigned x = 0 ; x < TAILLE_GRAPHE ; ++x) {
            printf("%c ", get_case(g, (Vecteur2i){x,y}));
        }
        printf("\n");
    }
}
int main(int argc, char ** argv) {
    printf("Création d'un graphe...\n");
    Graphe g = creer_graphe(TAILLE_GRAPHE);

    set_case(g, (Vecteur2i){3,5}, 'O');
    set_case(g, (Vecteur2i){3,4}, '3');
    set_case(g, (Vecteur2i){3,6}, '4');
    set_case(g, (Vecteur2i){2,5}, '1');
    set_case(g, (Vecteur2i){4,5}, '6');
    set_case(g, (Vecteur2i){2,6}, '2');
    set_case(g, (Vecteur2i){4,4}, '5');

    set_case(g, (Vecteur2i){0,9}, 'A');
    set_case(g, (Vecteur2i){1,9}, 'B');
    set_case(g, (Vecteur2i){0,8}, 'C');
    set_case(g, (Vecteur2i){1,8}, 'D');

    set_case(g, (Vecteur2i){9,9}, 'E');
    set_case(g, (Vecteur2i){8,8}, 'F');
    set_case(g, (Vecteur2i){9,8}, 'G');
    set_case(g, (Vecteur2i){8,9}, 'H');

    set_case(g, (Vecteur2i){9,0}, 'I');
    set_case(g, (Vecteur2i){8,0}, 'J');
    aff_graphe(g); printf("\n");

    
    Vecteur2i pos;
    printf("Dans les tests suivants, on va afficher les arrêtes de diverses cases dans l'ordre suivant : \nHaut gauche, Gauche, Bas gauche, Bas droit, Droite, Haut droit\n\n");
    printf("Pour les cases sur les côtés du plateau, il peut manquer des arrêtes car nous avons 'lissé' les bords dans un soucis d'optimisation mémoire\n\n") ;
    
    pos.x = 3; pos.y = 5;
    printf("Case %c : ", get_sommet(g, pos)->c);
    for (unsigned i = 0 ; i < get_sommet(g, pos)->nbAretes ; ++i) {
        printf("%c ", get_sommet(g, pos)->aretes[i]->c);
    }
    printf("\n");
    
    pos.x = 0; pos.y = 9;
    printf("Case %c : ", get_sommet(g, pos)->c);
    for (unsigned i = 0 ; i < get_sommet(g, pos)->nbAretes ; ++i) {
        printf("%c ", get_sommet(g, pos)->aretes[i]->c);
    }
    printf("\n");
    
    pos.x = 0; pos.y = 8;
    printf("Case %c : ", get_sommet(g, pos)->c);
    for (unsigned i = 0 ; i < get_sommet(g, pos)->nbAretes ; ++i) {
        printf("%c ", get_sommet(g, pos)->aretes[i]->c);
    }
    printf("\n");
    
    pos.x = 9; pos.y = 9;
    printf("Case %c : ", get_sommet(g, pos)->c);
    for (unsigned i = 0 ; i < get_sommet(g, pos)->nbAretes ; ++i) {
        printf("%c ", get_sommet(g, pos)->aretes[i]->c);
    }
    printf("\n") ;
    
    pos.x = 8; pos.y = 9;
    printf("Case %c : ", get_sommet(g, pos)->c);
    for (unsigned i = 0 ; i < get_sommet(g, pos)->nbAretes ; ++i) {
        printf("%c ", get_sommet(g, pos)->aretes[i]->c);
    }
    printf("\n");
    
    pos.x = 9; pos.y = 0;
    printf("Case %c : ", get_sommet(g, pos)->c);
    for (unsigned i = 0 ; i < get_sommet(g, pos)->nbAretes ; ++i) {
        printf("%c ", get_sommet(g, pos)->aretes[i]->c);
    }
    printf("\n");
    

    printf("Destruction du graphe...\n");
    detruire_graphe(g);
    return 0;
}
