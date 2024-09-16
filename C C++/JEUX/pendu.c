#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>
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
void supprimer (struct datamot *motDB);

int main() {
    srand(time(NULL)); 
    struct datamot motDB;
    int  b, choix;
    
    
    FILE *file;
    file = fopen(FILENAME_Mot, "r+");
    if (file == NULL) {
        
        file = fopen(FILENAME_Mot, "w+"); 
        if (file == NULL) {
            printf("Erreur lors de la création du fichier.\n");
            return EXIT_FAILURE;  
        }
        
        motDB.points = 0;
        motDB.count = 0;
        fwrite(&motDB.points, sizeof(int), 1, file);
        fwrite(&motDB.count, sizeof(int), 1, file);
        printf("Ini Faite\n");
    } else {
        
        fread(&motDB.points, sizeof(int), 1, file);
        fread(&motDB.count, sizeof(int), 1, file);
    }
    fclose(file);

    
    b = 0;
    while (b != 1) {
        printf("\n1 - On fait un pendu ?\n");
        printf("2 - Fin de jeux ?\n");
        printf("3 - Gestion Mot\n");  // faire avec fichier mdr faut que j'essaye
        printf("4 - Quitter\n");
        printf("Points : %d\n", motDB.points);
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                jeux(&motDB);  
                break;
            case 2:
                b = 1;  
                break;
            case 3:
                
                b = 10;
                while (b != 2) {
                    printf("\n1 - Ajouter un mot\n");
                    printf("2 - Supprimer un mot\n");
                    printf("3 - Voir les mots\n");
                    printf("4 - Retour\n");
                    scanf("%d", &choix);

                    switch (choix) {
                        case 1:
                            ajoutermot(&motDB);  
                            break;
                        case 2:
                            supprimer(&motDB); 
                            break;
                        case 3:
                            voirmot(&motDB);  
                            break;
                        case 4:
                            b = 2;  
                            break;
                        default:
                            printf("Numéro invalide !\n");
                            break;
                    }
                }
                break;
            case 4:
                b = 1;  
                break;
            default:
                printf("Numéro invalide !\n");
                break;
        }
    }

    return 0;
}



void initialisation(struct datamot *motDB) {
    FILE *file;
    
    file = fopen(FILENAME_Mot, "wb");

  
    motDB->count = 0;
    motDB->points = 0;

    
    fwrite(&motDB->count, sizeof(int), 1, file);
    fwrite(&motDB->points, sizeof(int), 1, file);

    fclose(file); 
    printf("Initialisation terminée.\n");
}

void ajoutermot(struct datamot *motDB) {
    FILE *file;
    int iddd;

    file = fopen(FILENAME_Mot, "r+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;  
    }

    
    fread(&motDB->count, sizeof(int), 1, file);
    motDB->count++;

    iddd = motDB->count - 1;  
    motDB->mots[iddd].id = iddd;

    
    printf("\nDonne ton mot : \n");
    scanf("%s", motDB->mots[iddd].mot); 

    
    int length = strlen(motDB->mots[iddd].mot);
    motDB->mots[iddd].nb = length;

    
    printf("\nParfait voici le récap : \n");
    printf("ID du mot : %d\n", motDB->mots[iddd].id);
    printf("Le mot : %s\n", motDB->mots[iddd].mot);
    printf("Nombre de lettres : %d\n", motDB->mots[iddd].nb);

    
    fseek(file, 0, SEEK_SET);
    fwrite(&motDB->count, sizeof(int), 1, file); 

    fseek(file, sizeof(int) + iddd * sizeof(struct mot), SEEK_SET);
    fwrite(&motDB->mots[iddd], sizeof(struct mot), 1, file);  

    fclose(file);  
}

