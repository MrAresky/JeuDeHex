#! /bin/sh

echoScript() {
    echo "[SCRIPT] $1"
}
compiler() {
    jni="jni.h"
    lib=`locate "$jni"`
    if [ ! "$lib" ] || [ ! "`echo "$lib" | grep 'include'`" ]
    then
        echo "Le fichier \"$jni\" n'a pas été trouvé"
        exit 1
    fi
    lib=`dirname "$lib"`

    # Compilation
    echoScript "Compilation..."
    echoScript "Etape 1/3"
    javac "src/Jeu.java"
    echoScript "Etape 2/3"
    javah -d "src" "src.Jeu"
    echoScript "Etape 3/3"
    gcc -I"$lib" -I"$lib"/linux -fPIC -shared "src/Sommet.c" "src/Graphe.c" "src/fct_jeu.c" -o "src/libfct_jeu.so"
    echoScript "Compilation finie"
}
executer() {
    # Execution
    echoScript "Exécution..."
    java -Djava.library.path="src" "src/Jeu"
    echoScript "Exécution finie"
}

if [ "$1" = "compiler" ]
then
    compiler
elif [ "$1" = "executer" ]
then
    executer
else
    compiler
    executer
fi
