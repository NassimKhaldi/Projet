#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"

int v=0,sexe,sexe1,r;

int a;
void
on_treeviewnk_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	gchar *nom;
        gchar *prenom;
        int *sexe;
        int *role;
        int *id;
	int *mdp;
       
	
        GtkTreeModel *model;
        GtkTreeIter iter;
        GtkWidget *treeview2=lookup_widget(treeview,"treeviewnk");
        GtkTreeSelection *selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview2));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
                gtk_tree_model_get (model,&iter,0,nom,1,prenom,2,&mdp,3,&sexe,4,&role,5,&id,-1);
}
}


void
on_btn_modifier_nassim_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nassimwindow,*modifiernassim;
	
	nassimwindow=lookup_widget(objet_graphique,"nassimwindow");
	gtk_widget_destroy(nassimwindow);
	modifiernassim=create_modifiernassim();
	gtk_widget_show(modifiernassim);	
}


void
on_btn_supprimer_nassim_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nassimwindow,*supprimernassim;
	
	nassimwindow=lookup_widget(objet_graphique,"nassimwindow");
	gtk_widget_destroy(nassimwindow);
	supprimernassim=create_supprimernassim();
	gtk_widget_show(supprimernassim);
}


void
on_btn_chercher_nassim_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
char IDENT111[50];
int ident,x;
Utilisateur u ;
GtkWidget *entridsup;
GtkWidget* treeview2;
entridsup=lookup_widget(button,"entrycherchernas");

strcpy(IDENT111,gtk_entry_get_text(GTK_ENTRY(entridsup) ) );

ident=atoi(IDENT111);
u=chercherUtilisateur("utilisateur.txt",ident);
x=u.id;
GtkWidget* cherchhh;
cherchhh=lookup_widget(button,"nassimwindow");

	
	treeview2=lookup_widget(cherchhh, "treeviewnk") ;
	
	Afficherproduit(treeview2,"utilisateur.txt");
}


void
on_pourcentage_sexe_clicked            (GtkWidget       *objet_graphique, gpointer	user_data)
{
GtkWidget *nassimwindow,*statistique;
	
	nassimwindow=lookup_widget(objet_graphique,"nassimwindow");
	gtk_widget_destroy(nassimwindow);
	statistique=create_statistique();
	gtk_widget_show(statistique);
}


void
on_home_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nassimwindow,*gestionwindow;
	
	nassimwindow=lookup_widget(objet_graphique,"nassimwindow");
	gtk_widget_destroy(nassimwindow);
	gestionwindow=create_gestionwindow();
	gtk_widget_show(gestionwindow);
}


void
on_btn_ajout_nassim_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *nassimwindow,*ajoutnassim;
	
	nassimwindow=lookup_widget(objet_graphique,"nassimwindow");
	gtk_widget_destroy(nassimwindow);
	ajoutnassim=create_ajoutnassim();
	gtk_widget_show(ajoutnassim);
}


void on_ajouter_nassim_clicked(GtkButton *button, gpointer user_data)
{
    Utilisateur u;

    GtkWidget *entryNom;
    GtkWidget *entryPrenom;
    GtkWidget *entryid;
    GtkWidget *entrymdp;

    GtkWidget *combobox4;
    GtkWidget *entryrole;
    GtkWidget *treeview2;
    GtkWidget *affiche;
    GtkWidget *ajout;
    ajout = lookup_widget(button, "ajoutnassim");

    char nom[50], prenom[50], id11[50], mdp11[50], role11[50];
    int role, id, mdp;

    entryNom = lookup_widget(button, "entry1_nom");
    entryPrenom = lookup_widget(button, "entry2_prenom");
    entrymdp = lookup_widget(button, "entry3_mdp");
    entryrole = lookup_widget(button, "comboboxentry1_role");
    entryid = lookup_widget(button, "entry4_id");

    strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(entryNom)));
    strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
    strcpy(id11, gtk_entry_get_text(GTK_ENTRY(entryid)));
    strcpy(mdp11, gtk_entry_get_text(GTK_ENTRY(entrymdp)));
    strcpy(role11, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole)));

    if (strcmp(role11, "Medecin biologiste") == 0)
        u.role = 0;
    else if (strcmp(role11, "Infermier") == 0)
        u.role = 1;
    else
        u.role = 2;

	
    u.sexe = sexe;
 

    u.id = atoi(id11);
    u.mdp = atoi(mdp11);
	

if (v==1){
	a=ajouterUtilisateur("utilisateur.txt",u);
        gtk_widget_destroy(ajout);
	affiche=create_nassimwindow();
	gtk_widget_show(affiche);
	treeview2=lookup_widget(affiche, "treeviewnk") ;
	Afficherproduit(treeview2,"utilisateur.txt");	
	
}
}


void
on_radiobutton1_hnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{sexe=0;}
}


void
on_radiobutton2_fnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{sexe=1;}
}


void
on_im_not_robot_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{v=1;}
}


void
on_button_retour_ajout_nassim_clicked  (GtkButton       *button,
                            		gpointer         user_data)
{
}


void
on_radiobutton3_hnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{sexe1=0;}
}


