/*
 * Fichier d'en tête liste.h pour le projet test_liste
 * Auteur : GIRAUD Pierre  / lundi 14 novembre 2016, 10:15:24 (UTC+0100)
 * Ce document est sous Licence GPL v3
 * voir : http://www.gnu.org/licenses/gpl-3.0.html
 */

#include <stdlib.h>
#include <stdio.h>
#include "boolean.h"



#ifndef __LISTE__H__
#define __LISTE__H__

typedef struct Elem Elem;
typedef struct Elem {
                int valeur;
                Elem *suivant;
}Element;

typedef Element *Liste;


//ajouter toutes les entete de fonction genre ci dessous
/**
 * Fonction qui fait d'autres choses
 * m (float**) : Matrice qui stocke quelque chose
 * r (int) : nombre de lignes de m
 * c (int) : nombre de colonnes de m
 * returns quelque chose (float**)
 */


/* Prototypes des fonctions */

Liste initialiserListe(void);
BOOL estVide(Liste L);
Liste dernier(Liste L);
Liste nouveauElement(void);
Liste ajouterTete(Liste L, int val);
Liste ajouterQueue(Liste L, int val);
Liste supprimerTete(Liste L);
Liste succ(Liste L);
Liste supprimerQueue(Liste L);
void afficherListe(Liste L);
int valeurTete(Liste L);
int nbElement(Liste L);
BOOL existe(Liste L, int val);

#endif /* __LISTE__H__ */

