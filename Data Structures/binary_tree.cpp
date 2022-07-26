#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* GetNewNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data; // The arrow (->) in C++ lets you access the data of a pointer. Alternate syntax for this could be (*newNode).data
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* Insert(Node* root, int n) // You can use "**" to mean "pointer to pointer"
{
    if (root == NULL)
    {
        root = GetNewNode(n);
    }
    else if (n <= root->data)
    {
       root->left = Insert(root->left, n);
    }
    else
    {
        root->right = Insert(root->right, n);
    }
    return root;
}

bool Search(Node* root, int n)
{
    if (root == NULL) return false;
    else if (root->data == n) return true;
    else if (n <= root->data) return Search(root->left, n);
    else return Search(root->right, n);
}

int main()
{
    Node* root = NULL;
    root = Insert(root, 15); root = Insert(root, 17); root = Insert(root, 19); root = Insert(root, 11);
    root = Insert(root, 12); root = Insert(root, 9); root = Insert(root, 20); root = Insert(root, 1);
    int i;
    cout << "Enter number you would like to search for:\n";
    cin>>i;
    if (Search(root, i)) cout<<"Found\n";
    else cout<<"Not Found\n";
}