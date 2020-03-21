#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data; 
    struct Node *left;
    struct Node* right;
};

struct Node* insert_key(struct Node *root, int key)
{
    if(root == NULL)
    {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = key;
        root->left = NULL;
        root->right = NULL;
    }
    else 
    {
        if(key >= root->data)
        {
            root->right = insert_key(root->right, key);
        }
        else if(key < root->data)
        {
            root->left = insert_key(root->left, key);
        }
    }   

    return root;
}

int height(struct Node *root)
{
    int lh = 0,rh = 0;
    if(root == NULL)
    {
        return -1; 
    }
    else 
    {   
        int lh = height(root->left) + 1; 
        int rh = height(root->right) + 1; 

        int ret = lh > rh ? lh: rh; 
        return ret;
    }
}

void inorder_traversal(struct Node *root)
{
    if(root != NULL)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main(int argc, char const *argv[])
{
    
    struct Node *root = NULL;
    root = insert_key(root, 23);
    insert_key(root, 23);
    insert_key(root, 12);
    insert_key(root, 1);
    insert_key(root, 9);
    insert_key(root, 11);
    insert_key(root, 8);
    insert_key(root, 24);
    inorder_traversal(root);
    printf("The height of the tree : %d", height(root));
    return 0;
}
