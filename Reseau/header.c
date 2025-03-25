#include "header.h"

void createUser(Liste* liste) {
	User* newUser = malloc(sizeof(User));
	if (!newUser) {
		return;
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
	newUser->amis = malloc(sizeof(Ami));
	Ami* friend = newUser->amis;
	friend->suivant = NULL;
	newUser->publication = malloc(sizeof(Publication));
	Publication* publi = newUser->publication;
	publi->suivant = NULL;
	//Publication* publi = newUser->publication;
	//strcpy_s(publi->texte, 280, " ");
	newUser->suivant = liste->premier;
	liste->premier = newUser;
	printf("Utilisateur cree !\n");
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

void ajoutAmi(Liste* liste) {
	if (liste->premier == NULL) {
		printf("Aucun utilisateur dans la liste !\n");
		return;
	}
	printf("Liste des utilisateurs:\n");
	afficheUsers(liste);
	char ajouteur[50] = "";
	char ajoute[50] = "";
	if (strcmp(ajouteur, ajoute)) {
		return;
	}
	printf("Qui veut ajouter un ami ? (Entrez son identifiant): ");
	scanf_s("%s", ajouteur, 50);
	getchar();
	printf("Qui veut-il ajouter en ami ? (Entrez son identifiant): ");
	scanf_s("%s", ajoute, 50);
	getchar();
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		if (strcmp(utilisateur->id, ajoute) == 0) {
			Ami* newAmi = malloc(sizeof(Ami));
			User* utilisateur2 = liste->premier;
			while (utilisateur2 != NULL) {
				if (strcmp(utilisateur2->id, ajouteur) == 0) {
					strcpy_s(newAmi->id, 50, ajoute);
					newAmi->suivant = utilisateur2->amis;
					utilisateur2->amis = newAmi;
					printf("Ami ajoute !\n");
				}
				utilisateur2 = utilisateur2->suivant;
			}
		}
		utilisateur = utilisateur->suivant;
	}
}

void createPublication(Liste* liste) {
	if (liste->premier == NULL) {
		printf("Aucun utilisateur dans la liste !\n");
		return;
	}
	printf("Liste des utilisateurs:\n");
	afficheUsers(liste);
	char id[50];
	printf("Entrez l'identifiant de l'utilisateur: ");
	scanf_s("%s", id, 50);
	getchar();
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		if (strcmp(utilisateur->id, id) == 0) {
			Publication* newPublication = malloc(sizeof(Publication));
			if (!newPublication) {
				return;
			}
			printf("Entrez le texte de la publication: ");
			fgets(newPublication->texte, 280, stdin);
			newPublication->suivant = utilisateur->publication;
			utilisateur->publication = newPublication;
			printf("Publication ajoutee avec succes !\n");
			return;
		}
		utilisateur = utilisateur->suivant;
	}
	printf("Utilisateur non trouve !\n");
}

void afficheUsers(Liste* liste) {
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		printf("-> %s (@%s)\n", utilisateur->pseudo, utilisateur->id);
		utilisateur = utilisateur->suivant;
	}
}

void afficheAmis(Liste* liste) {
	printf("Liste des utilisateurs:\n");
	afficheUsers(liste);
	char id[50];
	printf("Entrez l'identifiant de l'utilisateur: ");
	scanf_s("%s", id, 50);
	getchar();
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		if (strcmp(utilisateur->id, id) == 0) {
			Ami* ami = utilisateur->amis;
			while (ami != NULL) {
				printf("%s\n", ami->id);
				ami = ami->suivant;
			}
		}
		utilisateur = utilisateur->suivant;
	}
}

void afficherProfil(Liste* liste) {
	printf("Liste des utilisateurs:\n");
	afficheUsers(liste);
	char id[50];
	printf("Entrez l'identifiant de l'utilisateur: ");
	scanf_s("%s", id, 50);
	getchar();
	User* utilisateur = liste->premier;
	while (utilisateur != NULL) {
		if (strcmp(utilisateur->id, id) == 0) {
			printf("Profil de %s (@%s)\n", utilisateur->pseudo, utilisateur->id);
			Publication* publication = utilisateur->publication;
			while (publication != NULL) {
				printf("# %s\n", publication->texte);
				publication = publication->suivant;
			}
		}
		utilisateur = utilisateur->suivant;
	}
}

void libereUser(User* user) {
	liberePubli(user->publication);
	libereAmi(user->amis);
	if (user->suivant != NULL) {
		libereUser(user->suivant);
	}
	free(user);
}

void liberePubli(Publication* publication) {
	if (publication != NULL) {
		liberePubli(publication->suivant);
	}
	free(publication);
}

void libereAmi(Ami* ami) {
	if (ami != NULL) {
		libereAmi(ami->suivant);
	}
	free(ami);
}