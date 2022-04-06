/*! 
 *  \file main.c
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *  \brief Fonction principale
 */

/* Inclusion des fichiers en-tête */
#include "morpion.h"

/*! \fn int main (int argc, char** argv)
 *  \author Yann Langlo <yann.langlo@cy-tech.fr>
 *  \version 0.1
 *  \date Mon Nov 22 2021
 *
 *  \brief Fonction principale
 * 
 *
 * \param argc : Nombre d'argument
 * \param argv : Tableau des arguments
 * \return 0   : le programme doit se terminer normalement
 *
 * \remarks 
 */
int main(int argc, char const *argv[])
{
    int ttint_plateau[N][N]; /* Plateau de jeu */

    /* Initialisation du plateau de jeu */
    init(ttint_plateau);
    /* Affichage du plateau de jeu */
    affichage(ttint_plateau);
    /* On lance le jeu */
    tourDeJeu(ttint_plateau);
    /* On retourne 0, tout s'est bien passé */
    return 0;
}
