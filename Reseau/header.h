#ifndef RESEAUX
#define RESEAUX

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char texte[280];
	struct Publication* suivant;
}Publication;

typedef struct {
	char id[50];
	char pseudo[50];
	struct Publication* publication;
	struct Liste* amis;
	struct User* suivant;
}User;

typedef struct {
	struct User* premier;
}Liste;

#endif
