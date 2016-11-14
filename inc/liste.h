/*
 * Fichier d'en tête liste.h pour le projet test_liste
 * Auteur : GIRAUD Pierre  / lundi 14 novembre 2016, 10:15:24 (UTC+0100)
 * Ce document est sous Licence GPL v3
 * voir : http://www.gnu.org/licenses/gpl-3.0.html
 */
#include "boolean.h"

#ifndef __LISTE__H__
#define __LISTE__H__


typedef struct element	{
			int valeur;
			element *suivant;
			}element;
			
typedef element *liste;


BOOL estVide(liste L);
liste dernier(liste L);
liste nouveauElement(void);
liste ajouterTete(liste L, int val);
liste ajouterQueue(liste L, int val);

liste supprimerTete(liste L);
liste succ(liste L);
liste supprimerQueue(liste L);
void afficherListe(liste L);
int valeurTete(liste L);
int nbElement(liste L);
BOOL existe(liste L, int val);


#endif /* __LISTE__H__ */

