#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include "absentisme.h"

int x,y,z;
int a=0;


void
on_treeview_louv_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
	gchar* identifiant;
	gchar* nom;
	gchar* prenom;
	gchar* sexe;
	gchar* tache;
	gchar* securite_sociale;
	gchar* jour_dn;
        gchar* mois_dn;
        gchar* annee_dn;

	ouvrier n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &nom, 2, &prenom , 3, &sexe, 4, &tache, 5, &securite_sociale , 6, &jour_dn , 7, &mois_dn , 8, &annee_dn ,-1);
  		strcpy(n.identifiant,identifiant);
		strcpy(n.nom,nom);
		strcpy(n.prenom,prenom);
                strcpy(n.sexe,sexe);
		strcpy(n.tache,tache);
		strcpy(n.ss,securite_sociale);
                n.date_naissance.jour=jour_dn;
                n.date_naissance.mois=mois_dn;
                n.date_naissance.annee=annee_dn;
                
                
                afficher(treeview);
}
}


void
on_button_ajtouv_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetreajtouv;
    Fenetregouv=lookup_widget(objet,"gouv");
    gtk_widget_destroy(Fenetregouv);
    Fenetreajtouv=create_ajtouv();
    gtk_widget_show(Fenetreajtouv);
}


void
on_button_mdfouv_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetremdfouv;
    Fenetregouv=lookup_widget(objet,"gouv");
    gtk_widget_destroy(Fenetregouv);
    Fenetremdfouv=create_mdfouv();
    gtk_widget_show(Fenetremdfouv);
}


void
on_button_suppouv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetresuppouv;
    Fenetregouv=lookup_widget(objet,"gouv");
    gtk_widget_destroy(Fenetregouv);
    Fenetresuppouv=create_suppouv();
    gtk_widget_show(Fenetresuppouv);
}


void
on_button_affouv_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview_louv;

treeview_louv=lookup_widget(objet,"treeview_louv");

afficher(treeview_louv);
}


void
on_button_retouv_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_button_rechouv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetrerechouv;
    Fenetregouv=lookup_widget(objet,"gouv");
    gtk_widget_destroy(Fenetregouv);
    Fenetrerechouv=create_rechouv();
    gtk_widget_show(Fenetrerechouv);
}


void
on_button_mbabs_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetreabsouv;
    Fenetregouv=lookup_widget(objet,"gouv");
    gtk_widget_destroy(Fenetregouv);
    Fenetreabsouv=create_absouv();
    gtk_widget_show(Fenetreabsouv);
}


void
on_button_mbcnfajt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    ouvrier n ;
    GtkWidget *Fenetrescajouv;
    GtkWidget *Fenetreajtouv;
    GtkWidget *input1, *input2, *input3, *input4;
    GtkWidget *jour,*mois,*annee;
    GtkWidget *tache;
    GtkWidget *output1, *output2,*output3,*output4;
    int b=1,v;
    char id[20];

Fenetreajtouv=lookup_widget(objet,"ajtouv");
input1=lookup_widget(objet,"entry_mbidajt");
input2=lookup_widget(objet,"entry_mbnomajt");
input3=lookup_widget(objet,"entry_mbpreajt");
input4=lookup_widget(objet,"entry_mbssajt");
tache=lookup_widget(objet,"combobox_mbtfaj");
jour=lookup_widget(objet,"spinbutton_mbjdnajt");
mois=lookup_widget(objet,"spinbutton_mbmdnajt");
annee=lookup_widget(objet,"spinbutton_mbadnajt");
output1=lookup_widget(objet,"label_mbsnomaj");
output2=lookup_widget(objet,"label_mbspreaj");
output3=lookup_widget(objet,"label_mbsnsaj");
output4=lookup_widget(objet,"label_mbaltaj");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n.identifiant,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
if(strcmp(n.nom,"")==0)
{
gtk_widget_show (output1);
b=0;
}
strcpy(n.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
if(strcmp(n.prenom,"")==0)
{
gtk_widget_show (output2);
b=0;
}
strcpy(n.ss,gtk_entry_get_text(GTK_ENTRY(input4)));
if(strcmp(n.ss,"")==0)
{
gtk_widget_show (output3);
b=0;
}
strcpy(n.tache,gtk_combo_box_get_active_text(GTK_COMBO_BOX(tache)));
n.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(x==1)
{strcpy(n.sexe,"Masculin");}
else
if(x==2)
{strcpy(n.sexe,"Feminin");}

v=verif(id);
if (v==1)
{
gtk_widget_show (output4);
}
else
{
  if(b==1)
{
ajouter(n);

    gtk_widget_destroy(Fenetreajtouv);
    Fenetrescajouv=create_scajouv();
    gtk_widget_show(Fenetrescajouv);
}
}
}


