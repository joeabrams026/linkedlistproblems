#include <stdio.h>

struct node {
    int data;
    struct node* next;
};

int Length (struct node* n) {
    int ctr = 0;
    while (n != NULL) {
        ctr++;
        n = n->next;
    }
    
    return ctr;
}

void Push(struct node** headRef, int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node)); 
    newNode->next =  (*headRef);
    newNode->data = data;
    (*headRef) = newNode; 
}

struct node* BuildOneTwoThree() {
    struct node* head = NULL; // Start with the empty list
    Push(&head, 3); // Use Push() to add all the data
    Push(&head, 2);
    Push(&head, 1);
    return(head);
}

/**
 * 1. Count
 **/
int Count (struct node *head, int val) {
    int ctr = 0;
    while (head != NULL) {
        if (head->data == val) {
            ctr++;
        }
        head = head->next;
    }
    
    return ctr;
}

/**
 * 2. GetNth
 **/
int GetNth (struct node *head, int nth) {
    
    while (nth >= 0) {
        if (nth == 0) {
            return head->data;
        }
        
        head = head->next;
        nth--;
    }
    
    // assert(0);
}

/**
 * 3. GetNth
 **/
void DeleteList (struct node **headRef) {
    struct node *head = *headRef;
    
    while (head != NULL) {
        struct node *last = head;
        head = head->next;
        
        free(last);
    }
    
    *headRef = NULL;
}


main() {
    struct node* head = BuildOneTwoThree();
    
    printf("1: Count\n");
    printf("\tCount of '2' in OneTwoThree: %d\n", Count(BuildOneTwoThree(),2));
    printf("\tCount of '4' in OneTwoThree: %d\n", Count(BuildOneTwoThree(),4));
    
    printf("2: GetNth\n");
    printf("\tGetNth of  of '2' in OneTwoThree: %d\n", GetNth(BuildOneTwoThree(),2));
    
    printf("3: Delete List\n");
    struct node* toDelete = BuildOneTwoThree();
    DeleteList(&toDelete);
    printf("\tdeleted list");
    
    return 0;
}

