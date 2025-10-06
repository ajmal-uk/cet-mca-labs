#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *r_link, *l_link;
};

struct node *head,*temp,*ptr;
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
void reverse_traversal();

int main() {
    head = (struct node*)malloc(sizeof(struct node));
    head->r_link = NULL;
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
                reverse_traversal();
                break;
            case 9:
                search();
                break;
            case 10:
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
    ptr->r_link = head->r_link;
    ptr->l_link = head;
    head->r_link = ptr;
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
    while(temp->r_link != NULL){
        temp = temp->r_link;
    }
    temp->r_link = ptr;
    temp->l_link = ptr->l_link;
    ptr->l_link= temp;
    ptr->r_link = NULL;

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
        temp = temp->r_link;
    }
    ptr->r_link = temp->r_link;
    ptr->l_link = temp;
    temp->r_link = ptr;
}


void deleteFirst(){
    if(head->r_link == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    ptr = head->r_link;
    head->r_link = ptr->r_link;
    ptr->r_link->l_link = head;
    free(ptr);
}

void deleteEnd(){
    ptr = head;
    if(ptr->r_link == NULL){
        printf("\nNo Node for Delete!!");
        return;
    }
    while(ptr->r_link->r_link!=NULL){
        ptr = ptr->r_link;
    } 
    free(ptr->r_link);
    ptr->r_link = NULL;
}

void deletePosition(){
    if(head->r_link == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    ptr = head;
    printf("\nEnter the Position to Delete Node.");
    scanf("%d",&position);
    for(i=1;i<position;i++){
        ptr = ptr->r_link;
    }
    ptr->l_link->r_link = ptr->r_link;
    ptr->r_link->l_link = ptr->l_link;
    free(ptr);
}

void traversal(){
    temp = head->r_link;
    if(temp == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    printf("\n| NULL | HEAD | %p |", (void*)temp);
    while(temp != NULL){
        printf(" ---> | %p | ", (void*)temp->l_link);
        printf(" %d | ", temp->data);
        if(temp->r_link != NULL)
            printf("%p | ", (void*)temp->r_link);
        else
            printf("NULL | ");
        temp = temp->r_link;
    }
    printf("\n");
}

void reverse_traversal(){
    if (head->r_link == NULL) {
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    }
    temp = head->r_link;
    while (temp->r_link != NULL) {
        temp = temp->r_link;
    }
    printf("\nReverse Traversal:\n");
    while (temp != head) {
        printf("| %d |", temp->data);
        if (temp->l_link != head)
            printf(" <--- ");
        temp = temp->l_link;
    }
    printf(" <--- | HEAD |\n");
}


void search(){
    temp = head->r_link;
    if(head->r_link == NULL){
        printf("\nNo Node -- >  UnderFlow !!");
        return;
    };
    itemFound = false;
    printf("\nEnter the Item to Search : ");
    scanf("%d",&item);
    i = 1;
    while(temp != NULL){
        if(item == temp->data){
            printf("\nItem Found At Node - | Address | Position | Left Link | Data | Right Link | --->  | %p | %d | %p | %d | %p |",temp,i,temp->l_link, temp->data, temp->r_link);
            itemFound = true;
        }
        i++;
        temp = temp->r_link;
    }
    if(!itemFound){
        printf("\nItem Not in List");
    }
}