void
on_button_mbanlajt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetreajtouv;
    Fenetreajtouv=lookup_widget(objet,"ajtouv");
    gtk_widget_destroy(Fenetreajtouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
}


void
on_radiobutton_mbfajt_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
}
}


void
on_radiobutton_mbmajt_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
}
}


void
on_button_mbcnfmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
  ouvrier n;

  GtkWidget *Fenetremdfouv;
  GtkWidget *Fenetrescmdfouv;
  GtkWidget *input1, *input2, *input3, *input4;
  GtkWidget *jour,*mois,*annee;
  GtkWidget *tf;

Fenetremdfouv=lookup_widget(objet,"mdfouv");
input1=lookup_widget(objet,"combobox_mbidmdf");
input2=lookup_widget(objet,"entry_mbnommdf");
input3=lookup_widget(objet,"entry_mbpremdf");
input4=lookup_widget(objet,"entry_mbssmdf");
tf=lookup_widget(objet,"combobox_mbtamdf");
jour=lookup_widget(objet,"spinbutton_mbjdnmdf");
mois=lookup_widget(objet,"spinbutton_mbmdnmdf");
annee=lookup_widget(objet,"spinbutton_mbadnmdf");

strcpy(n.identifiant,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
strcpy(n.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(n.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(n.ss,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(n.tache,gtk_combo_box_get_active_text(GTK_COMBO_BOX(tf)));
n.date_naissance.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_naissance.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_naissance.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(y==1)
{strcpy(n.sexe,"Masculin");}
else
if(y==2)
{strcpy(n.sexe,"Feminin");}

modifier(n);

    gtk_widget_destroy(Fenetremdfouv);
    Fenetrescmdfouv=create_scmdfouv();
    gtk_widget_show(Fenetrescmdfouv);
}


void
on_button_mbanlmdf_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetremdfouv;
    Fenetremdfouv=lookup_widget(objet,"mdfouv");
    gtk_widget_destroy(Fenetremdfouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
}


void
on_radiobutton_mbmmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=1;
}
}


void
on_radiobutton_mbfmdf_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=2;
}
}


void
on_button_mbchid_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
  ouvrier n;
  FILE *f;
  GtkWidget *Fenetremdfouv;
  GtkWidget *id;
  GtkWidget *output1,*output2;

Fenetremdfouv=lookup_widget(objet,"mdfouv");
id=lookup_widget(objet,"combobox_mbidmdf");
output1=lookup_widget(objet,"label_mbvldch");
output2=lookup_widget(objet,"label_mbanlchid");

f=fopen("liste_des_ouvriers.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee)!=EOF)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(id),_(n.identifiant));
}
fclose(f);

gtk_widget_hide(output2);
gtk_widget_show (output1);
}


void
on_button_mbvldchid_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
  ouvrier n;
  FILE *f;
  GtkWidget *Fenetremdfouv;
  GtkWidget *id;
  GtkWidget *output1,*output2;
  GtkWidget *input1,*input2,*input3;
   char id1[20];
   char nom1[20];
   char prenom1[20];
   char ss1[20];

