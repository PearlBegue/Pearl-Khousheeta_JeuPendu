/*
Jeu du pendu
Par M@teo21, pour le Site du Z�r0
www.siteduzero.com

dico.c
------

Ces fonctions piochent au hasard un mot dans un fichier dictionnaire
pour le jeu du pendu
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../include/dico.h"


int piocherMot(char *motPioche)
{
    FILE* dico = NULL; // Le pointeur de fichier qui va contenir notre fichier
    int nombreMots = 0, numMotChoisi = 0, i = 0;
    int caractereLu = 0;
    char ans[10];

    printf("Choisissez votre mode de difficulte [facile,moyen,difficile]\n");
    scanf("%s", ans);

    if(strcmp(ans, "facile") == 0){
        dico = fopen("../ressource/dictionaire_4.txt", "r"); // On ouvre le dictionnaire en les 
    }
    else if (strcmp(ans, "moyen") == 0){
        dico = fopen("../ressource/dictionaire_5.txt", "r");
    }
    else if (strcmp(ans, "difficile") == 0){
        dico = fopen("../ressource/dictionaire_6.txt", "r");
    }

    else {printf("Erreur\n");
}
    // On v�rifie si on a r�ussi � ouvrir le dictionnaire
    if (dico == NULL) // Si on n'a PAS r�ussi � ouvrir le fichier
    {
        printf("\nImpossible de charger le dictionnaire de mots");
        return 0; // On retourne 0 pour indiquer que la fonction a �chou�
        // A la lecture du return, la fonction s'arr�te imm�diatement.
    }

    // On compte le nombre de mots dans le fichier (il suffit de compter les
    // entr�es \n
    do
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            nombreMots++;
    } while(caractereLu != EOF);

    numMotChoisi = nombreAleatoire(nombreMots); // On pioche un mot au hasard

    // On recommence � lire le fichier depuis le d�but. On s'arr�te lorsqu'on est arriv�s au bon mot
    rewind(dico);
    while (numMotChoisi > 0)
    {
        caractereLu = fgetc(dico);
        if (caractereLu == '\n')
            numMotChoisi--;
    }

    /* Le curseur du fichier est positionn� au bon endroit.
    On n'a plus qu'� faire un fgets qui lira la ligne */
    fgets(motPioche, 100, dico);

    // On vire l'\n � la fin
    motPioche[strlen(motPioche) - 1] = '\0';
    fclose(dico);

    return 1; // Tout s'est bien pass�, on retourne 1
}

int nombreAleatoire(int nombreMax)
{
    srand(time(NULL));
    return (rand() % nombreMax);
}


