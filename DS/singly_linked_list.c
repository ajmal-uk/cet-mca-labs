#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head;

void insertFirst();
void insertEnd();
void insertRandom();
void deleteFirst();
void deleteEnd();
void deleteRandom();
void traversal();
void search();

int option, item;

int main() {
    head->link = NULL;
    while(1){
        printf("\n========== MENU ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Traverse List\n");
        printf("8. Search in List\n");
        printf("9. Exit\n");
        printf("==========================\n");
        printf("Enter your choice: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                insertFirst();
                break;
            case 2:
                insertEnd();
                break;
            case 3:
                insertRandom();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deleteRandom();
                break;
            case 7:
                traversal();
                break;
            case 8:
                search();
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose between 1 and 9.\n");
        }
    }
    return 0;
}


void insertFirst(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(prt == NULL){
        printf("\nOverflow");
        return;
    }
    prinf("\nEnter the Item to Enter : ");
    scanf("%d",&item);
    ptr->data = item;
    if(head->link == NULL){
        head->link = ptr
    }
    else{
        ptr->link = head->link;
        head->link = prt;
    }
}

void insertEnd(){
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if(prt == NULL){
        printf("\nOverflow");
        return;
    }
    struct node *temp = head;
    prinf("\nEnter the Item to Enter : ");
    scanf("%d",&item);
    ptr->data = item;
    while(temp->link != NULL){
        
    }
}

void deleteFirst(){
    if(head->link == NULL){
        printf("\nUnderFlow!");
        return;
    }
    struct node *ptr = head->link;
    head->link = ptr->link;

}