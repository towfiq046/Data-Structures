// linked-list: insert a node at the beginning.

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head;   // global variable. // head is an indication of the first node.

void insert(int inputFromUser) {

    // creating a node.
    struct node* temp = (struct node*)malloc(sizeof(struct node));    // variable temp, pointer to node. // storing the address of node in temp.
    // dereferencing (*temp) for accessing the fields (in this case data part) of the node.

    (*temp).data = inputFromUser;   // or-- temp->data = inputFromUser;
    // dereferencing the pointer variable (temp) to modify the node.
    // inputFromUser is in data part with the help of (dereferencing) *temp.

    // temp->next = NULL;    // nothing in next. // only getting used when list is empty. obviously head is already null.

    //if(head != NULL)        // no need for the condition.

    temp->next = head;      // so simply write next is head. so list is empty.

    head = temp;    // head has the address of the 'first' node.
}

void print() {
    struct node* temp = head;   // this global variable (head) has the address of the head node.
                                 // head is not for modification. if so we will lose the address of head.
    printf("list is: ");

    while(temp != NULL) {       // traversing from the head node, since temp has the head address.

        printf(" %d", temp->data);
        temp = temp->next;    // keep going to the next node.
    }
    printf("\n");
}

int main() {

    head = NULL;        // empty list.
    printf("How many elements? ");

    int n, i, inputFromUser;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nEnter number: ");
        scanf("%d", &inputFromUser);

        insert(inputFromUser);
        print();
    }
}

