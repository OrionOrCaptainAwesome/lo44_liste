/*
 * Fichier code source liste.c pour le projet test_liste
 * Auteur : GIRAUD Pierre  / mardi 8 novembre 2016, 15:09:48 (UTC+0100)
 * Ce document est sous Licence LGPL
 * voir : http://www.gnu.org/licenses/lgpl-3.0.html
 */

//Definition liste chainee d entiers

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"
#include "liste.h"


liste creer_liste(void)
{
	liste L;
	L = NULL;
	return L;
}


BOOL estVide(liste L)
{
        return L==NULL;
}

liste dernier(liste L)
{
	if (estVide(L))
	{
		return L;
	}
	else
	{
		liste d;
		d = L;
		while (d->suivant != NULL)
		{
			d = d->suivant;
		}
	}
	return d;
}

liste nouveauElement(void)
{
	liste nouvElem;
	nouvElem = (element*)malloc(sizeof(element));
	nouvElem = NULL;
	return nouvElem;
}


liste ajouterTete(liste L, int val)
{
	liste temp;
	temp = nouveauElement();
	temp->valeur = val;
	temp->suivant = L;
	return temp;
}

liste ajouterQueue(liste L, int val)
{
	liste temp;
	liste d;

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

liste supprimerTete(liste L)
{
	if (estVide(L))
    	{
        	return L;
    	}
    	else
    	{
		liste temp;
		temp = L->suivant;
		free(L);
        	return temp;
    	}
}

liste succ(liste L)
{
        if (estVide(L))
        {
		printf("La liste est vide !");
                return L;
        }
        else
        {
	        return L->suivant;
        }	
}

liste supprimerQueue(liste L)
{
    if (estVide(L))
    {
        return L;
    }
    else
    {
        if (L->suivant != NULL)
        {
            liste temp = L;
            liste q;
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

void afficherListe(liste L)
{
    liste temp;
    temp = L;
    while (temp->suivant != NULL)
    {
        printf("Valeur de l'élément pointer : %d \n", temp->valeur);
    	if (temp->suivant == NULL)
    	{
		printf("Valeur de l'élément pointer : %d \n", temp->valeur);
	}
	temp = temp->suivant;
    }
}

int valeurTete(liste L)
{
	if (estVide(L))
	{
		printf("Code erreur NTM !! La liste est vide mais il faut une valeur de retour par defaut a 0");
		return 	0;
	}
	else
	{
		return L->valeur;
	}
}

int nbElement(liste L)
{
	if (estVide(L))
	{
		printf("La liste est vide !");
		return 0;
	}
	else	
	{
	        int nbElement = 0;
	        liste temp;
        	temp = L;

		while (temp->suivant != NULL)
		{
			nbElement++;
		}
		return nbElement + 1;
	}
}

BOOL existe(liste L, int val)
{
	if (estVide(L))
	{
		printf("La liste est vide !");
		return FALSE;
	}
	else
	{
		BOOL estContenu = FALSE;
		liste temp = L;
		while (temp->suivant != NULL)
		{
			if (temp->valeur == val)
			{
				return TRUE;
			}
			temp = temp->suivant;
		}
		if (temp->suivant == NULL)
		{
			if (temp->valeur == val)
                        {
                                return TRUE;
                        }
		}
	}
	return estContenu;
}

