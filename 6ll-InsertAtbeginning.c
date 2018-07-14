// linked-list: insert a node at the beginning.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

// first way of modifying the head in main.
struct node* insert(struct node* head, int inputFromUser) {       // pass the pointer to the node
                // this head is just a copy from main.
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    (*temp).data = inputFromUser;
    temp->next = head;
    head = temp;

    return head;        // returning head.
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

        head = insert(head, inputFromUser);     // collecting the return in the head again. so head is now modified.
        print(head);
    }
}

