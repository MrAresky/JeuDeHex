#include <jni.h>
#include <assert.h>
#include "src_Jeu.h"
#include "Graphe.h"

static Graphe graphe = NULL;

JNIEXPORT void JNICALL Java_src_Jeu_initialiserJeu(JNIEnv * env, jclass this, jint tailleGraphe) {
    assert(graphe == NULL);
    graphe = creer_graphe(tailleGraphe);
}
JNIEXPORT void JNICALL Java_src_Jeu_finJeu(JNIEnv * env, jclass this) {
    assert(graphe != NULL);
    detruire_graphe(graphe);
    graphe = NULL;
}

JNIEXPORT jchar JNICALL Java_src_Jeu_getCaseGraphe(JNIEnv * env, jclass this, jint x, jint y) {
    assert(graphe != NULL);
    return get_case(graphe, (Vecteur2i){x,y});
}
JNIEXPORT void JNICALL Java_src_Jeu_setCaseGraphe(JNIEnv * env, jclass this, jint x, jint y, jchar c) {
    assert(graphe != NULL);
    set_case(graphe, (Vecteur2i){x,y}, c);
}

/** TODO **/
JNIEXPORT jboolean JNICALL Java_src_Jeu_estFini(JNIEnv * env, jclass this, jchar c) {
    assert(graphe != NULL);
    Graphe grapheReduit = creer_graphe_reduit(graphe);
    detruire_graphe_reduit(grapheReduit);

    return 1;
}
