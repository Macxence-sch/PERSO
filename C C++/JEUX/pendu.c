#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX_MOT 1000
#define FILENAME_Mot "mot.dat" 

struct mot{
    int id;
    int nb;
    char mot[50];
};

struct datamot {
    int points;
    int count;
    struct mot mots[MAX_MOT];
};

void initialisation (struct datamot *motDB);
void ajoutermot (struct datamot *motDB);
void voirmot (struct datamot *motDB);
void jeux (struct datamot *motDB);

int main(){
    srand(time(NULL)); 
    struct datamot motDB;

    int points,b,choix;
    
    FILE *file;
    file = fopen(FILENAME_Mot, "r+");
    fread(&motDB.points, sizeof(int), 1, file);
    motDB.points= 0;
    fseek(file, 0, SEEK_SET);
    fwrite(&motDB.points, sizeof(int), 1, file);
    fclose(file);
    
    
    b=0;
    while (b!=1){

        FILE *file;
        file = fopen(FILENAME_Mot, "r");
        fread(&motDB.points, sizeof(int), 1, file);
        points=motDB.points;
        fclose(file);

        printf("\n1 - On fait un pendu ?\n");
        printf("2 - Fin de jeux ?\n");
        printf("3 - Gestion Mot \n"); //a faire avec fichier
        printf("4 - Quitter \n");
        printf("points : %d\n",points);
        scanf("%d",&choix);

        switch (choix)
        {
        case (1):
            jeux (&motDB);
            break; 
        case (2):
            b=1;
            break;
        case (3):

            while (b!=2){
                printf("\n1 - Ajouter un mot\n"); 
                printf("2 - Supprimer un mot\n"); 
                printf("3 - Voir les mots\n"); 
                printf("4 - Retour\n"); 
                scanf("%d",&choix);

                switch (choix){
                    case (1):                       
                        ajoutermot (&motDB);
                        break;
                    case (2):

                        break;
                    case (3):  
                        voirmot (&motDB);
                        break;
                    case (4):
                        b=2;
                        break;
                    default:
                        printf("Tu t'es trompé dans les numéros !\n");
                        break;
                }}
            break;
        case (4):
            b=1;
            break;
        case (5):
            initialisation (&motDB);
            break;
        default:
            printf("Tu t'es trompé de numéro !\n");
            break;
        }
    }

}


void initialisation (struct datamot *motDB){
    FILE *file;
    
    file = fopen(FILENAME_Mot, "wb");
    motDB->count = 0;
    motDB->points = 0;

    fwrite(&motDB->count, sizeof(int), 1, file);
    fwrite(&motDB->points, sizeof(int), 1, file);

    fclose(file);
    printf("fait");
}



void ajoutermot (struct datamot *motDB){
    FILE *file;
    int iddd;
    file = fopen(FILENAME_Mot, "r+");

    if (file == NULL) {
        	printf("Erreur lors de l'ouverture du fichier.\n");
        	fclose(file);
        	return;
    }

    fread(&motDB->count, sizeof(int), 1, file);
    motDB->count = motDB->count + 1;
    fwrite(&motDB->count, sizeof(int), 1, file);

    iddd = motDB->count;

    motDB->mots[iddd].id = iddd;

    printf("\nDonne ton mot : \n");
    scanf(" %s",&motDB->mots[iddd].mot);
    
    
    int length = strlen(motDB->mots[iddd].mot);
    motDB->mots[iddd].nb = length;
    
    printf("\nParfait voici le recap : \n");
    printf("\nID du mot : %d\n",motDB->mots[iddd].id);
    printf("Le mot : %s\n",motDB->mots[iddd].mot);
    printf("Nombre de lettre : %d\n",motDB->mots[iddd].nb);
    
    fseek(file, 0, SEEK_SET);
    fwrite(&motDB->count, sizeof(int), 1, file);    
    fseek(file, sizeof(int) + iddd * sizeof(struct mot), SEEK_SET);
    fwrite(&motDB->mots[iddd], sizeof(struct mot), 1, file);
    fclose(file);
    
}

void voirmot (struct datamot *motDB){
    FILE *file;
    file = fopen(FILENAME_Mot, "r");

    int iddd;

    if (file == NULL) {
        	printf("Erreur lors de l'ouverture du fichier.\n");
        	fclose(file);
        	return;
    }

    fread(&motDB->count, sizeof(int), 1, file);
    iddd = motDB->count;

    //iddd = iddd  + 1;
    
    fseek(file, sizeof(int), SEEK_SET);

    for (int i=0; i <= iddd; i++ ){
        fread(&motDB->mots[iddd + 1], sizeof(struct mot), 1, file);
       
        printf("\nID : %d",motDB->mots[iddd + 1].id);
        
        printf(" Mot : %s",motDB->mots[iddd + 1].mot);
        
        printf(" Nombre de lettre : %d",motDB->mots[iddd + 1].nb);
        printf(" \n");
    }

    fclose(file);

}


void jeux (struct datamot *motDB){
    int id,nberreur,nb,trouve;
    int test,test2;
    char lettre;
    char tab2[50];

    FILE *file;
    file = fopen(FILENAME_Mot, "r+");

    if (file == NULL) {
        	printf("Erreur lors de l'ouverture du fichier.\n");
        	fclose(file);
        	return;
    }

    fread(&motDB->count, sizeof(int), 1, file);


    id = rand() % motDB->count;
    if (id == 0) {
        id = motDB->count;
    }

    fread(&motDB->mots[id + 1], sizeof(struct mot), 1, file);

    nberreur = 0;
    nb = motDB->mots[id].nb;

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
            if (motDB->mots[id].mot[i]==lettre){
                printf("\nUne lettre minimum trouvée \n");
                tab2[i]=motDB->mots[id].mot[i];

            }
        }      

        test=0;
        for (int i=0; i<nb; i++){
            if (motDB->mots[id].mot[i]!=lettre){
                test = test +1;
            }
        }

        test2=0;
        for (int i=0; i<nb; i++){
            if (tab2[i]==motDB->mots[id].mot[i]){
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
        fread(&motDB->points, sizeof(int), 1, file);
        motDB->points=motDB->points+1;
        fseek(file, 0, SEEK_SET);
        fwrite(&motDB->points, sizeof(int), 1, file);
    }

    fclose(file);
}