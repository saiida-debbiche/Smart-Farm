#include <stdio.h>
<<<<<<< HEAD
#include <stdlib.h>
#include "fonction.h"

=======
#include "fonction.h"
>>>>>>> 5359ee06d6e5688b717efc84ea85d4949b422bba
int main()
{
int a;
int b;
printf("\nSaisie du Premier Nombre: ");
scanf("%d",&a);
do{
printf("\nsaisie du Second Nombre: ");
scanf("%d",&b);
}while(b==0);
printf("\n%d+%d=%d",a,b,sommer(a,b));
printf("\n%d-%d=%d",a,b,soustraire(a,b));
printf("\n%d/%d=%f",a,b,diviser(a,b));
return(0);
}
