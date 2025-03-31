#include "header.h"

int main() {
	Liste* listeUsers = malloc(sizeof(Liste));
	listeUsers->premier = NULL;
	int choix = 0;
	int stop = 0;
	while (stop == 0) {
		printf("\n---SIGMASPHERE---\n1- Ajouter un utilisateur\n2- Ajouter un ami\n3- Publier un message\n4- Afficher les utilisateurs\n5- Afficher une liste d'amis\n6- Afficher un profil\n7- Quitter\n");
		scanf_s("%d", &choix);
		getchar();
		switch (choix) {
		case 1:
			createUser(listeUsers);
			break;
		case 2:
			ajoutAmi(listeUsers);
			break;
		case 3:
			createPublication(listeUsers);
			break;
		case 4:
			afficheUsers(listeUsers);
			break;
		case 5:
			afficheAmis(listeUsers);
			break;
		case 6:
			afficherProfil(listeUsers);
			break;
		case 7:
			stop = 1;
			break;
		}
	}

	libereUser(listeUsers->premier);
	free(listeUsers);

	return 0;
}