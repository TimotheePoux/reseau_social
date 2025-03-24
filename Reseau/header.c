#include "header.h"


User* createUser(Liste* liste) {
	User* newUser = malloc(sizeof(User));
	if (!newUser) {
		return NULL;
	}
	while (1) {
		printf("Entrez un identifiant: ");
		scanf_s("%s", newUser->id, 50);
		getchar();
		if (verifId(liste, newUser->id) == 1) {
			break;
		}
		printf("Identifiant déjà utilise !\n");
	}
	printf("Entrez un pseudo: ");
	scanf_s("%s", newUser->pseudo, 50);
	getchar();
	newUser->amis = NULL;
	newUser->publication = NULL;
	newUser->suivant = liste->premier;
	liste->premier = newUser;
}

int verifId(Liste* liste, char pseudo[50]) {
	User* utilisateur = liste->premier;
	while (utilisateur->suivant != NULL) {
		if (utilisateur->pseudo == pseudo) {
			return 0;
		}
		utilisateur = utilisateur->suivant;
	}
	return 1;
}