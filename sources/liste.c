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


Liste initialiserListe(Liste L)
{
	return L = NULL;
}


BOOL estVide(Liste L)
{
        return L == NULL;
}

Liste dernier(Liste L)
{
	Liste d;
	if (estVide(L))
	{
		return L;
	}
	else
	{
		d = L;
		while (d->suivant != NULL)
		{
			d = d->suivant;
		}
	}
	return d;
}

Liste nouveauElement(void)
{
	Liste nouvElem;
	nouvElem = (Element*)malloc(sizeof(Element));
	nouvElem = NULL;
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
        	return L;
    	}
    	else
    	{
		Liste temp;
		temp = L->suivant;
		free(L);
        	return temp;
    	}
}

Liste succ(Liste L)
{
        if (estVide(L))
        {
		printf("\nLa liste est vide , je vais retourner la meme liste !\n");
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
        return L;
    }
    else
    {
        if (L->suivant != NULL)
        {
            Liste temp = L;
            Liste q;
            while (temp->suivant != NULL)
            {
                temp = temp->suivant;
                q=temp;
            }
            q->suivant = NULL;
	    free(temp);
            return L;
        }
        else
        {
	    free(L->suivant);
            return L;
        }
    }
}

void afficherListe(Liste L)
{
    if (estVide(L))
    {
        printf("[liste vide valeur et suivant = NULL]");
    }
    else
    {
        Liste temp;
        temp = L;
        printf("[");
        while (temp->suivant != NULL)
        {
            printf(" %d ->", temp->valeur);
            if (temp->suivant == NULL)
    	    {
	        printf(" %d -> NULL]\n", temp->valeur);
	    }
	    temp = temp->suivant;
        }
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
		printf("La liste est vide donc l'element n'a pas ete trouver !\n");
		return 0;
	}
	else	
	{
	        int nbElement = 0;
	        Liste temp;
        	temp = L;

		while (temp->suivant != NULL)
		{
			nbElement++;
		}
		return nbElement + 1;
	}
}

BOOL existe(Liste L, int val)
{
	BOOL estContenu = FALSE;

	if (estVide(L))
	{
		printf("La liste est vide donc forcement il existe pas !\n");
		estContenu = FALSE;
	}
	else
	{
		Liste temp = L;
		while (temp->suivant != NULL)
		{
			if (temp->valeur == val)
			{
				estContenu = TRUE;
			}
			temp = temp->suivant;
		}
		if (temp->suivant == NULL)
		{
			if (temp->valeur == val)
                        {
                                estContenu = TRUE;
                        }
		}
	}
	return estContenu;
}

