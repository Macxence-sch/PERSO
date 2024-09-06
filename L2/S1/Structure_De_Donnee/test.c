#include <stdlib.h>


void f(void){
    int t[1000];
}


int main(void){
    int *t =malloc(sizeof(int)*1000);
    if(t != NULL){
        printf("Coucou");
        //Gestion de l'erreur 
    }
    free(t);
}