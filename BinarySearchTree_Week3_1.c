#include<stdio.h>
#include<stdlib.h>
static int arr_in[100];
static int i=0;
struct node
{
    int key;
    struct node *left, *right;
};
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        arr_in[i]=root->key;
        i++;
        inorder(root->right);
    }
}
struct node* insert(struct node* node, int key)
{

    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;
    return current;
}
struct node* deleteNode(struct node* root, int key)
{
    if (root == NULL) return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {

        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int pop(int k)
{
    return arr_in[k-1];
}
void main()
{
    struct node *root = NULL;
    root = insert(root, 500);
    root = insert(root, 16);
    root = insert(root, 26);
    root = insert(root, 40);
    root = insert(root, 42);
    root = insert(root, 60);
    root = insert(root, 8);
    printf("Inorder traversal also gives the sorted form of the elements of the given binary search tree\n");
    inorder(root);
    printf("\nNow printing the 3rd smallest element\n%d",pop(3));
}
