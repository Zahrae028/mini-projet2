#include <stdio.h>

    typedef struct
    {
        
        char ID[10];
        char nom[50];
        char prenom[50];
        float notes[4];
        float moyenne ;

    }Etudiant;

    Etudiant etudiant[30] ;
    int count = 0;
    int c;
    int choice;

void ajouterEtudiant(){
    if (count >=30)
    {
        printf("Impossible d'ajouter un nouvel etudiant. La classe est deja complete (30 etudiants).\n");
    }
    else{

    printf(">1) Ajouter etudiant\n");

    printf("CNE: ");
    scanf("%s",etudiant[count].ID);

    printf("Nom :");
    scanf("%s",etudiant[count].nom);

    printf("Prenom :");
    scanf("%s",etudiant[count].prenom);

    count++;
    }
}

void sasirNotes(){
    do
    {

    
    printf("Choisissez quel etudiant :");
    scanf("%d",&c);

    
    if (c>count || c<=0)
    {
        printf("Entree invalide. Veuillez reessayer.\n");
    }
    else{
    
    for (int i = 0; i < 4; i++)
        {
        do
        {

        printf("Note %d =",i+1);
        scanf("%f",&etudiant[c-1].notes[i]);

        if (etudiant[c-1].notes[i]<0 || etudiant[c-1].notes[i]>20)
        {
            printf("Erreur : la note doit etre comprise entre 0 et 20.\n");
        }
        
        } while (etudiant[c-1].notes[i]<0 || etudiant[c-1].notes[i]>20);
        }
    }
    } while (c>count || c<=0);
    
}


void calculerMoyenneEtudiant(){
    int n=c-1;

    etudiant[n].moyenne = 0;
    
    for (int i = 0; i < 4; i++)
    {
        etudiant[n].moyenne = etudiant[n].moyenne + etudiant[n].notes[i] /4; 
    }

}


void afficherEtudiants(){
    for (int i = 0; i < count; i++)
    {
        printf("etudiant %d :\n",i+1);
        printf("%s | %s | %s | [%.2f , %.2f , %.2f , %.2f] | %.2f \n",etudiant[i].ID ,etudiant[i].nom ,etudiant[i].prenom , etudiant[i].notes[0], etudiant[i].notes[1],etudiant[i].notes[2], etudiant[i].notes[3], etudiant[i].moyenne);
    }
    

}


void afficherBulletin(){
    int nombre ;
    do
    {
    
    printf("Entrez le numero de l'etudiant : ");
    scanf("%d",&nombre);
    if (nombre>count || nombre <=0)
    {
        printf("Entree invalide. Veuillez reessayer.");
    }
    
    else {
    int nu = nombre -1;
    
        printf("etudiant %d :\n",nombre);
        printf("%s | %s | %s | [%.2f , %.2f , %.2f , %.2f] | %.2f \n",etudiant[nu].ID ,etudiant[nu].nom ,etudiant[nu].prenom , etudiant[nu].notes[0], etudiant[nu].notes[1],etudiant[nu].notes[2], etudiant[nu].notes[3], etudiant[nu].moyenne);
    }
    } while (nombre>count || nombre <=0);
    
}


void calculerMoyenneGenerale(){
    float moyenne_general=0;
    for (int i = 0; i < count; i++)
    {
        moyenne_general= moyenne_general + (etudiant[i].moyenne/count);
    }
    
    printf("Moyenne general de la classe = %.2f",moyenne_general);

}