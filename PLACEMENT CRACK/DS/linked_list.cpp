#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
    int data;
    struct node *link;
};

struct node *root = nullptr;

void insterFirst(){
    int item;
    cout<<"Enter the Item to Insert";

    if(!root){
        root->data = item;
        root->link = nullptr;
        return;
    }

    struct node *ptr = new node();
    ptr->data = item;
    root->link = ptr;
    ptr->link = nullptr;
}

void deleteFirst(){
    if(!root){
        cout<<"No Item to Remove";
    }else{
        struct node *temp = root;
        root = root->link;
        free(temp);
    }
}


void traveral(){
    if(!root){
        cout<<"No Item to Remove";
    }else{
        struct node *temp = root;
        while(temp!=nullptr){
            cout<"| "<< temp->data;
        }
    }
}

int main(){
    return 0;
}