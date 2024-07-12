#include <stdio.h>

int compte_ligne(FILE *file,int *nombre_ligne)							//source de la fonction qui compte le nombre de ligne dans le fichier
{
	char c;
	int nbr_ligne;
	nbr_ligne =0;
	do
	{
		c = fgetc(file);
		if(c == '\n')
			nbr_ligne++;
	}
	while(!feof(file));
    return nbr_ligne;
}

void tail(FILE *file,int nombre_ligne,int n)							//source de la fonction qui affiche les n lignes
{
	char c;
	int i;
	i =0;
	do
	{
		c = fgetc(file);
		if(c == '\n')
			i++;
		if (i >= (nombre_ligne - n ))
			printf("%c",c);
	}
	while(!feof(file));
}

