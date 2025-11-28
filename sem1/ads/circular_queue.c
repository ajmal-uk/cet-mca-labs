#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define Max 100


int frond, rear , maxSize , i , item , option;
int queue[Max];

void enQueue();
void decQueue();
void traversal();
void search();

int main(){
    frond = rear = -1;
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

void enQueue() {
    if ((frond == (rear + 1) % maxSize)) {
        printf("\nOverflow - Queue is full!\n");
        return;
    }

    printf("\nEnter the Item to insert into queue: ");
    scanf("%d", &item);

    if (frond == -1) {
        frond = rear = 0;
    } else {
        rear = (rear + 1) % maxSize;
    }

    queue[rear] = item;
    printf("\nItem inserted successfully!\n");
}

void decQueue() {
    if (frond == -1) {
        printf("\nUnderflow - Queue is empty!\n");
        return;
    }

    printf("\nItem '%d' removed successfully!", queue[frond]);

    if (frond == rear) {
        frond = rear = -1;
    } else {
        frond = (frond + 1) % maxSize;
    }
}

void traversal() {
    if (frond == -1) {
        printf("\nQueue is empty!\n");
        return;
    }

    printf("\n");
    if (frond > rear) {
        for (i = frond; i <= maxSize - 1; i++) {
            printf("| %d ", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("| %d ", queue[i]);
        }
    } else {
        for (i = frond; i <= rear; i++) {
            printf("| %d ", queue[i]);
        }
    }
}

void search(){
    if (frond == -1) {
        printf("\nQueue is empty!\n");
        return;
    }
    printf("\nEnter the Item to Search : ");
    scanf("%d", &item);
    bool itemFound = false;

    if(frond>rear){
        for(i = frond ; i <= maxSize-1; i++){
            if(queue[i] == item){
                printf("\nItem ' %d ' Found on ' %d ' ",item, i);
                itemFound = true;
            }
        }
        for(i = 0 ; i <=rear; i++){
            if(queue[i] == item){
                printf("\nItem ' %d ' Found on ' %d ' ",item, i);
                itemFound = true;
            }
        }
    }
    else{
        for(i = frond ; i <= rear; i++){
            if(queue[i] == item){
                printf("\nItem ' %d ' Found on ' %d ' ",item, i);
                itemFound = true;
            }
        }
    }

    if(!itemFound){
        printf("Item Not Found in Queue");
    }
}