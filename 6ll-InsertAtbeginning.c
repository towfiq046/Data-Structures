// linked-list: insert a node at the beginning.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// second way of modifying the head in main. with pointer.
void insert(struct node** head, int inputFromUser) {       // receiving pointer to pointer.

    struct node* temp = (struct node*)malloc(sizeof(struct node));
    (*temp).data = inputFromUser;

    // to get head from main, dereferencing is needed. pointer to head.
    temp->next = *head;
    *head = temp;
}

void print(struct node* head) {

    // no need for temp. since head is now local.
    printf("list is: ");

    while(head != NULL) {       // traversing from the head node, since temp has the head address.

        printf(" %d", head->data);
        head = head->next;    // keep going to the next node.
    }
    printf("\n");
}

int main() {

    struct node* head = NULL;        // empty list.
    printf("How many elements? ");

    int n, i, inputFromUser;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter number: ");
        scanf("%d", &inputFromUser);

        insert(&head, inputFromUser);     // passing the variable head by reference(&).
        print(head);
    }
}

