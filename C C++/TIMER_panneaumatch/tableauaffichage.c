#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void tempsmort() {
    int minutes = 0, secondes =10;
    int a;

    while (a!=3) {
        printf("%02d:%02d\n", minutes, secondes);
        fflush(stdout); 

        
        sleep(1);


        secondes--;

    
       if (minutes == 0 && secondes == 0){
            printf("Fin du temps-mort\n");
            a=3;
        }
        else 
            if (secondes == 0) {
                secondes = 0;
                secondes = 59;
                minutes--;
            }
        
       

    }
}




int main() {
    int nb1,nb2,tm1,tm2;
    int i,a,b,pena1;


    nb1=0;
    nb2=0;
    tm1=3;
    tm2=3;

    while (1){
       
        printf("\nEQUIPE 1\n");
        printf("Points : %d\n",nb1);
        printf("Temps mort restant : %d\n",tm1);

        printf("\nEQUIPE 2\n");
        printf("Points : %d\n",nb2);
        printf("Temps mort restant : %d\n",tm2);


        printf("\n1. Modifier points\n");
        printf("2. Modifier temps morts\n");
        printf("3. Finir le match\n");
        printf("\nQue voulez faire ? :\n");
        scanf("%d",&i);

        switch(i){
            case 1: 
                printf("\n1. Modifier equipe 1 ou 2 ?\n");
                scanf("%d",&a);
                
                switch (a)
                {
                case 1:
                    nb1=nb1+1;
                    break;
                case 2:
                    nb2=nb2+1;
                    break;
                default:
                    printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 2.\n");
                    break;
                }
            break;
            case 2:
                printf("\nQu'elle equipe utilise un temps mort ?\n");
                scanf("%d",&b);

                switch (b)
                {
                case 1:
                    tempsmort();
                    tm1=tm1-1;
                    break;
                
                case 2:
                    tempsmort();
                    tm2=tm2-1;
                default:
                    printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 2.\n");
                    break;
                }   
            break;
           
            case 3:
                printf("\nFIN DU MATCH\n");
                if (nb1>nb2) 
                    printf("L'Equipe 1 a gagner le match\n");
                    if (nb2>nb1)
                        printf("L'Equipe 2 a gagner le match\n");
                    if (nb2==nb1)
                        printf("Match nul mdr force à vous\n");
        	    
                exit(0);

            default:
				printf("\nChoix invalide. Veuillez entrer un nombre entre 1 et 3.\n");
				break;

    }
}
return 0;
}