/*! 
 *  \file morpion.c
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *  \brief Morpion
 */

/* Inclusion des fichiers en-tête */
#include "morpion.h"

void init(int ttint_plateau[N][N])
{
    int i_i; /* Variable de boucle */
    int i_j; /* Variable de boucle */

    /* Parcours des lignes */
    for (i_i = 0; i_i < N; i_i++){
        /* Parcours des lignes */
        for (i_j = 0; i_j < N; i_j++){
            /* Initialisation du tableau */
            ttint_plateau[i_i][i_j] = -1;
        }
    }
}

void affichage(int ttint_plateau[N][N])
{
    int i_i; /* Variable de boucle */
    int i_j; /* Variable de boucle */

    /* Parcours des lignes */
    for (i_i = 0; i_i < N; i_i++){
        /* Parcours des colonnes */
        for (i_j = 0; i_j < N; i_j++){
            printf("|");
            /* Si la case parcourue est vide */
            if (ttint_plateau[i_i][i_j] == -1){
                /* On affiche un espace */
                printf("   ");
            /* Sinon si le premier joueur à rempli la case */
            }else if (ttint_plateau[i_i][i_j] == 1){
                /* On affiche une croix */
                printf(" X ");
            /* Sinon si le deuxième joueur à rempli la case */
            }else{
                /* On affiche un cercle */
                printf(" O ");
            }
        }
        printf("|");
        printf("\n");
    }  
}

int saisieLigne(void)
{
    int i_ligne; /* Variable de retour */
    int scanretour; /* Valeur de vérification */

    /* Affichage de la requête */
    printf("Dans quelle ligne voulez-vous jouer ?\n");
    /* Initialisation de la valeur de vérification */
    scanretour = scanf("%d",&i_ligne);
    /* Vérification de la validité de la saisie */
    while(scanretour == 0 || i_ligne < 0 || i_ligne > 2){
        /* Affichage d'un message d'erreur */
        printf("Ligne invalide. Veuillez choisir un chiffre entre 0,1 et 2.\n");
        /* Réinitialisation de la valeur de vérification */
        scanretour = scanf("%d",&i_ligne);
    }
    /* On retourne la ligne saisie par l'utilisateur */
    return(i_ligne);
}

int saisieColonne(void)
{
    int i_colonne; /* Variable de retour */
    int scanretour; /* Valeur de vérification */

    /* Affichage de la requête */
    printf("Dans quelle colonne voulez-vous jouer ?\n");
    /* Initialisation de la valeur de vérification */
    scanretour = scanf("%d",&i_colonne);
    /* Vérification de la validité de la saisie */
    while(scanretour == 0 || i_colonne < 0 || i_colonne > 2){
        /* Affichage d'un message d'erreur */
        printf("Colonne invalide. Veuillez choisir un chiffre entre 0,1 et 2.\n");
        /* Réinitialisation de la valeur de vérification */
        scanretour = scanf("%d",&i_colonne);
    }
    /* On retourne la colonne saisie par l'utilisateur */
    return(i_colonne);
}

int occupe(int ttint_plateau[N][N], int i_ligne, int i_colonne)
{
    int i_res; /* Valeur de retour */

    /* Initialisation de la valeur de retour à 1 */
    i_res = 1;
    /* Si la case choisie par l'utilisateur est vide */
    if (ttint_plateau[i_ligne][i_colonne] == -1){
        /* On met la valeur de retour à 0 */
        i_res = 0;
    }
    /* On retourne 0 si la case choisie par l'utilisateur est vide et 0 sinon */
    return(i_res);
}

int victoireDiago1(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */

    /* Initialisation de la valeur de retour */
    i_res = 0;
    /* Si la première diagonale est remplie par le même joueur */
    if ((ttint_plateau[0][0] != -1) && (ttint_plateau[0][0] == ttint_plateau[1][1]) && (ttint_plateau[1][1] == ttint_plateau[2][2])){
        /* La valeur de retour prend 1 */
        i_res = 1;
    }
    /* On retourne 1 si un joueur a gagné sur la diagonale et 0 sinon */
    return(i_res);
}

int victoireDiago2(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */

    /* Initialisation de la valeur de retour */
    i_res = 0;
    /* Si la première diagonale est remplie par le même joueur */
    if ((ttint_plateau[0][2] != -1) && (ttint_plateau[0][2] == ttint_plateau[1][1]) && (ttint_plateau[1][1] == ttint_plateau[2][0])){
        /* La valeur de retour prend 1 */
        i_res = 1;
    }
    /* On retourne 1 si un joueur a gagné sur la diagonale et 0 sinon */
    return(i_res);
}

int victoireLigne(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */
    int i_i; /* Valeur prenant la valeur des lignes */

    /* Initialisation de la valeur de retour à 0 */
    i_res = 0;
    /* Initialisation à la première ligne */
    i_i = 0;

    /* Tant que la vérification des lignes précédentes n'a rien donné et qu'il reste des lignes à vérifier */
    while((i_res != 1) && (i_i < N)){
        /* Si toutes les cases d'une même ligne sont égales à 1 ou 2 */ 
        if ((ttint_plateau[i_i][0] != -1) && (ttint_plateau[i_i][0] == ttint_plateau[i_i][1]) && (ttint_plateau[i_i][1] == ttint_plateau[i_i][2])){
            /* La valeur de retour prend 1 */
            i_res = 1;
        }     
        /* On passe à la ligne suivante */
        i_i++;
    }
    /* On retourne 1 si un joueur a gagné sur une ligne et 0 sinon */
    return(i_res);
}

