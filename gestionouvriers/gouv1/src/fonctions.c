#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>

enum
{
    EIDENTIFIANT,
    ENOM,
    EPRENOM,
    ESEXE,
    ESS,
    ETACHE,
    EJOUR_N,
    EMOIS_N,
    EANNEE_N,
    
    COLUMNS,
};

    
void ajouter(ouvrier n)
{

 FILE *f;
 f=fopen("liste_des_ouvriers.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %s  %d %d %d\n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,n.date_naissance.jour,n.date_naissance.mois,n.date_naissance.annee);

 fclose(f);
 }

}

void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char nom[20];
char prenom[20];
char sexe[20];
char ss[20];
char tache[30];
char jour_naissance[20];
char mois_naissance[20];
char annee_naissance[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("ss",renderer,"text",ESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("tache",renderer,"text",ETACHE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	



renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_naissance",renderer,"text",EJOUR_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_naissance",renderer,"text",EMOIS_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_naissance",renderer,"text",EANNEE_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_ouvriers.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_ouvriers.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",identifiant,nom,prenom,sexe,ss,tache,jour_naissance,mois_naissance,annee_naissance)!=EOF)
		{
          

			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);

		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void chercher(GtkWidget *liste, char id[])
{
    
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char nom[20];
char prenom[20];
char sexe[20];
char ss[20];
char tache[30];
char jour_naissance[20];
char mois_naissance[20];
char annee_naissance[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("ss",renderer,"text",ESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("tache",renderer,"text",ETACHE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	



renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_naissance",renderer,"text",EJOUR_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_naissance",renderer,"text",EMOIS_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_naissance",renderer,"text",EANNEE_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_ouvriers.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_ouvriers.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",identifiant,nom,prenom,sexe,ss,tache,jour_naissance,mois_naissance,annee_naissance)!=EOF)
		{
            if(strcmp(identifiant,id)==0)
{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void modifier(ouvrier n)
{
char id1[20];
char prenom1[20];
char nom1[20];
char sexe1[20];
char ss1[20];
char tache1[30];
    int jdn;
    int mdn;
    int adn;
    	

FILE *f;
FILE *f1;

f=fopen("liste_des_ouvriers.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %d %d %d \n",id1,nom1,prenom1,sexe1,ss1,tache1,&jdn,&mdn,&adn)!=EOF)
{
if (strcmp(n.identifiant,id1)==0)
	fprintf(f1,"%s %s %s %s %s %s %d %d %d\n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,n.date_naissance.jour,n.date_naissance.mois,n.date_naissance.annee);

else
	fprintf(f1,"%s %s %s %s %s %s %d %d %d\n",id1,nom1,prenom1,sexe1,ss1,tache1,jdn,mdn,adn);

}
fclose(f);
fclose(f1);
remove("liste_des_ouvriers.txt");
rename("modif.txt","liste_des_ouvriers.txt");
}

void supprimer(char idsp[])
{
FILE *f;
FILE *f1;
ouvrier n;
f=fopen("liste_des_ouvriers.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s %d %d %d \n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee)!=EOF)
{
	if (strcmp(n.identifiant,idsp)!=0)	
	fprintf(f1,"%s %s %s %s %s %s %d %d %d\n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,n.date_naissance.jour,n.date_naissance.mois,n.date_naissance.annee);

}
fclose(f);
fclose(f1);
remove("liste_des_ouvriers.txt");
rename("doc.txt","liste_des_ouvriers.txt");
}


int verif(char id[])
{
    
    FILE *f=NULL;
    ouvrier n;
    int test;
    f=fopen("liste_des_ouvriers.txt","r");
    test=0;
    if(f!=NULL)
    {
       while(fscanf(f,"%s %s %s %s %s %s %d %d %d \n",n.identifiant,n.nom,n.prenom,n.sexe,n.ss,n.tache,&n.date_naissance.jour,&n.date_naissance.mois,&n.date_naissance.annee)!=EOF)
       {
         if(strcmp(n.identifiant,id)==0)
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}

void filtrecritere(GtkWidget *liste, char critere[], char filtre[])
{
    
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char nom[20];
char prenom[20];
char sexe[20];
char ss[20];
char tache[30];
char jour_naissance[20];
char mois_naissance[20];
char annee_naissance[20];


store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("ss",renderer,"text",ESS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("tache",renderer,"text",ETACHE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	



renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour_naissance",renderer,"text",EJOUR_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois_naissance",renderer,"text",EMOIS_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee_naissance",renderer,"text",EANNEE_N,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	


	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("liste_des_ouvriers.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("liste_des_ouvriers.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",identifiant,nom,prenom,sexe,ss,tache,jour_naissance,mois_naissance,annee_naissance)!=EOF)
		{
            if(strcmp(critere,"identifiant")==0)
{
         if(strcmp(filtre,identifiant)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
}
            if(strcmp(critere,"nom")==0)
{
         if(strcmp(filtre,nom)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
}
            if(strcmp(critere,"prenom")==0)
{
         if(strcmp(filtre,prenom)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
}
            if(strcmp(critere,"securite_sociale")==0)
{
         if(strcmp(filtre,ss)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
}
            if(strcmp(critere,"tache")==0)
{
         if(strcmp(filtre,tache)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
}
            if(strcmp(critere,"annee_naissance")==0)
{
         if(strcmp(filtre,annee_naissance)==0)
      {
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,ENOM,nom,EPRENOM,prenom,ESEXE,sexe,ESS,ss,ETACHE,tache,EJOUR_N,jour_naissance,EMOIS_N,mois_naissance,EANNEE_N,annee_naissance,-1);
}
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

int verifrech(char crt[])
{
    
    FILE *f=NULL;
char identifiant[20];
char nom[20];
char prenom[20];
char sexe[20];
char ss[20];
char tache[30];
char jour_naissance[20];
char mois_naissance[20];
char annee_naissance[20];
    int test;
    f=fopen("liste_des_ouvriers.txt","r");
    test=0;
    if(f!=NULL)
    {
 		while(fscanf(f,"%s %s %s %s %s %s %s %s %s  \n",identifiant,nom,prenom,sexe,ss,tache,jour_naissance,mois_naissance,annee_naissance)!=EOF)
       {
         if(strcmp(identifiant,crt)==0)
        {
          test=1;
          break;
        }
        if(strcmp(nom,crt)==0)
        {
          test=1;
          break;
        }
        if(strcmp(prenom,crt)==0)
        {
          test=1;
          break;
        }
        if(strcmp(ss,crt)==0)
        {
          test=1;
          break;
        }
       if(strcmp(tache,crt)==0)
        {
          test=1;
          break;
        }
       if(strcmp(annee_naissance,crt)==0)
        {
          test=1;
          break;
        }
       }
     fclose(f);
     }
return(test);
}






