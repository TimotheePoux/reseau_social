#include "header.h"

int main() {
	Liste* listeUsers = malloc(sizeof(Liste));
	listeUsers->premier = NULL;
	int choix = 0;
	int stop = 0;
	while (stop == 0) {
		printf("\n---SIGMASPHERE---\n1- Ajouter un utilisateur\n2- Ajouter un ami\n3- Supprimer un ami X\n4- Publier un message\n5- Afficher les utilisateurs\n6- Afficher une liste d'amis\n7- Afficher un profil\n8- Quitter\n");
		scanf_s("%d", &choix);
		getchar();
		switch (choix) {
		case 1:
			createUser(listeUsers);
			break;
		case 2:
			ajoutAmi(listeUsers);
			break;
		case 4:
			createPublication(listeUsers);
			break;
		case 5:
			afficheUsers(listeUsers);
			break;
		case 6:
			afficheAmis(listeUsers);
			break;
		case 7:
			afficherProfil(listeUsers);
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