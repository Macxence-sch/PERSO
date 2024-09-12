#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int a,b,c;
    int choix,choixx,atrouv,points;
    
    points = 0;

    while (b!=1){
        printf("1 - On joue ?\n");
        printf("2 - On sort ?\n");
        printf("Points: %d\n",points);
        scanf("%d",&choixx);

        switch (choixx){
        
        case (1):
            
            printf("\nSalut jeune Padawan, essaie de trouver le nombre !\n");
            
            c=3;
            while (c==3){
                printf("Jusqu'à combien veux-tu jouer ?\n");
                scanf("%d",&a);

                if (a<=0){
                    printf("Non, pas possible, le choix doit être au-dessus de 0, non compris !\n");
                }
                else{
                    c=0;
                }   
            }
            
            atrouv = rand() % a;
            printf("\nC'est parti alors. On joue entre 0 et %d\n",a);
            
            b=0;
            while (b != 2){
                printf("\nTon choix : \n");
                scanf("%d",&choix);
                
                if (choix < 0 || choix > a ){
                    printf("J'ai dit entre 0 et %d poto !!\n",a);
                }
                
                if (choix == atrouv){
                    printf("GG tu es trop chaud\n");
                    b=2;
                    points=points+1;
                }

                if (choix < atrouv){
                    printf("Au dessus\n");
                
                }

                if (choix > atrouv){
                    printf("En dessous\n"); 
                }   
            }
            break;
        case (2):
            b=1;
            break;
        default:
            printf("Le choix n'est pas bon");
            break;

        }
    }
    printf("Fin du jeux, tu as eu %d points, gg à bientôt",points);
}