int victoireColonne(int ttint_plateau[N][N])
{
    int i_res; /* Valeur de retour */
    int i_j; /* Valeur prenant la valeur des colonnes */

    /* Initialisation de la valeur de retour à 0 */
    i_res = 0;
    /* Initialisation à la première colonne */
    i_j = 0;

    /* Tant que la vérification des lignes précédentes n'a rien donné et qu'il reste des colonnes à vérifier */
    while((i_res != 1) && (i_j < N)){
        /* Si toutes les cases d'une même colonne sont égales à 1 ou 2 */ 
        if ((ttint_plateau[0][i_j] != -1) && (ttint_plateau[0][i_j] == ttint_plateau[1][i_j]) && (ttint_plateau[1][i_j] == ttint_plateau[2][i_j])){
            /* La valeur de retour prend 1 */
            i_res = 1;
        }     
        /* On passe à la ligne suivante */
        i_j++;
    }
    /* On retourne 1 si un joueur a gagné sur une ligne et 0 sinon */
    return(i_res);
}

int aGagne(int ttint_plateau[N][N])
{
    int i_res1; /* Valeur de retour de la fonction victoireDiago1 */
    int i_res2; /* Valeur de retour de la fonction victoireDiago2 */
    int i_res3; /* Valeur de retour de la fonction victoireLigne */
    int i_res4; /* Valeur de retour de la fonction victoireColonne */
    int i_resFinal; /* Valeur de retour */

    /* Appel de la fonction victoireDiago1 */
    i_res1 = victoireDiago1(ttint_plateau);
    /* Appel de la fonction victoireDiago2 */
    i_res2 = victoireDiago2(ttint_plateau);
    /* Appel de la fonction victoireLigne */
    i_res3 = victoireLigne(ttint_plateau);
    /* Appel de la fonction victoireColonne */
    i_res4 = victoireColonne(ttint_plateau);
    /* Initialisation de la valeur de retour à 0 */
    i_resFinal = 0;

    /* Si une des 4 fonctions a renvoyé 1 */
    if ((i_res1 == 1) || (i_res2 == 1) || (i_res3 == 1) || (i_res4 == 1)){
        /* On met la valeur de retour à 1 */
        i_resFinal = 1;
    }
    /* On retourne 1 si un joueur a gagné et 0 sinon */
    return(i_resFinal);
}

void jouer(int ttint_plateau[N][N], int i_joueur, int i_ligne, int i_colonne)
{
    int i_resOccupee; /* Valeur de retour de la fonction occupee */

    /* Appel de la fonction occupe */
    i_resOccupee = occupe(ttint_plateau,i_ligne,i_colonne);
    /* Tant que la case choisie par l'utilisateur est déjà occupée */
    while (i_resOccupee == 1){
        /* On affiche un message d'erreur */
        printf("La case est déjà occupée. Veuillez en choisir une autre.\n");
        /* L'utilisateur doit saisir une nouvelle valeur de ligne */
        i_ligne = saisieLigne();
        /* L'utilisateur doit saisir une nouvelle valeur de colonne */
        i_colonne = saisieColonne();
        /* Appel de la fonction occupe */
        i_resOccupee = occupe(ttint_plateau,i_ligne,i_colonne);
    }
    /* On place le coup du joueur sur le plateau */
    ttint_plateau[i_ligne][i_colonne] = i_joueur;
}

void tourDeJeu(int ttint_plateau[N][N])
{
    int i_matchnul; /* Variable correspondant au nombre de coups joués et permettant de vérifier si un match est nul */
    int i_gagne; /* Variable permettant de vérifier si un joueur a gagné */
    int i_joueur; /* Variable correspondant au numéro du joueur */
    int i_ligne; /* Variable correspondant à la ligne choisie par l'utilisateur */
    int i_colonne; /* Variable correspondant à la colonne choisie par l'utilisateur */

    /* C'est au premir joueur de commencer */
    i_joueur = 1;
    /* Personne n'a encore gagné */
    i_gagne = 0;
    /* Aucun coup n'est joué */
    i_matchnul = 0;
    /* Tant que personne n'a gagné et que le plateau n'est pas complet */
    while ((i_gagne != 1) && (i_matchnul != 9)){
        /* On clear le systeme */
        system("clear");
        /* On affiche le plateau */
        affichage(ttint_plateau);
        /* On affiche qui doit jouer */
        printf("Joueur %d, à vous de jouer.\n",i_joueur);
        /* On lui demande dans quelle ligne jouer */
        i_ligne = saisieLigne();
        /* On lui demande dans quelle colonne jouer */
        i_colonne = saisieColonne();
        /* On place le coup du joueur après vérification */
        jouer(ttint_plateau,i_joueur,i_ligne,i_colonne);
        /* On affiche le plateau */
        affichage(ttint_plateau);
        /* On vérifie si le joueur a gagné */
        i_gagne = aGagne(ttint_plateau);
        /* On incrémente le nombre de coups joués */
        i_matchnul++;
        /* On passe au joueur suivant */
        i_joueur = (i_joueur % 2) + 1;
    }
    /* On clear le systeme */
    system("clear");
    /* Si un joueur a gagné */
    if (i_gagne == 1){
        /* On repasse au joueur précédent car c'est le dernier à avoir joué */
        i_joueur = (i_joueur % 2) + 1;
        /* On affiche un message de victoire */
        printf("Le joueur %d a gagné.\n",i_joueur);
    /* Sinon si le plateau est complet*/
    }else if (i_matchnul == 9){
        /* On affiche u message de match nul */
        printf("MATCH NUL.\n");
    }
}