Fenetremdfouv=lookup_widget(objet,"mdfouv");
id=lookup_widget(objet,"combobox_mbidmdf");
output1=lookup_widget(objet,"label_mbvldch");
output2=lookup_widget(objet,"label_mbanlchid");
input1=lookup_widget(objet,"entry_mbnommdf");
input2=lookup_widget(objet,"entry_mbpremdf");
input3=lookup_widget(objet,"entry_mbssmdf");

strcpy(id1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
f=fopen("liste_des_ouvriers.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee)!=EOF)
{
if(strcmp(n.identifiant,id1)==0)
{
strcpy(nom1,n.nom);
strcpy(prenom1,n.prenom);
strcpy(ss1,n.ss);
}
}
fclose(f);

gtk_entry_set_text(input1,nom1);
gtk_entry_set_text(input2,prenom1);
gtk_entry_set_text(input3,ss1);

gtk_widget_hide(output2);
gtk_widget_hide(output1);
}


void
on_button_mbanlchid_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Fenetremdfouv;
  GtkWidget *output1,*output2;

Fenetremdfouv=lookup_widget(objet,"mdfouv");
output1=lookup_widget(objet,"label_mbvldch");
output2=lookup_widget(objet,"label_mbanlchid");

gtk_widget_hide(output1);
gtk_widget_show (output2);
}


void
on_treeview_mbtxtrech_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
        GtkTreeIter iter;
	gchar* identifiant;
	gchar* nom;
	gchar* prenom;
	gchar* sexe;
	gchar* tache;
	gchar* securite_sociale;
	gchar* jour_dn;
        gchar* mois_dn;
        gchar* annee_dn;

	ouvrier n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &nom, 2, &prenom , 3, &sexe, 4, &tache, 5, &securite_sociale , 6, &jour_dn , 7, &mois_dn , 8, &annee_dn ,-1);
  		strcpy(n.identifiant,identifiant);
		strcpy(n.nom,nom);
		strcpy(n.prenom,prenom);
                strcpy(n.sexe,sexe);
		strcpy(n.tache,tache);
		strcpy(n.ss,securite_sociale);
                n.date_naissance.jour=jour_dn;
                n.date_naissance.mois=mois_dn;
                n.date_naissance.annee=annee_dn;
                
                
                afficher(treeview);
}
}


void
on_button_mbretrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetrerechouv;
    Fenetrerechouv=lookup_widget(objet,"rechouv");
    gtk_widget_destroy(Fenetrerechouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
}


void
on_button_mbcnfrech_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetrerechouv;
   GtkWidget *id,*crt;
   GtkWidget *treeviewrech;
   GtkWidget *output1,*output2;
   char filtre[20];
   char critere[20];
   int v;
   
Fenetrerechouv=lookup_widget(objet,"rechouv");
id=lookup_widget(objet,"entry_mbidrech");
treeviewrech=lookup_widget(objet,"treeview_mbtxtrech");
output1=lookup_widget(objet,"label_mbtxtrech");
output2=lookup_widget(objet,"label_mbaltrech");
crt=lookup_widget(objet,"combobox_mbcrrech");

strcpy(filtre,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(critere,gtk_combo_box_get_active_text(GTK_COMBO_BOX(crt)));

v=verifrech(filtre);
if(v!=1)
{
   gtk_widget_hide(output1);
    gtk_widget_show (output2);
}
else
{
   gtk_widget_hide(output2);
   gtk_widget_show (output1);

filtrecritere(treeviewrech, critere, filtre);
}
}


void
on_treeview_mbabs_row_activated        (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
       GtkTreeIter iter;
	gchar* identifiant;
	gchar* jour;
	gchar* mois;
	gchar* annee;
	gchar* abs;	

	ouv n;
        FILE *f=NULL;
        
	GtkTreeModel *model = gtk_tree_view_get_model(treeview1);
	if (gtk_tree_model_get_iter(model, &iter ,path))
	{
		
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 0, &identifiant, 1, &jour, 2, &mois , 3, &annee, 4, &abs ,-1);
  		strcpy(n.identifiant,identifiant);
		strcpy(n.abs,abs);
                n.date_abs.jour=jour;
                n.date_abs.mois=mois;
                n.date_abs.annee=annee;
                afficherabs(treeview1);
}  
}