void
on_radiobutton4_fnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{sexe1=1;}
}


void
on_confirmer_nassim_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
    Utilisateur u;
    GtkWidget *entryNom1;
    GtkWidget *entryPrenom1;
    GtkWidget *entryid1;
    GtkWidget *entrymdp1;

    GtkWidget *combobox;
    GtkWidget *entryrole1;
    GtkWidget *treeview2;
    GtkWidget *affiche1;
    GtkWidget *modifier;
    modifier = lookup_widget(button, "modifiernassim");

    char nom[50], prenom[50], id11[50], mdp11[50], role11[50];
    int role, id, mdp, ident;

    entryNom1 = lookup_widget(button, "entry5_nom");
    entryPrenom1 = lookup_widget(button, "entry6_prenom");
    entrymdp1 = lookup_widget(button, "entry7_mdp");
    entryrole1 = lookup_widget(button, "comboboxentry2_role");
    entryid1 = lookup_widget(button, "entry8_id");

    strcpy(u.nom, gtk_entry_get_text(GTK_ENTRY(entryNom1)));
    strcpy(u.prenom, gtk_entry_get_text(GTK_ENTRY(entryPrenom1)));
    strcpy(id11, gtk_entry_get_text(GTK_ENTRY(entryid1)));
    strcpy(mdp11, gtk_entry_get_text(GTK_ENTRY(entrymdp1)));
    strcpy(role11, gtk_combo_box_get_active_text(GTK_COMBO_BOX(entryrole1)));

    if (strcmp(role11, "Medecin biologiste") == 0)
        u.role = 0;
    else if (strcmp(role11, "Infermier") == 0)
        u.role = 1;
    else
        u.role = 2;

	
    u.sexe = sexe;
    u.id = atoi(id11);
    ident = atoi(id11);
    u.mdp = atoi(mdp11);
	

if (r==1){
	int m=modifierUtilisateur("utilisateur.txt",ident,u);
        gtk_widget_destroy(modifier);
	affiche1=create_nassimwindow();
	gtk_widget_show(affiche1);
	treeview2=lookup_widget(affiche1, "treeviewnk") ;
	Afficherproduit(treeview2,"utilisateur.txt");
}	
}


void
on_button_retour_modifier_nassim_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_nassim_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char IDENT11[50];
int ident,x;
Utilisateur u ;
GtkWidget *entridsup;
GtkWidget* treeview2;
entridsup=lookup_widget(button,"entry9_id_supprimer");

strcpy(IDENT11,gtk_entry_get_text(GTK_ENTRY(entridsup) ) );

ident=atoi(IDENT11);
x=supprimerUtilisateur("utilisateur.txt",ident);
GtkWidget* suprim;
GtkWidget* affiche;
suprim=lookup_widget(button,"supprimernassim");
gtk_widget_destroy(suprim);
affiche=create_nassimwindow();
gtk_widget_show(affiche);
treeview2=lookup_widget(affiche, "treeviewnk") ;	
Afficherproduit(treeview2,"utilisateur.txt");
}


void
on_button_retour_supprimer_nassim_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_chercher_nassim_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_retour_chercher_nassim_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_nassim_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_btnstat_clicked                     (GtkWidget       *objet_graphique, gpointer	user_data)
{
char nbh[20]="";
char nbf[20]="";
GtkWidget *labelhomme ,*labelfemme;
labelhomme=lookup_widget(objet_graphique,"labelhomme");
labelfemme=lookup_widget(objet_graphique,"labelfemme");

float nbhomme;
float nbfemme;
    pourcentageUser("utilisateur.txt", &nbhomme, &nbfemme);
    printf("Percentage of Men: %.2f%%\n", nbhomme);
    printf("Percentage of Women: %.2f%%\n", nbfemme);


sprintf(nbh,"%.2f",nbhomme); 
sprintf(nbf,"%.2f",nbfemme);
strcat(nbh,"%");
strcat(nbf,"%");

gtk_label_set_text(GTK_LABEL(labelhomme),nbh);
gtk_label_set_text(GTK_LABEL(labelfemme),nbf);
}


void
on_btn_actualise_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1, *affiche,*affiche1;
affiche1 = lookup_widget(objet_graphique, "nassimwindow");
gtk_widget_destroy(affiche1);
affiche=create_nassimwindow();
gtk_widget_show(affiche);
treeview1=lookup_widget(affiche, "treeviewnk");
Afficherproduit(treeview1,"utilisateur.txt");
}


void
on_imnotrobot2_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton))) 
	{r=1;}
}


void
on_afficherole_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget *spinbtn;
	spinbtn = lookup_widget(objet_graphique, "spinbuttonrole");
	int role=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbtn));
	UserRole("utilisateur.txt",role);


	GtkWidget *treeview1, *affiche,*affiche1;
	affiche1 = lookup_widget(objet_graphique, "nassimwindow");
	gtk_widget_destroy(affiche1);
	affiche=create_nassimwindow();
	gtk_widget_show(affiche);
	treeview1=lookup_widget(affiche, "treeviewnk");
	Afficherproduit(treeview1,"utilisateurs_role.txt");	

}

