# Pearl-Khousheeta_JeuPendu
# TP -SE_Jeu tu sera pendu
Ce TP consiste  faire le jeu de Tu sera pendu, Devinette des mots

## On vera comment:
- Comment Compiler
- Comment Executer
- Comment Utiliser

## Le but du  TP

- De Faire le jeu tu sera pendu, et choisir un mot au hasard
- Il poura faire le choix entre facile,moyenne,difficile et depend il aura un nombre de mots
- Il peut avoir un aide,au cas ou c'est trop diffcile
- Il pourait avoir que 8 chance de faire des fautes


## Compilation

Les command utiliser pour git 
On la fait fonction sur terminal
Apres la creation d'un dossier sur le local
- cd bin
- [cmake ..]
- [make] 
le main.c se trouve dans le bin d'ou on a compiler le dossier


## Comment on l'execute
Pour l'executation du script apres avoir mis les codage et les droits par chmod u+x
On biensur apres avoir compiler on fait l'appelle par ./pendu non par ./main.c


L'etape avant execution
```sh
gcc pendu main.c
chmod u+x pendu
```

L'execution

```sh
./pendu
```
On a fait l'execution sur terminal vous pouvez le faire sur sublime text.

## Comment Utiliser
## MAIN.C
### Premiere Etape
Mettre les declaration 
```sh
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "../include/dico.h"

int gagne(int lettreTrouvee[], long tailleMot);
int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[]);
char lireCaractere();

int main(int argc, char* argv[])
```
### Deuixeme Etape
A inisialiser tout les comptes a zero ou ou nombre necessaire
```sh
{
    char lettre = 0; // Stocke la lettre proposée par l'utilisateur (retour du scanf)
    char motSecret[100] = {0}; // Ce sera le mot à trouver
    int *lettreTrouvee = NULL; // Un tableau de booléens. Chaque case correspond à une lettre du mot secret. 0 = lettre non trouvée, 1 = lettre trouvée
    long coupsRestants = 10; // Compteur de coups restants (0 = mort)
    long i = 0; // Une petite variable pour parcourir les tableaux
    long tailleMot = 0;
```
### Troiseme Etape
On cherche les mots hosaires pour l'interloguteur,tout en savoir la tailles du mots, si c'est facile,moyenn ou diffcile
```sh

    printf("Bienvenue dans le Pendu !\n\n");

    if (!piocherMot(motSecret))
        exit(0);

    tailleMot = strlen(motSecret);

    lettreTrouvee = malloc(tailleMot * sizeof(int)); // On alloue dynamiquement le tableau lettreTrouvee (dont on ne connaissait pas la taille au départ)
```
### Quatrieme Etape
On fait un loop pour savoir si on bien prit un mots
Aucun mots choisie
```sh
    if (lettreTrouvee == NULL)
        exit(0);
```
Un mot a ete choisit
```sh
    for (i = 0 ; i < tailleMot ; i++)
        lettreTrouvee[i] = 0;
```

La boucle pour continue a jouer apres un echouement d'essai.

// On continue à jouer tant qu'il reste au moins un coup à jouer ou qu'on
// n'a pas gagné
```sh
    while (coupsRestants > 0 && !gagne(lettreTrouvee, tailleMot))
    {
        printf("\n\nIl vous reste %ld coups a jouer", coupsRestants);
        printf("\nQuel est le mot secret ? ");

        /* On affiche le mot secret en masquant les lettres non trouvées
        Exemple : A*ON */
        for (i = 0 ; i < tailleMot ; i++)
        {
            if (lettreTrouvee[i]) // Si on a trouvé la lettre n°i
                printf("%c", motSecret[i]); // On l'affiche
            else
                printf("_"); // Sinon, on affiche under score pour les lettres non trouvées
        }
```
Ici on demand a l'interloguteur de propose des lettre ou mots d'essai
```sh

        printf("\nProposez une lettre : ");
        lettre = lireCaractere();

        // Si ce n'était PAS la bonne lettre
        if (!rechercheLettre(lettre, motSecret, lettreTrouvee))
        {
            coupsRestants--; // On enlève un coup au joueur
        }
    }
```
Il va seulement indiquez sur l'ecran le mots secret ou la lettre apres le boucle de verification
```sh
    if (gagne(lettreTrouvee, tailleMot))
        printf("\n\nGagne ! Le mot secret etait bien : %s\n\n", motSecret);
    else
        printf("\n\nPerdu ! Le mot secret etait : %s\n\n", motSecret);

    free(lettreTrouvee); // On libère la mémoire allouée manuellement (par malloc)

        return 0;
}
```
### Cinqeme Etape
On peut accepter les majuscule ou les minuscule durant la proposition des lettres.
```sh
char lireCaractere()
{
    char caractere = 0;

    caractere = getchar(); // On lit le premier caractère
    caractere = toupper(caractere); // On met la lettre en majuscule si elle ne l'est pas déjà

    // On lit les autres caractères mémorisés un à un jusqu'à l'\n
    while (getchar() != '\n') ;

    return caractere; // On retourne le premier caractère qu'on a lu
}
'''
### Sixeme Etape
C'est la fonction pour recevoir des indices.
```sh
char hint(char z)
{
    char caractere = 0;

    caractere = z;
    caractere = toupper(caractere);


    while (getchar() != '\n') ;

    return caractere;
}
'''

'''sh

### Sixeme Etape
Ici qu'on verifie si la lettre correspond au mots ou le mots que l'interlocuteur a mis et retourne bonne lettre ou mot
```sh
int gagne(int lettreTrouvee[], long tailleMot)
{
    long i = 0;
    int joueurGagne = 1;

    for (i = 0 ; i < tailleMot ; i++)
    {
        if (lettreTrouvee[i] == 0)
            joueurGagne = 0;
    }

    return joueurGagne;
}

int rechercheLettre(char lettre, char motSecret[], int lettreTrouvee[])
{
    long i = 0;
    int bonneLettre = 0;

    // On parcourt motSecret pour vérifier si la lettre proposée y est
    for (i = 0 ; motSecret[i] != '\0' ; i++)
    {
        if (lettre == motSecret[i]) // Si la lettre y est
        {
            bonneLettre = 1; // On mémorise que c'était une bonne lettre
            lettreTrouvee[i] = 1; // On met à 1 le case du tableau de booléens correspondant à la lettre actuelle
        }
    }

    return bonneLettre;
}
```

## Collaborateur 
La proprietaire est:
Pearl Begue
Collaborateur est :
Khousheeta Jebodh