void
on_button_mbretabs_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetreabsouv;
    Fenetreabsouv=lookup_widget(objet,"absouv");
    gtk_widget_destroy(Fenetreabsouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
}


void
on_checkbutton_mboabs_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{
a=1;
}
}


void
on_button_mbchidabs_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
  ouvrier n;
  FILE *f;
  GtkWidget *Fenetreabsouv;
  GtkWidget *id;

Fenetreabsouv=lookup_widget(objet,"absouv");
id=lookup_widget(objet,"combobox_mbidabs");

f=fopen("liste_des_ouvriers.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee)!=EOF)
{
gtk_combo_box_append_text (GTK_COMBO_BOX(id),_(n.identifiant));
}
fclose(f);
}


void
on_button_mbtabs_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
   ouv n;
   GtkWidget *Fenetreabsouv;
   GtkWidget *id;
   GtkWidget *treeviewabs;
   GtkWidget *mois,*annee;
   GtkWidget *output1,*output2,*output3;
   char idouv[20];
   char moisabs[20],anneeabs[20];

Fenetreabsouv=lookup_widget(objet,"absouv");
id=lookup_widget(objet,"combobox_mbidabs");
treeviewabs=lookup_widget(objet,"treeview_mbabs");
mois=lookup_widget(objet,"spinbutton1_mbmaffabs");
annee=lookup_widget(objet,"spinbutton_mbaaffabs");
output1=lookup_widget(objet,"label_mbscajabs");
output2=lookup_widget(objet,"label_mbscmdfabs");
output3=lookup_widget(objet,"label_mbscspabs");

strcpy(idouv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
sprintf(moisabs,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois)));
sprintf(anneeabs,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee)));

rechabs(treeviewabs, idouv, moisabs, anneeabs);
gtk_widget_hide (output1);
gtk_widget_hide (output2);
gtk_widget_hide (output3);
}


void
on_button_mbcnfabs_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    ouv n;
    GtkWidget *Fenetreabsouv;
    GtkWidget *id,*jour,*mois,*annee;
    GtkWidget *output1,*output2,*output3,*output4;
    char idouv[20];
    int v,j,m,a;

Fenetreabsouv=lookup_widget(objet,"absouv");
id=lookup_widget(objet,"combobox_mbidabs");
jour=lookup_widget(objet,"spinbutton_mbjabs");
mois=lookup_widget(objet,"spinbutton_mbmabs");
annee=lookup_widget(objet,"spinbutton_mbaabs");
output1=lookup_widget(objet,"label_mbscajabs");
output2=lookup_widget(objet,"label_mbscmdfabs");
output3=lookup_widget(objet,"label_mbscspabs");
output4=lookup_widget(objet,"label_mbvrdate");

strcpy(idouv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
strcpy(n.identifiant,idouv);
n.date_abs.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_abs.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_abs.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(a==0)
{n.abs=0;}
else
if(a==1)
{n.abs=1;}

v=verifdate(j,m,a);
if(v==1)
  {
gtk_widget_show (output4);
  }
else
  {
absentisme(n);

gtk_widget_show (output1);
gtk_widget_hide (output2);
gtk_widget_hide (output3);
  }
}


void
on_button_mbmdfabs_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    ouv n;
    GtkWidget *Fenetreabsouv;
    GtkWidget *id,*jour,*mois,*annee;
    GtkWidget *output1,*output2,*output3;
    char idouv[20];

Fenetreabsouv=lookup_widget(objet,"absouv");
id=lookup_widget(objet,"combobox_mbidabs");
jour=lookup_widget(objet,"spinbutton_mbjabs");
mois=lookup_widget(objet,"spinbutton_mbmabs");
annee=lookup_widget(objet,"spinbutton_mbaabs");
output1=lookup_widget(objet,"label_mbscajabs");
output2=lookup_widget(objet,"label_mbscmdfabs");
output3=lookup_widget(objet,"label_mbscspabs");

