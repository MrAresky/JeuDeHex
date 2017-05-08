package src;

import java.util.Scanner;

class Jeu {
    static final int TAILLE_GRAPHE_DEFAUT = 11;
    private int tailleGraphe = 0;
    private char cases[];

    public static native void initialiserJeu(int tailleGraphe);
    public static native void finJeu();
    public static native char getCaseGraphe(int x, int y);
    public static native void setCaseGraphe(int x, int y, char c);
    public static native boolean estFini(char c);
    static {
        System.loadLibrary("fct_jeu");
    }

    /** Constructeur du Jeu **/
    public Jeu() {
        this.tailleGraphe = TAILLE_GRAPHE_DEFAUT;
        this.cases = new char[3];
        this.cases[0] = '.';
        this.cases[1] = 'x';
        this.cases[2] = 'o';
    }
    /** Retourne true si s est un string composé que de chiffres **/
    public boolean estUnNombrePositif(String s) {
        for (int i = 0 ; i < s.length() ; ++i) {
            if (s.charAt(i) < '0' || s.charAt(i) > '9') {
                return false;
            }
        }
        return true;
    }
    /** Fonction personnalisée qui lit un nombre au clavier et renvoie -1 si l'entrée n'est pas un nombre positif **/
    public int entrerInt() {
        Scanner clavier = new Scanner(System.in);
        String x = clavier.next();
        if (estUnNombrePositif(x)) {
            return Integer.valueOf(x);
        }
        else {
            return -1;
        }
    }
    /** Fonction qui affiche dans la console le graphe **/
    public void afficherGraphe() {
        final char bord1 = 'N'; //cases[1];
        final char bord2 = 'B'; //cases[2];

        for (int i = 0 ; i < tailleGraphe + 1 ; ++i) {
            System.out.print(bord1);
            if (i < tailleGraphe)
                System.out.print(" ");
        }
        System.out.println("/" + bord2);
        for (int i = 0 ; i < tailleGraphe ; ++i) {
            for (int j = 0 ; j < i + 1 ; ++j) {
                System.out.print(" ");
            }
            System.out.print(bord2 + " ");
            for (int j = 0 ; j < tailleGraphe ; ++j) {
                System.out.print(getCaseGraphe(i,j) + " ");
            }
            System.out.println(bord2);
        }

        for (int j = 0 ; j < tailleGraphe + 1 ; ++j) {
            System.out.print(" ");
        }
        System.out.print(bord2 + "/");
        for (int i = 0 ; i < tailleGraphe + 1 ; ++i) {
            System.out.print(bord1 + " ");
        }
        System.out.println();
    }
    /** Méthode principale qui contient la boucle de jeu **/
    public void jouer() {
        System.out.println("Jeu lancé");
        boolean finJeu = false;

        int x = 0, y = 0;
        int numJ = 1;
        while (!finJeu) {
            System.out.println("Joueur " + numJ + " (" + cases[numJ] + ")");
            System.out.println("Entrez les coordonnées du pion à placer (0 à " + (tailleGraphe-1) + "): ");
            boolean coordErr = false;
            do {
                System.out.print("> ");
                x = entrerInt();
                System.out.print("> ");
                y = entrerInt();
                coordErr = (x < 0 || x >= tailleGraphe || y < 0 || y >= tailleGraphe);
                if (coordErr) {
                    System.out.println("Coordonnées incorrectes. Entrez des nombres entre 0 et " + (tailleGraphe-1) + ".");
                }
            } while(coordErr);
            //*/

            if (getCaseGraphe(x, y) == cases[0]) {
                setCaseGraphe(x, y, cases[numJ]);

                finJeu = estFini(cases[numJ]);
                if (numJ == 2) {
                    numJ = 1;
                }
                else {
                    ++numJ;
                }
            }
            else {
                System.out.println("Case déjà prise par un pion");
            }
            afficherGraphe();
        }
    }

    /** Main du jeu **/
    public static void main(String args[]) {
        System.out.println("Main java lancé.");
        Jeu jeu = new Jeu();
        initialiserJeu(jeu.tailleGraphe);
        jeu.jouer();
        finJeu();
        System.out.println("Fin du Main java.");
    }
}
