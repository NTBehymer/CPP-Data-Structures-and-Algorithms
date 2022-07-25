#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node 
{
    int data;
    struct Node* next; // The "*" in the variable declares a "pointer to" the variable
};

Node* Insert(Node* head, int x)
{
    struct Node* temp  = (Node*) malloc (sizeof(struct Node)); // malloc allocates a block of memory, returning a pointer to the beginning of the block
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next = head;
    head = temp;
    return head;
}

void Print(Node* head)
{
    while (head != NULL)
    {
        printf(" <- %d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
    Node* head = NULL; //initalize empty list
    int n, x;
    printf("How large is the list?\n");
    scanf("%d", &n);  // The "&" in the variable declares the "address of" the variable
    for(int i = 0; i<n; i++){
        printf("Enter the next number in the list: \n");
        scanf("%d", &x);
        head = Insert(head, x);
        Print(head);
    }
}