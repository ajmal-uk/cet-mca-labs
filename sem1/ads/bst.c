#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *ROOT = NULL;


void insert(int item);
void delete(int item);
void traversal();


void preOrder(struct node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}

void inOrder(struct node *ptr){
    if(ptr!=NULL){
        inOrder(ptr->left);
        printf("%d ",ptr->data);
        inOrder(ptr->right);
    }
}

void postOrder(struct node *ptr){
    if(ptr!=NULL){
        postOrder(ptr->left);
        postOrder(ptr->right);
        printf("%d ",ptr->data);
    }
}

int main(){
    int op;
    int item;
    while(1){ 
        printf("\nEnter the Option : \n1.Insert\n2.Delete\n3.Traversal\n4.Exit");
        scanf("%d",&op);
        if(op == 1 || op == 2){
            printf("\nEnter the Item to ");
            if(op == 1) printf("Insert");
            else printf("Delete");
            scanf("%d",&item);
        }
            switch(op){
                case 1: insert(item);
                        break;
                case 2: delete(item);
                        break;
                case 3: traversal();
                        break;
                case 4: exit(0);
                default : printf("\nChose Correct Option!");
            }
    }
    return 0;
}

struct node* createNode(int item){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = item;
    new->left = new->right = NULL;
    return new;
}

void insert(int item){
    if(ROOT == NULL){
        ROOT = createNode(item);
        return;
    }
    struct node *ptr = ROOT,*parent = NULL;
    while(ptr!=NULL){
        parent = ptr;
        if(item < ptr->data){
            ptr = ptr->left;
        }else if(item > ptr->data){
            ptr = ptr->right;
        }else{
            printf("\nItem already Exists ");
            return;
        }
    }
    struct node * new = createNode(item);

    if(item<parent->data){
        parent->left=new;
    }else{
        parent->right = new;
    }
}

void delete(int item){
    int flag=0, met;
    struct node *ptr = ROOT, *parent = NULL;
    while(ptr!=NULL){
        if(item < ptr->data){
            parent = ptr;
            ptr=ptr->left;
        }else if(item > ptr->data){
            parent = ptr;
            ptr=ptr->right;
        }else{
            flag = 1;
            break;
        }
    }
    if(flag == 0){
        printf("Item not found");
        return;
    }
    if(ptr->left == NULL && ptr->right == NULL) met = 1;
    else if(ptr->left != NULL && ptr->right != NULL) met = 3;
    else met = 2;

    if(met == 1){
        if (parent == NULL) {
            ROOT = NULL;
        }else if(parent->left == ptr){
            parent->left = NULL;
        }else{
            parent->right = NULL;
        }
        free(ptr);
    }else if(met == 3){
        struct node *suc = ptr->right,*sucPar = ptr;
        while(suc->left!=NULL){
            sucPar = suc;
            suc = suc->left;
        }
        ptr -> data = suc->data;

        if(sucPar->left == suc){
            sucPar->left = suc->right;
        }else{
            sucPar->right = suc->right;
        }
        free(suc);
    }else{
        struct node *child = (ptr->left!=NULL) ? ptr->left : ptr->right;
        if (parent == NULL) {
            ROOT = child;
        }else if(parent->left == ptr){
            parent->left = child;
        }else{
            parent->right = child;
        }
        free(ptr);
    }
}

void traversal(){
    int mode;
    printf("\n1.Preorder\n2.Inorder\n3.Postorder\nEnter The Mode : ");
    scanf("%d",&mode);
    switch (mode)
    {
    case 1: preOrder(ROOT);
        break;
    case 2: inOrder(ROOT);
        break;
    case 3: postOrder(ROOT);
        break;
    default:
        break;
    }
}
