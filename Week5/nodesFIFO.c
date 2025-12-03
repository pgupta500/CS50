#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}node;

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
        n->next = NULL; // Must set next to NULL for the new tail node

        // // If list is empty
        if (list == NULL)
        {
            list = n;
        }
        // // If list has numbers already
        else
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // // If at end of list
                if (ptr->next == NULL)
                {
                    ptr->next = n;
                    break;
                }
            }
        }


        printf("Inserted %d at the end.\n", n->number);
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