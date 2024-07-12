#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "PrototypeLiat.h"

int main (int argc ,char *argv[])
{
	FILE *file;
	int nombre_ligne ,nombre_caractere,i,n,charNumber0,charNumber;
	char c ;
	nombre_ligne = 0 ;
	nombre_caractere = 0;
	i = 0 ;
	n = 0;

		file = fopen (argv[argc -1 ],"rw");										//ouvret le fichier 
		if (file == NULL)
		{
			printf("Erreur dans la foction fopen\n");
			exit(1);
		}
		else
		{
			if (argc == 2)
			{	
				nombre_ligne = compte_ligne(file,&nombre_ligne);				//Appel de la fonction qui compte le nombre de ligne dans le fichier
				rewind(file);													//reinitialise le curseur dans le fichier
				n = 10;
				tail(file,nombre_ligne,n);										//Appel de la fonction qui affiche les n lignes
				fclose(file);													//ferme le fichier
			}
			else
			{ 	
				if((strcmp(argv[1] , "-c")) == 0 ) 								//Option -c
				{
					while(!feof(file))
					{
						c = fgetc(file);
							nombre_caractere++;
					}
					rewind(file);
					do
					{
						c = fgetc(file);
							i++;
						if ( i >= (nombre_caractere - atoi(argv[2])))
							printf("%c",c);
					}
					while(!feof(file));
					fclose(file);												//ferme le fichier
				}
				if((strcmp(argv[1],"-n")) == 0)									//Option -n
				{ 
					nombre_ligne = compte_ligne(file,&nombre_ligne);			//Appel de la fonction qui compte le nombre de ligne dans le fichier
					rewind(file);												//reinitialise le curseur dans le fichier
					tail(file,nombre_ligne,atoi(argv[2]));						//Appel de la fonction qui affiche les n lignes
					fclose(file);												//ferme le fichier
				}
				if((strcmp(argv[1],"-v")) == 0)									//Option -v
				{
					printf("==> %s <==\n" , argv[argc - 1]);
					nombre_ligne = compte_ligne(file,&nombre_ligne);			//Appel de la fonction qui compte le nombre de ligne dans le fichier
					rewind(file);												//reinitialise le curseur dans le fichier
					n = 10;
					tail(file,nombre_ligne,n);									//Appel de la fonction qui affiche les n lignes
					fclose(file);												//ferme le fichier
				}
				if((strcmp(argv[1],"-f")) == 0)									//Option -f
				{
					while ((c = fgetc(file)) != EOF)
					{
						putchar(c);
					}

					while (1)
					{
						while ((i = fgetc(file)) != EOF)
							charNumber ++;

						if (charNumber >= charNumber0)
						{
							charNumber0 = charNumber;

							file = fopen(argv[argc -1], "r");

							while ((c = fgetc(file)) != EOF)
							{
								putchar(c);
							}
							fclose(file);										//ferme le fichier
						}
						sleep(1);
						system("clear");
					}
				}
			} 
		}
return (0);
}
