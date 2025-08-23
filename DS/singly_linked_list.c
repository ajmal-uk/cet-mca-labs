#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head,*temp,*ptr, *mergeHead, *copyHead;
int option, item, position, i;
bool itemFound;

void insertFirst();
void insertEnd();
void insertPosition();
void deleteFirst();
void deleteEnd();
void deletePosition();
void traversal();
void search();
void merge();
void copyList();
void traversalCopy();

int main() {
    head = (struct node*)malloc(sizeof(struct node));
    head->link = NULL;
    copyHead = (struct node*)malloc(sizeof(struct node));
    copyHead->link = NULL;
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
        printf("9. Merge\n");
        printf("10. Copy List\n");
        printf("11. Traverse Copied List\n");
        printf("12. Exit\n");
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
                insertPosition();
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                deletePosition();
                break;
            case 7:
                traversal();
                break;
            case 8:
                search();
                break;
            case 9:
                merge();
                break;
            case 10:
                copyList();
                break;
            case 11:
                traversalCopy();
                break;
            case 12:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose between 1 and 9.\n");
        }
    }
    return 0;
}


void insertFirst(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
        return;
    }
    printf("\nEnter the Item to Enter : ");
    scanf("%d",&item);
    ptr->data = item;
    ptr->link = head->link;
    head->link = ptr;
}

void insertEnd(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
        return;
    }
    temp = head;
    printf("\nEnter the Item to Enter : ");
    scanf("%d",&item);
    ptr->data = item;
    while(temp->link != NULL){
        temp = temp->link;
    }
    temp->link = ptr;
    ptr->link = NULL;

}
void insertPosition(){
    temp = head;
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL){
        printf("\nOverflow");
        return;
    }
    printf("\nEnter the Item to Enter : ");
    scanf("%d",&item);
    ptr->data = item;
    printf("\nEnter the Position to insert Node : ");
    scanf("%d",&position);
    for(i=1;i<position;i++){
        temp = temp->link;
    }
    ptr->link = temp->link;
    temp->link = ptr;
}


void deleteFirst(){
    if(head->link == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    ptr = head->link;
    head->link = ptr->link;
}

void deleteEnd(){
    ptr = head;
    if(ptr->link == NULL){
        printf("\nNo Node for Delete!!");
        return;
    }
    while(ptr->link->link!=NULL){
        ptr = ptr->link;
    } 

    ptr->link = NULL;
}

void deletePosition(){
    if(head->link == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    ptr = head;
    printf("\nEnter the Position to Delete Node.");
    scanf("%d",&position);
    for(i=1;i<position;i++){
        ptr = ptr->link;
    }
    ptr->link = ptr->link->link;
}

void traversal(){
    temp = head->link;
    if(temp == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    printf("\n| HEAD | %p |", (void*)temp);
    while(temp != NULL){
        printf(" ---> | %d | ", temp->data);
        if(temp->link != NULL)
            printf("%p | ", (void*)temp->link);
        else
            printf("NULL | ");
        temp = temp->link;
    }
    printf("\n");
}


void search(){
    temp = head->link;
    if(head->link == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    };
    itemFound = false;
    printf("\nEnter the Item to Search : ");
    scanf("%d",&item);
    i = 1;
    while(temp != NULL){
        if(item == temp->data){
            printf("\nItem Found At Node - | Address | Position | Data | Link | --->  | %p | %d | %d | %p |",temp,i, temp->data, temp->link);
            itemFound = true;
        }
        i++;
        temp = temp->link;
    }
    if(!itemFound){
        printf("\nItem Not in List");
    }
}


void merge(){
    mergeHead = (struct node*)malloc(sizeof(struct node));
    int count;
    mergeHead->link = NULL;
    temp = mergeHead;
    printf("\n=== New Linked List ===");
    printf("\nEnter the Number of Items Did You Want to Add in New is to Merge : ");
    scanf("%d",&count);
    printf("\nEnter The Item One By One");
    for(i=0;i<count;i++){
        printf("\nEnter the Item [%d] : ",i+1);
        scanf("%d",&item);
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->link = NULL;
        ptr->data = item;
        while(temp->link !=NULL){
            temp = temp->link;
        }
        temp->link = ptr;
    }
    temp = head;
    while(temp->link!=NULL){
        temp = temp->link;
    }
    temp->link = mergeHead->link;
}


void copyList(){
    temp = head;
    struct node *tempCopy = copyHead;
    printf("\n=== Copying Started ===");
    while(temp->link!=NULL){
        temp = temp->link;
        ptr = (struct node*)malloc(sizeof(struct node));
        ptr->link = NULL;
        ptr->data = temp->data;
        tempCopy->link = ptr;
        tempCopy = ptr;
    }
    printf("\n=== Copying Success ===");
    traversalCopy();
}

void traversalCopy(){
    temp = copyHead->link;
    if(temp == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    printf("\n=== Copied List ===");
    printf("\n| HEAD | %p |", (void*)temp);
    while(temp != NULL){
        printf(" ---> | %d | ", temp->data);
        if(temp->link != NULL)
            printf("%p | ", (void*)temp->link);
        else
            printf("NULL | ");
        temp = temp->link;
    }
    printf("\n");
}