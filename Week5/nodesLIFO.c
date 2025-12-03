#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;
// Function to create and populate a linked list with three nodes

int main(void){

    node *list = NULL;
    // This line creates an empty linked list by initializing the head pointer to NULL.
    

    for(int i = 0; i<3;i++){
        // This starts a loop that will run three times to create three nodes.
        node *n = malloc(sizeof(node));
        // This allocates memory for a new node and assigns it to the pointer n.
        if (n==NULL){
            return 1;
        }
        // This checked if the memory allocation was successful. If not, it returned an error.
        printf("Number: ");
        scanf("%d", &n->number);
        n->next = list;
        // This is important. It sets the next pointer of the new node to point to the current head of the list which is NULL when the loop runs for the first time, the node containing the user input from the second time and so on.
        list = n;
        // This updates the head of the list to point to the new node n, effectively adding it to the front of the list.
        printf("%d\n", list->number);
    }

    node *ptr = NULL;
    // This initializes a pointer ptr to traverse the linked list.
    ptr = list;
    while(ptr != NULL){
        // This loop continues until ptr is NULL, meaning the end of the list has been reached.
        printf("%d \n", ptr->number);
        // This prints the number stored in the current node pointed to by ptr.
        ptr = ptr->next;
        // This moves ptr to the next node in the list.
    }
    
}



