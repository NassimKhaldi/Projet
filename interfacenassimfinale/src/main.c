/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *nassimwindow;
  GtkWidget *ajoutnassim;
  GtkWidget *modifiernassim;
  GtkWidget *supprimernassim;
  GtkWidget *youssefwindow;
  GtkWidget *ajoutyoussef;
  GtkWidget *modifieryoussef;
  GtkWidget *supprimeryoussef;
  GtkWidget *salmawindow;
  GtkWidget *ajoutsalma;
  GtkWidget *modifiersalma;
  GtkWidget *supprimersalma;
  GtkWidget *mariemwindow;
  GtkWidget *ajoutmariem;
  GtkWidget *modifiermariem;
  GtkWidget *supprimermariem;
  GtkWidget *statistique;
  GtkWidget *pourcentagedemande;
  GtkWidget *daliwindow;
  GtkWidget *ajoutdali;
  GtkWidget *modifierdali;
  GtkWidget *supprimerwindow;
  GtkWidget *omarwindow;
  GtkWidget *ajoutomar;
  GtkWidget *modifieromar;
  GtkWidget *supprimeromar;
  GtkWidget *gestionwindow;
  GtkWidget *loginwindow;
  GtkWidget *cherchernassim;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  nassimwindow = create_nassimwindow ();
  gtk_widget_show (nassimwindow);
  /*ajoutnassim = create_ajoutnassim ();
  gtk_widget_show (ajoutnassim);
  modifiernassim = create_modifiernassim ();
  gtk_widget_show (modifiernassim);
  supprimernassim = create_supprimernassim ();
  gtk_widget_show (supprimernassim);
  youssefwindow = create_youssefwindow ();
  gtk_widget_show (youssefwindow);
  ajoutyoussef = create_ajoutyoussef ();
  gtk_widget_show (ajoutyoussef);
  modifieryoussef = create_modifieryoussef ();
  gtk_widget_show (modifieryoussef);
  supprimeryoussef = create_supprimeryoussef ();
  gtk_widget_show (supprimeryoussef);
  salmawindow = create_salmawindow ();
  gtk_widget_show (salmawindow);
  ajoutsalma = create_ajoutsalma ();
  gtk_widget_show (ajoutsalma);
  modifiersalma = create_modifiersalma ();
  gtk_widget_show (modifiersalma);
  supprimersalma = create_supprimersalma ();
  gtk_widget_show (supprimersalma);
  mariemwindow = create_mariemwindow ();
  gtk_widget_show (mariemwindow);
  ajoutmariem = create_ajoutmariem ();
  gtk_widget_show (ajoutmariem);
  modifiermariem = create_modifiermariem ();
  gtk_widget_show (modifiermariem);
  supprimermariem = create_supprimermariem ();
  gtk_widget_show (supprimermariem);
  statistique = create_statistique ();
  gtk_widget_show (statistique);
  pourcentagedemande = create_pourcentagedemande ();
  gtk_widget_show (pourcentagedemande);
  daliwindow = create_daliwindow ();
  gtk_widget_show (daliwindow);
  ajoutdali = create_ajoutdali ();
  gtk_widget_show (ajoutdali);
  modifierdali = create_modifierdali ();
  gtk_widget_show (modifierdali);
  supprimerwindow = create_supprimerwindow ();
  gtk_widget_show (supprimerwindow);
  omarwindow = create_omarwindow ();
  gtk_widget_show (omarwindow);
  ajoutomar = create_ajoutomar ();
  gtk_widget_show (ajoutomar);
  modifieromar = create_modifieromar ();
  gtk_widget_show (modifieromar);
  supprimeromar = create_supprimeromar ();
  gtk_widget_show (supprimeromar);
  gestionwindow = create_gestionwindow ();
  gtk_widget_show (gestionwindow);
  loginwindow = create_loginwindow ();
  gtk_widget_show (loginwindow);
  cherchernassim = create_cherchernassim ();
  gtk_widget_show (cherchernassim);*/

  gtk_main ();
  return 0;
}