strcpy(idouv,gtk_combo_box_get_active_text(GTK_COMBO_BOX(id)));
strcpy(n.identifiant,idouv);
n.date_abs.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
n.date_abs.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
n.date_abs.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
if(a==0)
{n.abs=0;}
else
if(a==1)
{n.abs=1;}

modifierabs(n);

gtk_widget_show (output2);
gtk_widget_hide (output1);
gtk_widget_hide (output3);
}


void
on_button_mbspabs_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetreabsouv;
   GtkWidget *id;
   GtkWidget *output1,*output2,*output3;
   char idsp[20];
    Fenetreabsouv=lookup_widget(objet,"absouv");
id=lookup_widget(objet,"combobox_mbidabs");
output1=lookup_widget(objet,"label_mbscajabs");
output2=lookup_widget(objet,"label_mbscmdfabs");
output3=lookup_widget(objet,"label_mbscspabs");

strcpy(idsp,gtk_entry_get_text(GTK_ENTRY(id)));
supprimerabs(idsp);

gtk_widget_show (output3);
gtk_widget_hide (output1);
gtk_widget_hide (output2);
}


void
on_button_mbcnfsp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetrescspouv;
    GtkWidget *Fenetresuppouv;
    GtkWidget *id;
    GtkWidget *output;
   char idsp[20];
   int v;

    Fenetresuppouv=lookup_widget(objet,"suppouv");
id=lookup_widget(objet,"entry_mbidsp");
output=lookup_widget(objet,"label_mbaltsp");
strcpy(idsp,gtk_entry_get_text(GTK_ENTRY(id)));

v=verif(idsp);

if(v!=1)
{
    gtk_widget_show (output);
}
else
{
 if(z==1)
{
supprimer(idsp);

    gtk_widget_destroy(Fenetresuppouv);
    Fenetrescspouv=create_scspouv();
    gtk_widget_show(Fenetrescspouv);
}
}
}


void
on_button_mbanlsp_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetresuppouv;
    Fenetresuppouv=lookup_widget(objet,"suppouv");
    gtk_widget_destroy(Fenetresuppouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
}


void
on_radiobutton_mbnsp_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetresuppouv;
   GtkWidget *output1;

Fenetresuppouv=lookup_widget(objet,"suppouv");
output1=lookup_widget(objet,"label_mbcnfsp");
z=0;

    gtk_widget_hide (output1);
}


void
on_radiobutton_mbosp_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Fenetresuppouv;
   GtkWidget *output1;

Fenetresuppouv=lookup_widget(objet,"suppouv");
output1=lookup_widget(objet,"label_mbcnfsp");
z=1;

    gtk_widget_show (output1);
}


void
on_button_okajouv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetrescajouv;
    GtkWidget *treeview_louv;
    Fenetrescajouv=lookup_widget(objet,"scajouv");
    gtk_widget_destroy(Fenetrescajouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
    treeview_louv=lookup_widget(Fenetregouv,"treeview_louv");

afficher(treeview_louv);

}


void
on_button_okmdfouv_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetrescmdfouv;
    GtkWidget *treeview_louv;
    Fenetrescmdfouv=lookup_widget(objet,"scmdfouv");
    gtk_widget_destroy(Fenetrescmdfouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
    treeview_louv=lookup_widget(Fenetregouv,"treeview_louv");

afficher(treeview_louv);
}


void
on_button_okspouv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
    GtkWidget *Fenetregouv;
    GtkWidget *Fenetrescspouv;
    GtkWidget *treeview_louv;
    Fenetrescspouv=lookup_widget(objet,"scspouv");
    gtk_widget_destroy(Fenetrescspouv);
    Fenetregouv=create_gouv();
    gtk_widget_show(Fenetregouv);
treeview_louv=lookup_widget(Fenetregouv,"treeview_louv");

afficher(treeview_louv);

}

