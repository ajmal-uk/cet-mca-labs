#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Max 100


int front, rear , maxSize , i , item , option;
int queue[Max];

void enQueue();
void decQueue();
void traversal();
void search();

int main(){
    front = rear = -1;
    printf("\nEnter the Maximum Size of Queue : ");
    scanf("%d",&maxSize);
    while(1){
        printf("\n\n1.Enqueue\n2.DeQueue\n3.Traversal\n4.Search\n5.Exit\n\nEnter the Option : ");
        scanf("%d",&option);
        switch (option)
        {
            case 1 : enQueue(); break;
            case 2 : decQueue(); break;
            case 3 : traversal(); break;
            case 4 : search(); break;
            case 5 : exit(0);
            default:
                break;
        }
    }
    return 0;
}


void enQueue(){
    if(rear == maxSize-1){
        printf("\nOverflow");
    }
    else{
        printf("\nEnter the Item to insert it into queue : ");
        scanf("%d",&item);
        rear++;
        queue[rear] = item;
        printf("\n 'Item inserted Successfully!!'");
    }
}

void decQueue(){
    if(front == -1){
        printf("\nUnderflow!!");
    }
    else{
        printf("\nItem '%d' removed Successfully!!",queue[front]);
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front++;
        }
    }
}


void traversal(){
    printf("\n");
    for(i = front ; i <= rear; i++){
        printf("| %d ", queue[i]);
    }
}

void search(){
    printf("\nEnter the Item to Search : ");
    scanf("%d", &item);
    bool itemFound = false;
    for(i=front; i<=rear; i++){
        if(queue[i] == item){
            printf("\nItem ' %d ' Found on ' %d ' ",item, i);
            itemFound = true;
        }
    }
    if(!itemFound){
        printf("Item Not Found in Queue");
    }
}