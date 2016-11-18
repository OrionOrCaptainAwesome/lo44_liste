/* fichier main.c (fait partie de : test_liste)
 * Auteur:  GIRAUD Pierre
 * Date:  mardi 8 novembre 2016, 15:08:41 (UTC+0100)
 * Ce document est sous Licence :  GPL v3
 * voir :  http://www.gnu.org/licenses/gpl-3.0.html
 */

#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
#include "boolean.h"
#include "efface_ecran.h"

int main(void)
{
	Liste maListe = initialiserListe();
	//maListe = initialiserListe(maListe);
	afficherListe(maListe);

	return EXIT_SUCCESS;
}

/*
Liste initialiserListe(Liste L);
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
*/
