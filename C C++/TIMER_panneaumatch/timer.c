#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int minutes = 0, secondes =10;

    while (1) {
        printf("%02d:%02d\n", minutes, secondes);
        fflush(stdout); 

        
        sleep(1);

        
        secondes--;

        
       if (minutes == 0 && secondes == 0){
            printf("Fin de la pénalité");
            exit(0);
        }
        else 
            if (secondes == 0) {
                secondes = 0;
                secondes = 59;
                minutes--;
            }
        
       

    }

    return 0;
}