#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *root = NULL;
int option;

void insertion();
void deletion(); 
void traversal();
void inorder(struct node *node);
void preorder(struct node *node);
void postorder(struct node *node);

int main() {
    while (1) {
        printf("\n========== MENU ==========\n");
        printf("1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                traversal();
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose between 1 and 4.\n");
        }
    }
    return 0;
}

void insertion() {
    int item;
    printf("\nEnter the Data To Insert: ");
    scanf("%d", &item);

    if (root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = item;
        root->left = root->right = NULL;
        printf("Item inserted successfully 💕💕\n");
        return;
    }

    struct node *ptr = root, *parent = NULL;

    while (ptr != NULL) {
        parent = ptr;
        if (item == ptr->data) {
            printf("Item already exists in the Tree!\n");
            return;
        } else if (item < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = newNode->right = NULL;

    if (item < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    printf("Item inserted successfully 💕💕\n");
}

void inorder(struct node *node) {
    if (node == NULL)
        return;
    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}

void preorder(struct node *node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct node *node) {
    if (node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

void traversal() {
    int choice;

    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }

    printf("\n====== Traversal Menu ======\n");
    printf("1. Inorder\n2. Preorder\n3. Postorder\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nTraversal result: ");
    switch (choice) {
        case 1:
            inorder(root);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            postorder(root);
            break;
        default:
            printf("Invalid choice!\n");
            return;
    }
    printf("\n");
}

void deletion() {
    if (root == NULL) {
        printf("No items in the tree.\n");
        return;
    }

    int item;
    printf("Enter the item to remove: ");
    scanf("%d", &item);

    struct node *ptr = root, *parent = NULL;

    while (ptr != NULL && ptr->data != item) {
        parent = ptr;
        if (item < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (ptr == NULL) {
        printf("Item not found in the tree.\n");
        return;
    }
    if (ptr->left == NULL && ptr->right == NULL) {
        if (parent == NULL) {
            free(root);
            root = NULL;
        } else if (parent->left == ptr) {
            parent->left = NULL;
            free(ptr);
        } else {
            parent->right = NULL;
            free(ptr);
        }
    }
    else if (ptr->left == NULL || ptr->right == NULL) {
        struct node *child = (ptr->left != NULL) ? ptr->left : ptr->right;

        if (parent == NULL) {
            free(root);
            root = child;
        } else if (parent->left == ptr) {
            parent->left = child;
            free(ptr);
        } else {
            parent->right = child;
            free(ptr);
        }
    }
    else {
        struct node *succParent = ptr;
        struct node *succ = ptr->right;

        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        ptr->data = succ->data;

        if (succParent->left == succ)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        free(succ);
    }

    printf("Item deleted successfully!\n");
}
