// utilisateur.h
#ifndef UTILISATEUR_H
#define UTILISATEUR_H

typedef struct Utilisateur {
    char nom[100];
    char prenom[100];
    int mdp;
    int sexe;
    int role;
    int id;
} Utilisateur;

int ajouterUtilisateur(char *filename, Utilisateur u);
int modifierUtilisateur(char *filename, int id, Utilisateur nouv);
int supprimerUtilisateur(char *filename, int ident);
Utilisateur chercherUtilisateur(char *filename, int id);

void UserRole(char nomFichier[], int role);
void pourcentageUser(char nomFichier[], float *nbHomme, float *nbFemme);

#endif


