#include <stdio.h>
#include <stdlib.h>
#include "utilisateur.h"
#include <gtk/gtk.h>
int ajouterUtilisateur(char *filename, Utilisateur u) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fprintf(f, "%s %s %d %d %d %d\n", u.nom, u.prenom, u.mdp, u.sexe, u.role, u.id);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}

int modifierUtilisateur(char *filename, int id, Utilisateur nouv) {
    int tr = 0;
    Utilisateur u;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %d %d %d %d ", u.nom, u.prenom, &u.mdp, &u.sexe, &u.role, &u.id) != EOF) {
            if (u.id == id) {
                fprintf(f2, "%s %s %d %d %d %d\n", nouv.nom, nouv.prenom, nouv.mdp, nouv.sexe, nouv.role, nouv.id);
                tr = 1;
            } else {
                fprintf(f2, "%s %s %d %d %d %d\n", u.nom, u.prenom, u.mdp, u.sexe, u.role, u.id);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimerUtilisateur(char *filename, int ident) {
    int tr = 0;
    Utilisateur u;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %d %d %d %d", u.nom, u.prenom, &u.mdp, &u.sexe, &u.role, &u.id) != EOF) {
            if (u.id == ident) {
                tr = 1;
            } else {
                fprintf(f2, "%s %s %d %d %d %d \n", u.nom, u.prenom, u.mdp, u.sexe, u.role, u.id);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

Utilisateur chercherUtilisateur(char *filename, int id) {
    Utilisateur u;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s %d %d %d %d", u.nom, u.prenom, &u.mdp, &u.sexe, &u.role, &u.id) != EOF) {
            if (u.id == id) {
                tr = 1;
                break;
            }
        }
    }
    fclose(f);
    if (tr == 0) {
        u.id = -1;
    }
    return u;
}


void UserRole(char nomFichier[], int role) {
    Utilisateur u;
    FILE *f = fopen(nomFichier, "r");
    FILE *f2 = fopen("utilisateurs_role.txt", "w");
    
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %d %d %d %d", u.nom, u.prenom, &u.mdp, &u.sexe, &u.role, &u.id) != EOF) {
            if (u.role == role) {
                fprintf(f2, "%s %s %d %d %d %d\n", u.nom, u.prenom, u.mdp, u.sexe, u.role, u.id);
            }
        }
    }
    
    fclose(f);
    fclose(f2);
}

void pourcentageUser(char nomFichier[], float *nbHomme, float *nbFemme) {
    Utilisateur u;
    FILE *f = fopen(nomFichier, "r");
    
    int totalHommes = 0;
    int totalFemmes = 0;
    int totalUtilisateurs = 0;

    if (f != NULL) {
        while (fscanf(f, "%s %s %d %d %d %d", u.nom, u.prenom, &u.mdp, &u.sexe, &u.role, &u.id) != EOF) {
            if (u.sexe == 0) {
                totalHommes++;
            } else if (u.sexe == 1) {
                totalFemmes++;
            }
            totalUtilisateurs++;
        }
    }

    fclose(f);

    if (totalUtilisateurs > 0) {
        *nbHomme = ((float)totalHommes / totalUtilisateurs) * 100;
        *nbFemme = ((float)totalFemmes / totalUtilisateurs) * 100;
    } else {
        *nbHomme = 0;
        *nbFemme = 0;
    }
}
/*****************************************************************************************************************************************************/
void Afficherproduit(GtkWidget* treeview1,char*l)
{
	GtkListStore *adstore;/*creation du modele de type liste*/
	GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
	GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
	FILE *f;
	Utilisateur u;
        int i;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT,
				     G_TYPE_INT,
          	       	             G_TYPE_INT,
				     G_TYPE_INT
                                     );
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %d %d %d %d ",u.nom,u.prenom,&u.mdp,&u.sexe,&u.role,&u.id)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,u.nom,
                            1,u.prenom,
                            2,u.mdp,
                            3,u.sexe,
                            4,u.role,
                            5,u.id,
                            -1);}
        fclose(f);

/* Creation de la 1ere colonne */
if(i==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("nom",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("prenom",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
/* Ajouter la 2emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("mot de passe",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
/* Ajouter la 3emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("sexe(0:HOMME | 1:Femme)",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
/* Ajouter la 4emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("role",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
/* Ajouter la 5emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("id",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
/* Ajouter la 6emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);



i++;}


  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
}
/***************************************************************************************************************************/

