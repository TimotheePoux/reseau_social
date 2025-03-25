#ifndef RESEAUX
#define RESEAUX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char texte[280];
	struct Publication* suivant;
} Publication;

typedef struct {
	char id[50];
	struct Ami* suivant;
} Ami;

typedef struct {
	char id[50];
	char pseudo[50];
	struct Publication* publication;
	struct Ami* amis;
	struct User* suivant;
} User;

typedef struct {
	struct User* premier;
} Liste;

void createUser(Liste* liste);
int verifId(Liste* liste, char identifiant[50]);
void ajoutAmi(Liste* liste);
void createPublication(Liste* liste);
void afficheUsers(Liste* liste);
void afficheAmis(Liste* liste);
void afficherProfil(User* utilisateur);
void libereUser(User* user);
void liberePubli(Publication* publication);
void libereAmi(Ami* ami);

#endif
