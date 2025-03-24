#include "header.h"

void createUser(Liste* liste) {
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
		printf("Identifiant deja utilise !\n");
	}
	printf("Entrez un pseudo: ");
	scanf_s("%s", newUser->pseudo, 50);
	getchar();
	newUser->publication = malloc(sizeof(Publication));
	Publication* publi = newUser->publication;
	strcpy_s(publi->texte, 280, " ");
	newUser->suivant = liste->premier;
	liste->premier = newUser;
}

int verifId(Liste* liste, char identifiant[50]) {
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		if (strcmp(utilisateur->id, identifiant) == 0) {
			return 0;
		}
		utilisateur = utilisateur->suivant;
	}
	return 1;
}

void afficheUsers(Liste* liste) {
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		printf("-> %s (@%s)\n", utilisateur->pseudo, utilisateur->id);
		utilisateur = utilisateur->suivant;
	}
}

void libereUser(User* user) {
	liberePubli(user->publication);
	if (user->suivant != NULL) {
		libereUser(user->suivant);
	}
	free(user);
}

void liberePubli(Publication* publication) {
	if (publication->suivant != NULL) {
		liberePubli(publication->suivant);
	}
	free(publication);
}