#include <stdio.h>

int n, n1, n2;

void clearset(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = 0;
}

int ispresent(int arr[], int size, int ele) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == ele)
            return 1;
    }
    return 0;
}

void display(int set[], int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        printf("%d", set[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("}\n");
}

void makeSet(int uniset[], int set[], int n, int bitstr[]) {
    clearset(bitstr, n);
    for (int i = 0; i < n; i++) {
        bitstr[i] = ispresent(set, n, uniset[i]);
    }
}

void Union(int set1[], int set2[], int n) {
    int uni[n];
    for (int i = 0; i < n; i++) {
        uni[i] = set1[i] || set2[i];
    }
    display(uni, n);
}

void Intersection(int set1[], int set2[], int n) {
    int inter[n];
    for (int i = 0; i < n; i++) {
        inter[i] = set1[i] && set2[i];
    }
    display(inter, n);
}

void Difference(int set1[], int set2[], int n) {
    int diff[n];
    for (int i = 0; i < n; i++) {
        diff[i] = set1[i] && !set2[i];
    }
    display(diff, n);
}

void createset(int universal[], int set[], int n1) {
    clearset(set, n1);
    for (int i = 0; i < n1; i++) {
        int element;
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        if (ispresent(set, n1, element) == 0 && ispresent(universal, n, element) == 1)
            set[i] = element;
        else {
            printf("Invalid or duplicate element! Try again.\n");
            i--;
        }
    }
}

int main() {
    int element;
    printf("Enter number of elements in Universal Set: ");
    scanf("%d", &n);
    int universal[n], bitstr1[n], bitstr2[n];
    clearset(universal, n);
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &element);
        if (ispresent(universal, n, element) == 0)
            universal[i] = element;
        else {
            printf("Duplicate element! Try again.\n");
            i--;
        }
    }

    printf("Enter number of elements in Set 1: ");
    scanf("%d", &n1);
    int Set1[n1];
    createset(universal, Set1, n1);

    printf("Enter number of elements in Set 2: ");
    scanf("%d", &n2);
    int Set2[n2];
    createset(universal, Set2, n2);

    printf("Universal Set: ");
    display(universal, n);
    printf("Set 1: ");
    display(Set1, n1);
    printf("Set 2: ");
    display(Set2, n2);

    makeSet(universal, Set1, n, bitstr1);
    makeSet(universal, Set2, n, bitstr2);

    printf("\nUnion of Set 1 and Set 2: ");
    Union(bitstr1, bitstr2, n);
    printf("Intersection of Set 1 and Set 2: ");
    Intersection(bitstr1, bitstr2, n);
    printf("Set 1 - Set 2: ");
    Difference(bitstr1, bitstr2, n);
    printf("Set 2 - Set 1: ");
    Difference(bitstr2, bitstr1, n);

    return 0;
}
