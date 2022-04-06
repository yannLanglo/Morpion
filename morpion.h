/*! \file morpion.h
 *	\author Langlo Yann <langloyann@eisti.eu>
 *	\version 0.1
 *	\date Mon Nov 22 2021
*/

/* Vérification de la présence de la variable TP4 */
#ifndef __MORPION_H_
/* Si non présente on la définit et on l'inclut dans le fichier */
#define __MORPION_H_
/* Déclaration de la constante symbolique N à 3 */
#define N 3

/* Inclusion des bibliothèques */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

/*! \fn void init(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Initialise le tableau en paramètre
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
void init(int ttint_plateau[N][N]);

/*! \fn void affichage(int ttint_tab[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Affiche le tableau en paramètre
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
void affichage(int ttint_plateau[N][N]);

/*! \fn int saisieLigne(void)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne la ligne saisie par l'utilisateur
 * 
 * \remarks 
 */
int saisieLigne(void);

/*! \fn int saisieColonne(void)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne la colonne saisie par l'utilisateur
 * 
 * \remarks 
 */
int saisieColonne(void);

/*! \fn int occupe(int ttint_plateau[N][N], int i_ligne, int i_colonne)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne 1 si la case est occupée, 0 sinon
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
int occupe(int ttint_plateau[N][N], int i_ligne, int i_colonne);

/*! \fn int victoireDiago1(int ttint_plateau)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne 1 si la première diagonale est occupée par le même joueur, 0 sinon
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
int victoireDiago1(int ttint_plateau[N][N]);

/*! \fn int victoireDiago2(int ttint_plateau)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne 1 si la deuxième diagonale est occupée par le même joueur, 0 sinon
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
int victoireDiago2(int ttint_plateau[N][N]);

/*! \fn int victoireLigne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne 1 si une ligne est occupée par le même joueur, 0 sinon
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
int victoireLigne(int ttint_plateau[N][N]);

/*! \fn int victoireColonne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne 1 si une colonne est occupée par le même joueur, 0 sinon
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
int victoireColonne(int ttint_plateau[N][N]);

/*! \fn int aGagne(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Retourne 1 si un joueur a gagné, 0 sinon
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
int aGagne(int ttint_plateau[N][N]);

/*! \fn void jouer(int ttint_plateau[N][N], int i_joueur, int i_ligne, int i_colonne)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Place le coup du joueur là où il l'a décidé
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 *         i_joueur : Numéro du joueur
 *         i_ligne : Ligne que le joueur a choisie
 *         i_colonne : Colonne que le joueur a choisie
 * 
 * \remarks 
 */
void jouer(int ttint_plateau[N][N], int i_joueur, int i_ligne, int i_colonne);

/*! \fn void tourDeJeu(int ttint_plateau[N][N])
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Fait jouer les joueurs chacun leurs tours jusqu'à ce que la partie soit terminée
 *
 *  \param ttint_plateau : Plateau de jeu du morpion
 * 
 * \remarks 
 */
void tourDeJeu(int ttint_plateau[N][N]);

/* Si présente, fin de l'inclusion */
#endif