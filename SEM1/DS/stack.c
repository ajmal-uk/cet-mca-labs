#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Max 100
int i,top, maxSize, item;
int stack[Max];
void push();
void pop();
void traversal();
void search();

int main(){
    top = -1;
    printf("\nEnter the Maximum Size of Stack : ");
    scanf("%d",&maxSize);
    int option;
    while(1){
        printf("\n\n1.Push\n2.Pop\n3.Traversal\n4.Search\n5.Exit\n\nEnter the Option : ");
        scanf("%d",&option);
        switch (option)
        {
            case 1 : push(); break;
            case 2 : pop(); break;
            case 3 : traversal(); break;
            case 4 : search(); break;
            case 5 : exit(0);
            default:
                break;
        }
    }
    return 0;
}


void push(){
    if(top == maxSize-1){
        printf("\nOverflow");

    }
    else{
        printf("\nEnter the item to Insert in Stack  : ");
        scanf("%d",&item);
        stack[++top] = item;
        printf("\n%d inserted Sucess fully!!",item);
    }
}

void pop(){
    if(top == -1){
        printf("\nUnderflow");
    }
    else{
        printf("\n%d Removed!!" , stack[top]);
        top--;
    }
}

void traversal(){
    printf("\n");
    if(top == -1){
        printf("No items in stack");
    }
    else{
        for(i = top; i>=0; i--){
            printf("| %d |\n", stack[i]);
            printf(" ___ \n");
        }
    }
}

void search(){
    printf("\nEnter the Item to to search  : ");
    scanf("%d",&item);
    bool itemFound = false;
    for(i = top; i>=0; i--){
        if(stack[i] == item){
            printf("\nItem ' %d ' Found Success Fully. At the %d",item,i);
            itemFound = true;
        }
    }
    if(!itemFound){
        printf("Item Not Found in Stack");
    }
}