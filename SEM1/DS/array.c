// Online C compiler to run C program online
#include <stdio.h>
#define MAX 100


int array[MAX];
int n;

void create_array(){
    printf("Enter the Numebr of Elements in Array : ");
    scanf("%d",&n);
    printf("\n\nEnter the Each Elements : ");
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
}


void display_array(){
    printf("Array Elements Are : \n");
    for(int i=0;i<n;i++){
        printf(" ___");
    }
    printf("\n");
    for (int i=0;i<n;i++){
        printf("| %d ",array[i]);
        if(i==n-1){
            printf("|\n");
        }
    }
    for(int i=0;i<n;i++){
        printf(" ---");
    }
    printf("\n");
}

void insert_begining(int item){
    for(int i=n;i>0;i--){
        array[i] = array[i-1];
    }
    array[0] = item;
    n++;
}

void insert_end(int item){
    array[n]=item;
    n++;
}

void insert_position(int pos, int item){
    for(int i=n;i>pos;i--){
        array[i] = array[i-1];
    }
    array[pos] = item;
    n++;
}

void insert_element(){
    int op;
    int number;
    if(n>MAX-1){
        printf("Maximum Size Used");
        return;
    }
    printf("\n1.Insert Begning\n2.Insert End\n3.Insert Position\n4.Exit\nEnter your Choice : ");
    scanf("%d",&op);
    if(op==1 || op==2 || op ==3){
        printf("\nEnter the Item to Insert in Array : ");
        scanf("%d",&number);
    }
    if(op==1){
        insert_begining(number);
    }else if(op==2){
        insert_end(number);
    }else if(op==3){
        int position;
        printf("\nEnter the index to Insert Item (0 - %d:) :  ",n-1);
        scanf("%d",&position);
        if(position>n){
            printf("You can't insert at %d index , your array size in %d",position,n-1);
        }
        if(position==0){
            insert_begining(number);
        }else if(position==n){
            insert_end(number);
        }else{
            insert_position(position,number);
        }
    }else{
        return;
    }
}


void array_reverse(int first, int last){
    if(first>=last){
        return;
    }
    array[first] = array[first] + array[last];
    array[last] = array[first] - array[last];
    array[first] = array[first] - array[last];
    array_reverse(first+1,last-1);
}


void array_sort(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(array[j]>array[j+1]){
                array[j] = array[j] + array[j+1];
                array[j+1] = array[j] - array[j+1];
                array[j] = array[j] - array[j+1];
            }
        }
    }
}


int main() {
    create_array();
    display_array();
    array_reverse(0,n-1);
    display_array();
    array_sort();
    display_array();
    insert_element();
    display_array();
    return 0;
}
