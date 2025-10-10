#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int data[MAX], parent[MAX];
int position = -1;


void make_set(int item);
int find_set(int item);
void union_set(int item1, int item2);
void print_set();

int main() {
    make_set(1);
    make_set(2);
    make_set(3);
    make_set(4);
    make_set(5);

    union_set(1, 2);
    union_set(3, 4);
    union_set(2, 3);

    print_set();

    return 0;
}

void make_set(int item) {
    position++;
    data[position] = item;
    parent[position] = item;
}

int find_set(int item) {
    for (int i = 0; i <= position; i++) {
        if (data[i] == item) {
            if (parent[i] == item) {
                return item;
            } else {
                parent[i] = find_set(parent[i]);
                return parent[i];
            }
        }
    }
    return -1;
}

void union_set(int item1, int item2) {
    int root1 = find_set(item1);
    int root2 = find_set(item2);

    if (root1 == -1 || root2 == -1) {
        printf("Can't union: one or both items not found\n");
        return;
    }

    if (root1 != root2) {
        for (int i = 0; i <= position; i++) {
            if (data[i] == root2) {
                parent[i] = root1;
                break;
            }
        }
    }
}

void print_set() {
    int printed[MAX] = {0}; 
    bool printedRoots[MAX] = {false};

    for (int i = 0; i <= position; i++) {
        int item = data[i];
        int root = find_set(item);

        if (!printedRoots[root]) {
            printedRoots[root] = true;
            printf("{%d", root);

            for (int j = 0; j <= position; j++) {
                int temp_item = data[j];
                if (find_set(temp_item) == root && temp_item != root) {
                    printf(", %d", temp_item);
                }
            }
            printf("} ");
        }
    }
    printf("\n");
}
