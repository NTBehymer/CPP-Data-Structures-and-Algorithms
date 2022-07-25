#include <iostream>

using namespace std;

struct Node 
{
    int data;
    struct Node* next; // The "*" in the variable declares a "pointer to" the variable
};

struct Node* head; // Global variable holding the pointer to the head of the list

void Insert(int x) // Insert data from head
{
    // struct Node* temp  = (Node*) malloc (sizeof(struct Node)); // malloc allocates a block of memory, returning a pointer to the beginning of the block. Is a C Keyword
    struct Node* temp = new Node; // Better way to write malloc in C++ is to declare a "new" variable/object
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next = head;
    head = temp;
}

void Insert(int data, int n) // Insert data in the nth position
{
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if(n==1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    Node* temp2 = head;
    for(int i =0; i<n-2;i++)
    {
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

void Print()
{
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void CreateList() // Inserts at beginning of list for each number
{
    head = NULL; //initalize empty list
    int n, x;
    printf("How large is the list?\n");
    scanf("%d", &n);  // The "&" in the variable declares the "address of" the variable
    for(int i = 0; i<n; i++){
        printf("Enter the next number in the list: \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
}

void Delete(int n)
{
    struct Node* temp = head;
    if (n==1)
    {
        head = temp->next; // Head will now point to the second node
        delete(temp); // delete temp from memory
        return;
    }

    int i;
    for (i=0;i<n-2;i++)
        temp = temp->next;
    // Temp points to the (n-1)th node
    struct Node* temp2 = temp->next;  // nth node
    temp->next = temp2->next; // (n+1)th node
    delete(temp2); // delete temp2 from memory
}

void ReverseIterative()
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void Reverse(struct Node* p)
{
    if (p->next == NULL) // Exit condition
    {
        head = p;
        return;
    }
    Reverse(p->next);
    struct Node* temp = p->next;
    temp->next = p;
    p->next = NULL;
}

void ReverseRecursively()
{
    Reverse(head);
}

int main() 
{
    CreateList();
    printf("Number to insert: \n");
    int i, n;
    scanf("%d", &i);
    printf("Position to insert: \n");
    scanf("%d", &n);
    Insert(i, n);
    Print();
    printf("Position to delete: \n");
    scanf("%d", &n);
    Delete(n);
    Print();
    printf("Reversing the list iteratively: \n");
    ReverseIterative();
    Print();
    printf("Reversing the list recursively: \n");
    ReverseIterative();
    Print();
}