#include "header.h"

int main() {
	Liste* listeUsers = malloc(sizeof(Liste));
	listeUsers->premier = NULL;
	int choix = 0;
	int stop = 0;
	while (stop == 0) {
		printf("\n---SIGMASPHERE---\n1- Ajouter un utilisateur\n2- Ajouter un ami X\n3- Supprimer un ami X\n4- Publier un message X\n5- Afficher les utilisateurs\n6- Afficher une liste d'amis X\n7- Afficher un profil X\n8- Quitter\n");
		scanf_s("%d", &choix);
		getchar();
		switch (choix) {
		case 1:
			createUser(listeUsers);
			break;
		case 5:
			afficheUsers(listeUsers);
			break;
		case 8:
			stop = 1;
			break;
		}
	}

	libereUser(listeUsers->premier);
	free(listeUsers);

	return 0;
}