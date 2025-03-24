#ifndef RESEAUX
#define RESEAUX

#include <stdio.h>
#include <stdlib.h>


typedef struct {
	char id[50];
	char pseudo[50];
	char publication[280];
	struct User* suivant;
}User;

typedef struct {
	struct User* premier;
}Liste;

#endif
