#! /bin/sh

tester_graphe() {
    echo "Compilation des fichiers du Graphe"
    cd src
    gcc Sommet.c Graphe.c test_graphe.c -o test
    # TEST A TERMINER
    rm -rf src/test
}

echo "Script de test"
tester_graphe
