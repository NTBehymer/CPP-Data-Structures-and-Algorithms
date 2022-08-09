#include <iostream>
#include <queue>
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

Node* FindMin(Node* root){
    if (root->left == NULL) return root;
    else return FindMin(root->left);
}

Node* FindMax(Node* root){
    if (root->right == NULL) return root;
    else return FindMax(root->right);
}

int FindHeight(Node* root){ 
    if (root == NULL) return -1; // Leaf nodes are at 0 height

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Breadth-first search goes through each level of a tree (Ex. Root then, left and right child of root, then left and right children of those nodes, etc.)
//  To do a level order search we put nodes into a queue, then once at the front of the queue we do the operations to them, then add their children (if any),
//      then pop the current node from queue
void LevelOrder(Node* root){
    if (root == NULL) return;
    queue<Node*> Q; 
    Q.push(root); // Puts root into the queue

    while (!Q.empty()){
        Node* current = Q.front(); // Sets the current node to the one in the front of the queue
        cout << current->data << " "; // Prints current node data
        if (current->left != NULL) Q.push(current->left); // If the current node has a left child, put it into the queue
        if (current->right != NULL) Q.push(current->right); // Same as above for right child
        Q.pop(); // Remove current node from the queue
    }
} //LevelOrder:  O(n) time complexity   |   O(n) space complexity

// Depth-first search means to visit an entire sub tree before moving on
//  There are different permeations of depth-first traversal:
//      Preorder traversal is root -> left -> right
//      Inorder traversal is left -> root -> right
//      Postorder traversal is left -> right -> root
//  You can also do permeations of the above with right first instead of left

void Preorder(Node* root){
    if (root == NULL) return;
    printf("%d ", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(Node* root){
    if (root == NULL) return;
    Inorder(root->left);
    printf("%d ", root->data);
    Inorder(root->right);
}
void Postorder(Node* root){
    if (root == NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    printf("%d ", root->data);
} //Preorder, Inorder, and Postorder:  O(n) time complexity  |  O(n) space complexity   

int main()
{
    Node* root = NULL;
    root = Insert(root, 15); root = Insert(root, 17); root = Insert(root, 19); root = Insert(root, 11); //                                  15
    root = Insert(root, 12); root = Insert(root, 3); root = Insert(root, 20); root = Insert(root, 34);  //                              11      17
    root = Insert(root, 25); root = Insert(root, 31); root = Insert(root, 22); root = Insert(root, 2);  //                            3    12      19
    int i;                                                                                              //                           2               20
    cout << "Enter number you would like to search for:\n";                                             //                                             34
    cin>>i;                                                                                             //                                           25
    if (Search(root, i)) cout<<"Found\n";                                                               //                                        22    31
    else cout<<"Not Found\n";
    cout << "Min in tree is: " << FindMin(root)->data << "\n";
    cout << "Max in tree is: " << FindMax(root)->data << "\n";
    cout << "Height of tree is: " << FindHeight(root) << "\n";

    cout << "Level order: ";
    LevelOrder(root);
    cout << "\n";

    cout << "Preorder: ";
    Preorder(root);
    cout << "\n";

    cout << "Inorder: ";
    Inorder(root);
    cout << "\n";

    cout << "Postorder: ";
    Postorder(root);
    cout << "\n";
}