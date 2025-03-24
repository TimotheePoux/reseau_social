#ifndef RESEAUX
#define RESEAUX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Publication;

typedef struct {
	char texte[280];
	struct Publication* suivant;
}Publication;

typedef struct {
	char id[50];
	char pseudo[50];
	struct Publication* publication;
	struct User** amis;
	struct User* suivant;
}User;

typedef struct {
	struct User* premier;
}Liste;

void createUser(Liste* liste);
int verifId(Liste* liste, char identifiant[50]);
void afficheUsers(Liste* liste);
void libereUser(User* user);
void liberePubli(Publication* publication);

#endif
