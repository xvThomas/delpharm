// Syntaxe "" ou <>
// #include stdio
// #include string
// #include stdlib
// #include ctype

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* liste chainee */
typedef struct liste
{
	char *mot;
	struct liste *suiv;
} LISTE;

void affiche(const LISTE *list)
{
    while (list)
    {
        printf("%s\n",list->mot);
        list=list->suiv;
    }
}

int main(int argc, char *argv[])
{
	char chaine[]="liste de mot que l'on veut stocker dans une liste chainee";
	char *pos;

	/* recherche des mots avec strtok -> voir annexe pour son fonctionnement */
	pos=strtok(chaine," ");

    // Eventuellement ,si la chaine est vide on sort (ce qui n'est pas le cas ici, mais c'est plus propre)
    if (pos == NULL) {
      return 0;
    }

    // initialisation de la première cellule de la liste chainée correspondant au premier mot
	LISTE *cour = (LISTE *) malloc(sizeof(LISTE));
    // la tête est la première cellule de la liste, à ce titre elle est déclarée constante
    const LISTE *tete = cour;

    while (pos)
	{
        if (cour == NULL) return 1;
        // allocation de la chaine de caractère devant contenir le mot et copie du mot courant
        cour->mot = (char *) malloc(strlen(pos) + 1);
		strcpy(cour->mot, pos);

		pos=strtok(NULL," ");
		if (pos)
			cour->suiv = (LISTE *) malloc(sizeof(LISTE));
		else
			cour->suiv = NULL;
		cour=cour->suiv;
	}
	affiche(tete);
}