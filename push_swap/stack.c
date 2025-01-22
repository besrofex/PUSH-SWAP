#include <stdio.h>
#include <stdlib.h>

#define TAILLE_MAX 100 // Taille maximale de la pile

typedef struct {
    int elements[TAILLE_MAX];
    int sommet; // Index du sommet de la pile
} Pile;

// Initialiser une pile vide
void initialiser_pile(Pile *p) {
    p->sommet = -1;
}


// Vérifier si la pile est vide
int est_vide(Pile *p) {
    return p->sommet == -1;
}

// Vérifier si la pile est pleine
int est_pleine(Pile *p) {
    return p->sommet == TAILLE_MAX - 1;
}

// Empiler un élément
void empiler(Pile *p, int valeur) {
    if (est_pleine(p)) {
        printf("Erreur : Pile pleine\n");
        return;
    }
    p->elements[++(p->sommet)] = valeur;
}

// Dépiler un élément
int depiler(Pile *p) {
    if (est_vide(p)) {
        printf("Erreur : Pile vide\n");
        exit(EXIT_FAILURE);
    }
    return p->elements[(p->sommet)--];
}

// Consulter l'élément au sommet
int sommet(Pile *p) {
    if (est_vide(p)) {
        printf("Erreur : Pile vide\n");
        exit(EXIT_FAILURE);
    }
    return p->elements[p->sommet];
}

// Exemple d'utilisation
int main() {
    Pile p;
    initialiser_pile(&p);

    empiler(&p, 10);
    empiler(&p, 20);
    empiler(&p, 30);

    printf("Sommet : %d\n", sommet(&p)); // Affiche 30

    printf("Dépiler : %d\n", depiler(&p)); // Retire et affiche 30
    printf("Dépiler : %d\n", depiler(&p)); // Retire et affiche 20
    // printf("Dépiler : %d\n", depiler(&p)); // Retire et affiche 10

    if (est_vide(&p)) {
        printf("La pile est vide.\n");
    }

    return 0;
}
