#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = NULL;

void push();
void pop();
void traversal();
void search();

int main() {
    int option;
    while(1){
        printf("\n\n1.Push\n2.Pop\n3.Traversal\n4.Search\n5.Exit\n\nEnter the Option : ");
        scanf("%d", &option);
        switch (option) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traversal(); break;
            case 4: search(); break;
            case 5: exit(0);
            default: printf("Invalid Option\n");
        }
    }
    return 0;
}

void push() {
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nStack Overflow");
        return;
    }
    int item;
    printf("\nEnter the Item to Enter : ");
    scanf("%d", &item);
    ptr->data = item;
    ptr->link = top;
    top = ptr;
    printf("Item pushed: %d\n", item);
}

void pop() {
    if(top == NULL){
        printf("\nStack Underflow! No elements to pop.\n");
        return;
    }
    struct node *ptr = top;
    int popped_item = ptr->data;
    top = top->link;
    free(ptr);
    printf("\nPopped item: %d\n", popped_item);
}

void traversal() {
    if(top == NULL){
        printf("\nStack is empty.\n");
        return;
    }
    struct node *ptr = top;
    printf("\nStack from top to bottom:\n");
    while(ptr != NULL){
        printf("| %d | ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void search() {
    if(top == NULL){
        printf("\nStack is empty.\n");
        return;
    }
    int item, pos = 1;
    bool itemFound = false;
    printf("\nEnter the Item to Search : ");
    scanf("%d", &item);

    struct node *ptr = top;
    while(ptr != NULL){
        if(ptr->data == item){
            printf("\nItem Found at position %d from top.\n", pos);
            itemFound = true;
            break;
        }
        ptr = ptr->link;
        pos++;
    }
    if(!itemFound){
        printf("\nItem not found in the stack.\n");
    }
}
