#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int n;
    struct node *next;
    struct node *prec;
} node;

typedef struct {
    node *tete;
    int taille;
} Liste;

Liste* insert_liste(int size);
node* create_list(int size);
node* create_node(void);
node* rotate_right(node *head, int k);
node* rotate_left(node *head, int k);
void show_list(Liste *head, int size);

int main() {
    int x = 1;
    int k;
    int choice;
    int liste_size;
    Liste *head = NULL;
    
    do {
        printf("1-To manipulate the Liste\n");
        printf("2-Create Liste\n");
        printf("3-To exit\n");
        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);
        printf("\n//////////////////////////////////////////\n");
        
        if (choice == 1) {
            if (head == NULL) {
                printf("No list created yet. Please create a list first.\n");
            } else {
                printf("Enter number of rotations (positive for right, negative for left): ");
                scanf("%d", &k);
                if (k > 0) {
                    head->tete = rotate_right(head->tete, k);
                } else if (k < 0) {
                    head->tete = rotate_left(head->tete, -k);
                }
                show_list(head, head->taille);
            }
        } else if (choice == 2) {
            printf("Enter List Size: ");
            scanf("%d", &liste_size);
            head = insert_liste(liste_size);
            show_list(head, head->taille);
        } else if (choice == 3) {
            printf("Quitting...\n");
            x = 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
        
    } while (x == 1);
    
    return 0;
}

node* rotate_right(node *head, int k) {
    if (head == NULL || k == 0) return head;

    // Find the size of the list
    int size = 1;
    node *tail = head;
    while (tail->next != head) {
        tail = tail->next;
        size++;
    }

    // Normalize k to be within the bounds of the list size
    k = k % size;
    if (k == 0) return head;

    // Move the head pointer by k steps
    for (int i = 0; i < size - k; i++) {
        head = head->next;
    }

    return head;
}

node* rotate_left(node *head, int k) {
    if (head == NULL || k == 0) return head;

    // Find the size of the list
    int size = 1;
    node *tail = head;
    while (tail->next != head) {
        tail = tail->next;
        size++;
    }

    // Normalize k to be within the bounds of the list size
    k = k % size;
    if (k == 0) return head;

    // Move the head pointer by k steps
    for (int i = 0; i < k; i++) {
        head = head->next;
    }

    return head;
}

node* create_node(void) {
    node *p = (node*)malloc(sizeof(node));
    if (p == NULL) {
        printf("Memory Allocation Failed !!!\n");
        return NULL;
    } else {
        printf("Enter Node Value: ");
        scanf("%d", &p->n);
        p->next = p->prec = NULL;
    }
    return p;
}

node* create_list(int size) {
    node *head = NULL;
    node *tail = NULL;
    for (int i = 0; i < size; i++) {
        node *p = create_node();
        if (p == NULL) break;
        if (head == NULL) {
            head = p;
            tail = p;
            p->next = p->prec = p;
        } else {
            tail->next = p;
            p->prec = tail;
            p->next = head;
            head->prec = p;
            tail = p;
        }
    }
    return head;
}

Liste* insert_liste(int size) {
    Liste *L = (Liste*)malloc(sizeof(Liste));
    if (L == NULL) {
        printf("Memory Allocation Failed !!!\n");
        return NULL;
    }
    L->taille = size;
    L->tete = create_list(size);
    return L;
}

void show_list(Liste *head, int size) {
    if (head == NULL || head->tete == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *p = head->tete;
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            printf("%d", p->n);
        } else {
            printf("->%d", p->n);
        }
        p = p->next;
    }
    printf("\n");
}
