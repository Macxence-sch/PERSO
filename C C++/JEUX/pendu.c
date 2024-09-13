#include <stdlib.h>
#include <stdio.h>


int main(){
    int points,b,choix;

    char tab[] = {'m', 'a', 'c', 'x', 'e','n', 'c', 'e'};
    char tab2[500];
    int nb;
    int nberreur;
    int trouve;  
    char lettre;  
    int test,test2;

    points=0;
    
    nb=8;
    b=0;
    while (b!=1){
        printf("\n1 - On fait un pendu ?\n");
        printf("2 - Fin de jeux ?\n");
        printf("3 - Gestion Mot \n"); //a faire avec fichier
        printf("points : %d\n",points);
        scanf("%d",&choix);

        switch (choix)
        {
        case (1):
            nberreur = 0;

            for (int i=0; i<nb; i++){
                tab2[i] = '_';
            }
            
            printf("\nOn commence : Le mot fait %d lettres \n",nb);

            trouve=0;
            while (nberreur <= 10 && trouve != 1){

                for (int i=0; i<nb; i++){
                    printf(" %c ",tab2[i]);
                }                                             

                printf("\nDonne une lettre : \n");
                scanf(" %c",&lettre);

                for (int i=0; i<nb; i++){
                    if (tab[i]==lettre){
                        printf("\nUne lettre minimum trouvée \n");
                        tab2[i]=tab[i];

                    }
                }      

                test=0;
                for (int i=0; i<nb; i++){
                    if (tab[i]!=lettre){
                        test = test +1;
                    }
                }

                test2=0;
                for (int i=0; i<nb; i++){
                    if (tab2[i]==tab[i]){
                        test2=test2+1;
                    }   
                }

                if (test==nb){
                    printf("\nLa lettre ne fait pas partie du mot :(\n");
                    nberreur=nberreur+1;
                }

                if (test2==nb){
                    printf("Braaavooo tu as trouvé le mot !!!\n");
                    trouve=1;
                }


                if (trouve!=1){
                    printf("Nombre d'erreur (attention pas plus de 10) : %d\n",nberreur);
                }
            }
            
            printf("Le mot etait : \n");
            for (int i=0; i<nb; i++){
                    printf(" %c ",tab2[i]);
            }

            if (trouve == 1){
                points=points+1;
            }    
              
            break; 
        case (2):
            b=1;
            break;
        case (3):

            while (b!=2){
                printf("1 - Ajouter un mot\n"); 
                printf("2 - Supprimer un mot\n"); 
                printf("3 - Voir les mots\n"); 
                printf("4 - Retour\n"); 
                scanf("%d",&choix);

                switch (choix){
                    case (1):
                        
                        printf("\n Ton mot fait combien de lettre ?\n");
                        scanf(" %d",&nb);
                        for (int i = 0; i< nb;i++){
                            printf("%d er/eme lettres : \n",i+1);
                            scanf(" %c",&tab[i]);
                        }
                        break;
                    case (2):

                        break;

                    case (3):

                        break;
                    case (4):
                        b=2;
                        break;
                    default:
                        printf("Tu t'es trompé dans les numéros !\n");
                        break;
                }}
            break;
        default:
            printf("Tu t'es trompé de numéro !\n");
            break;
        }
    }

}