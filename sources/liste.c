/*
 * Fichier code source liste.c pour le projet test_liste
 * Auteur : GIRAUD Pierre  / mardi 8 novembre 2016, 15:09:48 (UTC+0100)
 * Ce document est sous Licence LGPL
 * voir : http://www.gnu.org/licenses/lgpl-3.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#include "boolean.h"
#include "liste.h"


Liste initialiserListe(void) 
{
	return NULL;
}


BOOL estVide(Liste L)
{
        return L == NULL;
}

Liste dernier(Liste L)
{
	if (estVide(L))
	{
		return L;
	}
	else
	{
		Liste d = L;
		while (succ(d) != NULL)
		{
			d = succ(d);
		}
		return d;
	}
}

Liste nouveauElement(void)
{
	Liste nouvElem;
	nouvElem = (Element*)malloc(sizeof(Element));
	return nouvElem;
}


Liste ajouterTete(Liste L, int val)
{
	Liste temp;
	temp = nouveauElement();
	temp->valeur = val;
	temp->suivant = L;
	return temp;
}

Liste ajouterQueue(Liste L, int val)
{
	Liste temp;
	Liste d;

	temp = nouveauElement();
	temp->valeur = val;
	temp->suivant = NULL; 
	
	if (estVide(L))
	{
		L = temp;
	}
	else
	{
		d = dernier(L);
		d->suivant = temp;
	}
	
	return L;
}

Liste supprimerTete(Liste L)
{
	if (estVide(L))
    	{
		printf("La liste est vide ! impossible de supprimer la tete\n");
        	return L;
    	}
    	else
    	{
		Liste temp;
		temp = succ(L);
		free(L);
        	return temp;
    	}
}

Liste succ(Liste L)
{
        if (estVide(L))
        {
                return L;
        }
        else
        {
	        return L->suivant;
        }	
}

Liste supprimerQueue(Liste L)
{
    if (estVide(L))
    {
	printf("La liste est vide ! impossible de supprimer la queue \n");
        return L;
    }
    else
    {
	Liste temp = L;
        
	if (succ(temp) != NULL)
        {
            Liste q = L;
	    while (succ(q) != NULL)
            {
		temp = q;
                q = succ(q);
            }
            succ(temp) = NULL;
	    free(q);
        }
        else
        {
	    free(L);
	    L = NULL;
        }
	return L;
    }
}

void afficherListe(Liste L)
{
    if (estVide(L))
    {
        printf("La liste est vide ! impossible de l'afficher [-> NULL]\n");
    }
    else
    {
        Liste temp = L;
        printf("[");

        while (!estVide(temp))
        {
            printf(" %d ->", valeurTete(temp));
	    temp = succ(temp);
	}
        printf(" NULL]\n", valeurTete(temp));
    }
}

int valeurTete(Liste L)
{
	if (estVide(L))
	{
		printf("La liste est vide mais il faut une valeur de retour par defaut a 0\n");
		return 	0;
	}
	else
	{
		return L->valeur;
	}
}

int nbElement(Liste L)
{
	if (estVide(L))
	{
		printf("La liste est vide donc il ny a aucun element !\n");
		return 0;
	}
	else	
	{
        	int nbElement = 0;
	        Liste temp = L;

		while (!estVide(temp))
		{
			temp = succ(temp);
			nbElement++;
		}
		return nbElement;
	}
}

BOOL existe(Liste L, int val)
{
	BOOL estContenu = FALSE;

	if (estVide(L))
	{
		printf("La liste est vide donc forcement la valeur (%d) nexiste pas !\n", val);
		estContenu = FALSE;
	}
	else
	{
		Liste temp = L;
		while (!estVide(temp) && estContenu == FALSE)
		{
			if (valeurTete(temp) == val)
			{
				estContenu = TRUE;
			}
			temp = succ(temp);
		}
	}
	return estContenu;
}
