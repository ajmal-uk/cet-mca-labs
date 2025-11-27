#include<stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int item){
    if(top == MAX-1){
        printf("\nOverflow");
        return;
    }
    stack[++top] = item;
}

int pop(){
    if(top == -1){
        printf("\nUnderflow\n");
        return -1;
    }
    return stack[top--];
}

void traversal(){
    if(top == -1){
        printf("\nStack is empty\n");
        return;
    }
    for(int i = top; i >= 0; i--){
        printf("| %d |\n", stack[i]);
        if(i != 0)
            printf("-----\n");
    }
    printf("-----\n");
}

int main(){
    int choice, item;

    while(1){
        printf("\n\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item = pop();
                if(item != -1)
                    printf("Popped element: %d\n", item);
                break;

            case 3:
                printf("\nStack contents:\n");
                traversal();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
