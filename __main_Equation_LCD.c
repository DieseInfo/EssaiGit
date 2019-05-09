//***************************************************************************************
/*
 Nom		:	_main.c
 But		:	mettre en oeuvre les diff�rentes ressources du kit de d�veloppement Keil MCBSTM32
            R�solution de l'�quation ax�+bx+c = 0
            Affichage du r�sultat sur l'�cran LCD du kit Keil
 Processeur : STM32F103RB (Arm Cortex M3, Flash 128Lo, Ram 20Ko)
 Auteur	:	Jo�l P�trique
 Date		:	novembre 2018
*/


//*****************************************************************************
// Inclusion des fichiers prototypes standard
#include <stdio.h>					// pour la fonction "sprintf"
#include <stm32f10x.h>				// Device header

#include <math.h>						// pour la fonction math "sqrt"

// Inclusion des fichiers prototypes "faits maison" du dossier "Library"
#include "Library\LCD.h"			// n�cessaire pour utiliser l'�cran du kit Keil



//*****************************************************************************
// Prototypes des fonctions d�velopp�es plus bas
//==============================================

// Ecriture d'un texte � une position X, Y
// Re�oit 3 param�tres :
//        - un entier x signifiant la position X sur l'�cran
//        - un entier y      "      "      "   Y  "     "
//        - l'ADRESSE d'un texte � afficher
void EcrireXY (int x, int y, char *texte);

// Ecriture d'un nombre r�el � une position X, Y
// Re�oit 3 param�tres :
//        - un entier x signifiant la position X sur l'�cran
//        - un entier y      "      "      "   Y  "     "
//        - une valeur r�elle (type "double") � afficher
void EcrireReelXY (int x, int y, double valeur);



//***************************************************************************************
// Fonction main
//==============
int main (void)
{	double a, b, c, x1, x2, delta, racine;
	char ligne1[40];        // tableau de 40 "char"
	
	LCD_init ();
	
	a = 1;	b = 4;	c = 0;
	delta = (b * b) - (4 * a * c);

	// Calcul des racines de l'�quation
	if (delta < 0)
	{	x1 = x2 = 0;		// juste pour ne pas avoir n'importe quoi dans x1 et x2...
	}
	if (delta == 0)
	{	x1 = x2 = -b / (2 * a);
	}
	if (delta > 0)
	{	racine = sqrt (delta);
		x1 = (-b -racine) / (2 * a);
		x2 = (-b +racine) / (2 * a);
	}

	// Affichage des resultats
	sprintf (ligne1, "x1=%lf", x1);    // j'�cris dans la cha�ne de caract�res (tableau de char) "ligne1"
	EcrireXY (0, 0, ligne1);           // j'�cris la cha�ne "ligne1" sur l'�cran du kit Keil

	EcrireReelXY (0, 1, x2);           // variante avec une nouvelle fonction : j'�cris le r�el x2 sur l'�cran du kit Keil
	
	//LCD_set_cursor (0, 0);		
	//LCD_print (ligne1);
	//LCD_set_cursor (0, 1);
	//LCD_print (ligne2);
	return 0;
}


//*****************************************************************************
// Ecriture d'un texte � une position X, Y
// Re�oit 3 param�tres :
//        - un entier x signifiant la position X sur l'�cran
//        - un entier y      "      "      "   Y  "     "
//        - l'ADRESSE d'un texte � afficher
void EcrireXY (int x, int y, char *texte)
{	// Je positionne le curseur
	LCD_set_cursor (x, y);		
	
	// J'�cris � l'�cran
	LCD_print (texte);
}


//*****************************************************************************
// Ecriture d'un nombre r�el � une position X, Y
// Ecriture d'un nombre r�el � une position X, Y
// Re�oit 3 param�tres :
//        - un entier x signifiant la position X sur l'�cran
//        - un entier y      "      "      "   Y  "     "
//        - une valeur r�elle (type "double") � afficher
void EcrireReelXY (int x, int y, double valeur)
{	char texte[40];     // "texte" tableau de 40 char, variable LOCALE � la fonction "EcrireReelXY"
	
	// J'�cris la variable dans le tableau de char "texte",
	//	avec le format "%lf" ("long float", alias "double")
	// la valeur re�ue en param�tre
	sprintf (texte, "%lf", valeur);
	
	// Je positionne le curseur
	LCD_set_cursor (x, y);		
	
	// Et j'�cris le texte calcul� sur l'�cran du kit Keil
	LCD_print (texte);
}