void voirmot(struct datamot *motDB) {
    FILE *file;
    file = fopen(FILENAME_Mot, "r");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;  
    }

    
    fread(&motDB->count, sizeof(int), 1, file);
    

    if (motDB->count == 0) {
        printf("Aucun mot enregistré.\n");
        fclose(file);
        return;
    }

    
    for (int i = 0; i < motDB->count; i++) {
        fread(&motDB->mots[i], sizeof(struct mot), 1, file);
        printf("\nID : %d", motDB->mots[i].id);
        printf(" Mot : %s", motDB->mots[i].mot);
        printf(" Nombre de lettres : %d\n", motDB->mots[i].nb);
    }

    fclose(file);  
}

void supprimer(struct datamot *motDB) {
    int idd;
    char rep;
    FILE *file;

    file = fopen(FILENAME_Mot, "r+");
    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

   
    fread(&motDB->count, sizeof(int), 1, file);

    printf("\nDonner l'ID du mot à supprimer : \n");
    scanf("%d", &idd);

    if (idd < 0 || idd >= motDB->count) {
        printf("ID invalide.\n");
        fclose(file);
        return;
    }

    printf("\nVoulez-vous vraiment supprimer le mot : %s ? (O/N)\n", motDB->mots[idd].mot);
    scanf(" %c", &rep);

    if (rep == 'O' || rep == 'o') {
        
        for (int i = idd; i < motDB->count - 1; i++) {
            motDB->mots[i] = motDB->mots[i + 1];
            motDB->mots[i].id--;  
        }
        motDB->count--;  

        
        fseek(file, 0, SEEK_SET);
        fwrite(&motDB->count, sizeof(int), 1, file);
        fwrite(motDB->mots, sizeof(struct mot), motDB->count, file);

        printf("Mot supprimé avec succès.\n");
    } else {
        printf("Mot non supprimé.\n");
    }

    fclose(file);
}

void jeux(struct datamot *motDB) {
    int id, nberreur, nb, trouve;
    char lettre;
    char tab2[50] = {0};  

    FILE *file;
    file = fopen(FILENAME_Mot, "r+");

    if (file == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;  
    }

    
    fread(&motDB->count, sizeof(int), 1, file);
    fread(&motDB->points, sizeof(int), 1, file);  

    printf("\n Il y a  : %d mots\n", motDB->count);
    
    id = rand() % motDB->count;
    if (id==0){
        id = motDB->count;
    }  

    fseek(file, sizeof(int) + id * sizeof(struct mot), SEEK_SET); 
    fread(&motDB->mots[id], sizeof(struct mot), 1, file);

    nberreur = 0;
    nb = motDB->mots[id].nb;

    for (int i = 0; i < nb; i++) {
        tab2[i] = '_';
    }

    printf("\nOn commence : Le mot fait %d lettres \n", nb);

    trouve = 0;
    while (nberreur < 10 && !trouve) {
        printf("Mot à trouver : ");
        for (int i = 0; i < nb; i++) {
            printf(" %c ", tab2[i]);
        }

        printf("\nDonne une lettre : \n");
        scanf(" %c", &lettre);

        int lettre_trouvee = 0; 
        for (int i = 0; i < nb; i++) {
            if (motDB->mots[id].mot[i] == lettre) {
                tab2[i] = lettre;
                lettre_trouvee = 1;  
            }
        }

        if (!lettre_trouvee) {
            printf("\nLa lettre ne fait pas partie du mot :(\n");
            nberreur++;
        }

        trouve = 1; 
        for (int i = 0; i < nb; i++) {
            if (tab2[i] == '_') {
                trouve = 0;  
                break;
            }
        }

        if (!trouve) {
            printf("\nErreur : %d/10\n", nberreur);
        }
    }

    if (trouve) {
        printf("Bravo ! Tu as trouvé le mot !!!\n");
        printf("Mot : %s\n", motDB->mots[id].mot);

        
        motDB->points++;

        
        fseek(file, sizeof(int), SEEK_SET);  
        fwrite(&motDB->points, sizeof(int), 1, file);

    } else {
        printf("Désolé, tu as fait trop d'erreurs. Le mot était : %s\n", motDB->mots[id].mot);
    }

    fclose(file);
}
