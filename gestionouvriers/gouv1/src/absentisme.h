#include <gtk/gtk.h>
typedef struct
{
   int jour;
   int mois;
   int annee;
}dates;

typedef struct
{
    char identifiant[20];
    int abs;
    dates date_abs;

    
}ouv;


void absentisme(ouv n);
void modifierabs(ouv n);
void afficherabs(GtkWidget *liste);
void rechabs(GtkWidget *liste, char id[], char moisabs[], char anneeabs[]);
void supprimerabs(char idsp[]);
int verifdate(int j, int m, int a);

