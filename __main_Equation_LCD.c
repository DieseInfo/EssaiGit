//***************************************************************************************
/*
 Nom		:	_main.c
 But		:	mettre en oeuvre les différentes ressources du kit de développement Keil MCBSTM32
            		Résolution de l'équation ax²+bx+c = 0
            		Affichage du résultat sur l'écran LCD du kit Keil
 Processeur 	: 	STM32F103RB (Arm Cortex M3, Flash 128Lo, Ram 20Ko)
 			(kit de développement Keil)
 Auteur		:	Joël Pétrique
 Date		:	novembre 2018
 Vérifié	:	mai 2019
*/


//*****************************************************************************
// Inclusion des fichiers prototypes standard
#include <stdio.h>					// pour la fonction "sprintf"
#include <stm32f10x.h>				// Device header

#include <math.h>						// pour la fonction math "sqrt"

// Inclusion des fichiers prototypes "faits maison" du dossier "Library"
#include "Library\LCD.h"			// nécessaire pour utiliser l'écran du kit Keil



//*****************************************************************************
// Prototypes des fonctions développées plus bas
//==============================================

// Ecriture d'un texte à une position X, Y
// Reçoit 3 paramètres :
//        - un entier x signifiant la position X sur l'écran
//        - un entier y      "      "      "   Y  "     "
//        - l'ADRESSE d'un texte à afficher
void EcrireXY (int x, int y, char *texte);

// Ecriture d'un nombre réel à une position X, Y
// Reçoit 3 paramètres :
//        - un entier x signifiant la position X sur l'écran
//        - un entier y      "      "      "   Y  "     "
//        - une valeur réelle (type "double") à afficher
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

	// Calcul des racines de l'équation
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
	sprintf (ligne1, "x1=%lf", x1);    // j'écris dans la chaîne de caractères (tableau de char) "ligne1"
	EcrireXY (0, 0, ligne1);           // j'écris la chaîne "ligne1" sur l'écran du kit Keil

	EcrireReelXY (0, 1, x2);           // variante avec une nouvelle fonction : j'écris le réel x2 sur l'écran du kit Keil
	
	//LCD_set_cursor (0, 0);		
	//LCD_print (ligne1);
	//LCD_set_cursor (0, 1);
	//LCD_print (ligne2);
	return 0;
}


//*****************************************************************************
// Ecriture d'un texte à une position X, Y
// Reçoit 3 paramètres :
//        - un entier x signifiant la position X sur l'écran
//        - un entier y      "      "      "   Y  "     "
//        - l'ADRESSE d'un texte à afficher
void EcrireXY (int x, int y, char *texte)
{	// Je positionne le curseur
	LCD_set_cursor (x, y);		
	
	// J'écris à l'écran
	LCD_print (texte);
}


//*****************************************************************************
// Ecriture d'un nombre réel à une position X, Y
// Ecriture d'un nombre réel à une position X, Y
// Reçoit 3 paramètres :
//        - un entier x signifiant la position X sur l'écran
//        - un entier y      "      "      "   Y  "     "
//        - une valeur réelle (type "double") à afficher
void EcrireReelXY (int x, int y, double valeur)
{	char texte[40];     // "texte" tableau de 40 char, variable LOCALE à la fonction "EcrireReelXY"
	
	// J'écris la variable dans le tableau de char "texte",
	//	avec le format "%lf" ("long float", alias "double")
	// la valeur reçue en paramètre
	sprintf (texte, "%lf", valeur);
	
	// Je positionne le curseur
	LCD_set_cursor (x, y);		
	
	// Et j'écris le texte calculé sur l'écran du kit Keil
	LCD_print (texte);
}
