#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nom[90];
    char numero[90];
    char email[90];
} contact;
contact temp_tri;
int count;
contact cont [90];

int main()
{
    contact cont [90];
    int nbr ;
    int valid_supprime;
    char nommodifie[50];
    char nomsupprime[80];
    int supp=0;
    char choix ;
    int found2 =0;
    int found3 =0;
    char nomcherche[90];
    int count=0,nombre;
    int mil;
    int nbr1;
    char nomcherche1[80];
    int j;
    do
    {
        printf ("\n______________________menu_______________________\n");
        printf ("1. Ajouter un Contact.\n");
        printf ("2. Modifier un Contact.\n");
        printf ("3. Supprimer un Contact.\n");
        printf ("4. Afficher Tous les Contacts.\n");
        printf ("5. Rechercher un Contact (recherche sequentielle).\n");
        printf ("6. Rechercher un Contact (recherche dichotomique).\n");
        printf ("7. trier pa ordre alphapitique ascendant\n");
        printf ("8. trier pa ordre alphapitique descendant\n");
        printf("0-pour quitter le programme : \n");
        printf ("\n_________________________________________________\n");
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        printf ("choisir parmi les choix : \n");
        scanf ("%d",&nombre);
        switch (nombre)
        {
        case 0 :
            printf("le programme est arrete .");
            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 1 :
            printf ("veuillez entrer votre choix :\n ");
            printf (" a ==> Ajouter un nouveau contact: \n") ;
            printf (" b ==> Ajouter plusieures nouveaux contacts: \n") ;
            scanf (" %c",&choix);
            switch (choix)
            {

            case 'a':
                printf ("vous avez choisissez l'ajouter un Contact.\n");
                printf("ajouter le nom :");
                scanf ("%s",cont[count].nom);
                printf("ajouter le numero :");
                scanf ("%s",cont[count].numero);
                printf("ajouter le email :");
                scanf ("%s",cont[count].email);
                count++;
                break ;
            case 'b' :
                printf ("veuillez le nombre des contacts ");
                scanf ("%d",&nbr);
                for (int i=0; i<nbr; i++)
                {
                    printf("ajouter le nom :");
                    scanf ("%s",cont[count].nom);
                    printf("ajouter le numero :");
                    scanf ("%s",cont[count].numero);
                    printf("ajouter le email :");
                    scanf ("%s",cont[count].email);
                    count++;
                }
                break ;
            default :
                printf ("le choix est inccorect veulliez entrer 'a' ou 'b' .\n");
                break;
            }

            break;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 3 :
            printf ("vous avez choisissez de supprimer un contact : \n");
            printf(" veuillez entrer le nom de contact :\n");
            scanf("%s",nomsupprime);
            printf ("le nom entrer est %s  .\n",nomsupprime);
            printf("pour valider la suppression saisir 1 .\n");
            printf ("pour annuler la suppression saisir 2 .\n");
            scanf("%d",&valid_supprime);
                if (valid_supprime==1)
            {
                for (i=0; i<count; i++)
            {
                if (strcmp(cont[i].nom,nomsupprime)==0)
                {
               for (j=i;j<count;j++){
                cont[j]=cont[j+1];

               }
             printf("le contact a ete supprimer avec success !\n");
             count--;
             supp++;

             break;
                }
            }
            if (supp==0)
                printf("le contact est introuvable !\n");

            }
            else if(valid_supprime==2)
                printf ("la suppression est annulee\n");
            else
                printf ("veuillez choisir 1 ou 2 .\n");
            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 4 :
            printf ("vous avez choisissez de  afficher tous les contacts: \n");
            for (i=0; i<count; i++)
            {
                printf("## le nom est :%s   le numero est : %s  l'email est %s \n",cont[i].nom,cont[i].numero,cont[i].email);
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 5 :
            printf("vous avez choisissez rechercher un contact (recherche sequensielle)");
            printf ("veuillez entrer le nom cherche .");
            scanf("%s",nomcherche);
            for (i=0; i<count; i++)
            {
                if (strcmp(cont[i].nom,nomcherche)==0){
                        found3=1;
                    break;
}


            }
            if (found3==1)
                printf("le nom est :%s \n  le numero est : %s \n l'email est %s \n",cont[i].nom,cont[i].numero,cont[i].email);

            else
                    printf("le nom cherche n'existe pas au contact  .");

            break;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 6 :
            printf("vous avez choisissez rechercher un contact (recherche dichotomique) :\n");
            printf ("veuillez entrer le nom cherche .");
            scanf("%s",nomcherche1);
            int sup=count;
           int inf=0;
            for (int i=0; i<count-1; i++)
            {
                for (int j=0; j<count-1-i; j++)
                {
                    if (strcmp(cont[j].nom,cont[j+1].nom)>0)
                    {
                        temp_tri=cont[j];
                        cont[j]=cont [j+1];
                        cont [j+1]=temp_tri;
                    }
                }
            }
            while (inf<=sup)
            {

                mil = (sup+inf)/2;
                if(strcmp(cont[mil].nom,nomcherche1)==0)
                {
                    found2=1;
                    break;
                }
                else if(strcmp(cont[mil].nom,nomcherche1)<0)
                {
                    inf=mil+1;
                }
                else if(strcmp(cont[mil].nom,nomcherche1)>0)
                {
                    sup=mil-1;
                }
            }
            if (found2==1)
            {

                printf("## le nom est :%s  \n le numero est : %s \n l'email est %s \n",cont[mil].nom,cont[mil].numero,cont[mil].email);

            }
            else
                printf("le nom cherche n'existe pas au contact  .") ;
            break;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 7 :
            printf("vous avez choisissez de trier les contact par ordre alphapitique descendant :\n");

            for (int i=0; i<count-1; i++)
            {
                for (int j=0; j<count-1-i; j++)
                {
                    if (strcmp(cont[j].nom,cont[j+1].nom)>0)
                    {
                        temp_tri=cont[j];
                        cont[j]=cont [j+1];
                        cont [j+1]=temp_tri;
                    }
                }
            }
            printf("le contact a ete trier avec success !\n");
            break ;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 8 :
            printf("vous avez choisissez de trier les contact par orde alphabitique ascendant :\n");

            for (int i=0; i<count-1; i++)
            {
                for (int j=0; j<count-1-i; j++)
                {
                    if (strcmp(cont[j].nom,cont[j+1].nom)<0)
                    {
                        temp_tri=cont[j];
                        cont[j]=cont [j+1];
                        cont [j+1]=temp_tri;
                    }
                }
            }
            printf("le contact a ete trier avec success !\n");
            break ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        default :
    printf (" votre choix n'existe pas . choisir parmi les choix : \n");
        }
        system ("pause");
        system ("cls");
    }
    while (nombre !=0);
    return 0;
}
