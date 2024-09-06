#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nom[90];
    char numero[90];
    char email[90];
} contact;

int main()
{
    contact cont [90];

    char nommodifie[50];
    char nomsupprime[80];
    int supp=0;
    char nomcherche[90];
    int count=0;
    int nombre;
    int j;
    do
    {
        printf ("\n____________________ menu____________________\n");
        printf ("1. Ajouter un Contact.\n");
        printf ("2. Modifier un Contact.\n");
        printf ("3. Supprimer un Contact.\n");
        printf ("4. Afficher Tous les Contacts.\n");
        printf ("5. Rechercher un Contact.\n");
        printf("0-pour quitter le programme : \n");
        printf ("choisir parmi les choix : ");
        scanf ("%d",&nombre);
        switch (nombre)
        {
        case 0 :
            printf("le programme est arrete .");
            break;

        case 1 :
            printf ("vous avez choisissez l'ajouter un Contact.\n");
            printf("ajouter le nom :");
            scanf ("%s",cont[count].nom);
            printf("ajouter le numero :");
            scanf ("%s",cont[count].numero);
            printf("ajouter le email :");
            scanf ("%s",cont[count].email);
            count++;
            break;

        case 2 :
            printf ("vous avez choisissez de modifier un contact : \n");
            printf(" veuillez entrer le nom de comtact :\n");
            scanf ("%s",nommodifie);
            int found = 0;
            int i;
            for (i=0; i<count; i++)
            {
                if (strcmp(cont[i].nom,nommodifie)==0)
                {
                    found++;
                    printf("entrer la nouvelle numero :\n");
                    scanf("%s",cont[i].numero);
                    printf("entrer la nouvelle adresse e-mail :\n");
                    scanf("%s",cont[i].email);
                    break;
                }
            }
            if (found ==0)
                printf("le nom entrer n'existe pas dans votre contact :\n");
            break;
        case 3 :
            printf ("vous avez choisissez de supprimer un contact : \n");
            printf(" veuillez entrer le nom de contact :\n");
            scanf("%s",nomsupprime);
            for (i=0; i<count; i++)
            {
                if (strcmp(cont[i].nom,nomsupprime)==0)
                {
                    supp++;
               for (j=i;j<count;j++){
                cont[j]=cont[j+1];

               }
             printf("le contact a ete supprimer avec success !\n");
             count--;
             break;
                }
            }



            if (supp==1)
                printf("le contact est introuvable !\n");
            break;

        case 4 :
            printf ("vous avez choisissez de  afficher tous les contacts: \n");
            for (i=0; i<count; i++)
            {
                printf("## le nom est :%s   le numero est : %s  l'email est %s \n",cont[i].nom,cont[i].numero,cont[i].email);
            }
            break;

        case 5 :
            printf("vous avez choisissez rechercher un contact");
            printf ("veuillez entrer le nom cherche .");
            scanf("%s",nomcherche);
            for (i=0; i<count; i++)
            {
                if (strcmp(cont[i].nom,nomcherche)==0)
                    printf("le nom est :%s \n  le numero est : %s \n l'email est %s \n",cont[i].nom,cont[i].numero,cont[i].email);

                else
                    printf("le nom cherche n'existe pas au contact  .") ;

            }

            break;
        }
    }
    while (nombre !=0);
    return 0;
}
