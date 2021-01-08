#include <gtk/gtk.h>
typedef struct
{
   int jour;
   int mois;
   int annee;
}date;

typedef struct
{
    char identifiant[20];
    char nom[20];
    char prenom[20];
    char sexe[20];
    date date_naissance;
    char ss[20];
    char tache[30];
    
}ouvrier;


void ajouter(ouvrier n);
void afficher(GtkWidget *liste);
void supprimer(char idsp[]);
void modifier(ouvrier n);
void chercher(GtkWidget *liste, char id[]);
int verif(char id[]);
void filtrecritere(GtkWidget *liste, char critere[], char filtre[]);
int verifrech(char crt[]);


