#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *head) {
    t_stack *current = head;
    
    if (current == NULL) {
        printf("La pile est vide.\n");
        return;
    }

    printf("Pile : ");
    while (current != NULL) {
        printf("%d ", current->value); // Affiche la valeur de l'élément courant
        current = current->next; // Passe à l'élément suivant
    }
    printf("\n");
}
