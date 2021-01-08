#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "absentisme.h"
#include <gtk/gtk.h>

enum
{
    EIDENTIFIANT,
    EJ,
    EM,
    EA,
    EABS,
    
    COLUMNS,
};


void absentisme(ouv n)
{
 FILE *f;
 f=fopen("tableau_absentisme.txt","a+");
 if(f!=NULL)
 {
   fprintf(f,"%s %d %d %d %d \n",n.identifiant,n.date_abs.jour,n.date_abs.mois,n.date_abs.annee,n.abs);
fclose(f);
}
}

void modifierabs(ouv n)
{
char id1[20];
int abs1;
    int jda;
    int mda;
    int ada;
    	

FILE *f;
FILE *f1;

f=fopen("tableau_absentisme.txt","r");
f1=fopen("modif.txt","a+");
while (fscanf(f,"%s %d %d %d %d \n",id1,&jda,&mda,&ada,&abs1)!=EOF)
{
if ((strcmp(n.identifiant,id1)==0)&&(n.date_abs.jour==jda)&&(n.date_abs.mois==mda)&&(n.date_abs.annee==ada)==0)
	fprintf(f1,"%s %d %d %d %d\n",n.identifiant,n.date_abs.jour,n.date_abs.mois,n.date_abs.annee,n.abs);

else
	fprintf(f1,"%s %d %d %d %d\n",id1,jda,mda,ada,abs1);

}
fclose(f);
fclose(f1);
remove("tableau_absentisme.txt");
rename("modif.txt","tableau_absentisme.txt");
}

void rechabs(GtkWidget *liste, char id[], char moisabs[], char anneeabs[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char abs[20];

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("abs",renderer,"text",EABS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("tableau_absentisme.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("tableau_absentisme.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",identifiant,jour,mois,annee,abs)!=EOF)
		{
   if(strcmp(identifiant,id)==0&&strcmp(mois,moisabs)==0&&strcmp(annee,anneeabs)==0)
{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,EJ,jour,EM,mois,EA,annee,EABS,abs,-1);
}
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	   }
}

}

void afficherabs(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant[20];
char jour[20];
char mois[20];
char annee[20];
char abs[20];

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);	

renderer=gtk_cell_renderer_text_new();                column=gtk_tree_view_column_new_with_attributes("abs",renderer,"text",EABS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("tableau_absentisme.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("tableau_absentisme.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",identifiant,jour,mois,annee,abs)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EIDENTIFIANT,identifiant,EJ,jour,EM,mois,EA,annee,EABS,abs,-1);

		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	   }
}

}

void supprimerabs(char idsp[])
{
FILE *f;
FILE *f1;
ouv n;
f=fopen("tableau_absentisme.txt","r");
f1=fopen("doc.txt","a+");
while (fscanf(f,"%s %d %d %d %d \n",n.identifiant,&n.date_abs.jour,&n.date_abs.mois,&n.date_abs.annee,&n.abs)!=EOF)
{
	if (strcmp(n.identifiant,idsp)!=0)	
	fprintf(f1,"%s %d %d %d %d\n",n.identifiant,n.date_abs.jour,n.date_abs.mois,n.date_abs.annee,n.abs);

}
fclose(f);
fclose(f1);
remove("tableau_absentisme.txt");
rename("doc.txt","tableau_absentisme.txt");
}

int verifdate(int j, int m, int a)
{
    
    FILE *f=NULL;
ouv n;
    int test;
    f=fopen("tableau_absentisme.txt","r");
    test=0;
    if(f!=NULL)
    {
 while (fscanf(f,"%s %d %d %d %d \n",n.identifiant,&n.date_abs.jour,&n.date_abs.mois,&n.date_abs.annee,&n.abs)!=EOF)
       {
         if((n.date_abs.jour==j)&&(n.date_abs.mois==m)&&(n.date_abs.annee==a))
        {
          test=1;
          break;
        }

       }
     fclose(f);
     }
return(test);
}


