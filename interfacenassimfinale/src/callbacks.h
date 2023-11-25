#include <gtk/gtk.h>


void
on_treeviewnk_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_btn_modifier_nassim_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_btn_chercher_nassim_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_pourcentage_sexe_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_home_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_btn_ajout_nassim_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_btn_supprimer_nassim_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_ajouter_nassim_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_hnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_fnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_im_not_robot_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retour_ajout_nassim_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton3_hnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_fnas_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confirmer_nassim_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retour_modifier_nassim_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_nassim_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_nassim_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_btnstat_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_btn_actualise_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_imnotrobot2_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_afficherole_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
