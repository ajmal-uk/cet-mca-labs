#include <stdio.h>

#define MAX 8   // universal set U = {0,1,2,...,MAX-1}

// Helpers
void initSet(int S[]) {
    for (int i = 0; i < MAX; ++i) S[i] = 0;
}

void insertElement(int S[], int x) {
    if (x >= 0 && x < MAX) S[x] = 1;
}

void deleteElement(int S[], int x) {
    if (x >= 0 && x < MAX) S[x] = 0;
}

int isMember(int S[], int x) {
    if (x < 0 || x >= MAX) return 0;
    return S[x];
}

void printBitstring(int S[]) {
    for (int i = MAX - 1; i >= 0; --i) printf("%d", S[i]);
    printf("\n");
}

void printSetElements(int S[]) {
    int first = 1;
    printf("{");
    for (int i = 0; i < MAX; ++i) {
        if (S[i]) {
            if (!first) printf(", ");
            printf("%d", i);
            first = 0;
        }
    }
    if (first) printf("}"); else printf("}");
    printf("\n");
}

// Set operations (result stored in R)
void setUnion(int A[], int B[], int R[]) {
    for (int i = 0; i < MAX; ++i) R[i] = (A[i] || B[i]) ? 1 : 0;
}

void setIntersection(int A[], int B[], int R[]) {
    for (int i = 0; i < MAX; ++i) R[i] = (A[i] && B[i]) ? 1 : 0;
}

void setDifference(int A[], int B[], int R[]) {
    // A \ B  -> elements in A that are not in B
    for (int i = 0; i < MAX; ++i) R[i] = (A[i] && !B[i]) ? 1 : 0;
}

void setSymmetricDifference(int A[], int B[], int R[]) {
    for (int i = 0; i < MAX; ++i) R[i] = (A[i] ^ B[i]) ? 1 : 0;
}

void setComplement(int A[], int R[]) {
    for (int i = 0; i < MAX; ++i) R[i] = A[i] ? 0 : 1;
}

// Predicates
int isSubset(int A[], int B[]) {
    // A subset of B -> every element of A is also in B
    for (int i = 0; i < MAX; ++i) {
        if (A[i] && !B[i]) return 0;
    }
    return 1;
}

int isEqual(int A[], int B[]) {
    for (int i = 0; i < MAX; ++i) if (A[i] != B[i]) return 0;
    return 1;
}

// Demo
int main() {
    int A[MAX], B[MAX], R[MAX];
    initSet(A); initSet(B); initSet(R);

    // A = {1, 3, 4}
    insertElement(A, 1);
    insertElement(A, 3);
    insertElement(A, 4);

    // B = {2, 3, 6}
    insertElement(B, 2);
    insertElement(B, 3);
    insertElement(B, 6);

    printf("Universal set size MAX = %d (elements 0..%d)\n\n", MAX, MAX-1);

    printf("A (bits): ");
    printBitstring(A);
    printf("A (elements): "); printSetElements(A);
    printf("\n");

    printf("B (bits): ");
    printBitstring(B);
    printf("B (elements): "); printSetElements(B);
    printf("\n");

    setUnion(A, B, R);
    printf("A ∪ B (bits): ");
    printBitstring(R);
    printf("A ∪ B (elements): "); printSetElements(R);
    printf("\n");

    setIntersection(A, B, R);
    printf("A ∩ B (bits): ");
    printBitstring(R);
    printf("A ∩ B (elements): "); printSetElements(R);
    printf("\n");

    setDifference(A, B, R);
    printf("A \\ B (bits): ");
    printBitstring(R);
    printf("A \\ B (elements): "); printSetElements(R);
    printf("\n");

    setDifference(B, A, R);
    printf("B \\ A (bits): ");
    printBitstring(R);
    printf("B \\ A (elements): "); printSetElements(R);
    printf("\n");

    setSymmetricDifference(A, B, R);
    printf("A △ B (bits): ");
    printBitstring(R);
    printf("A △ B (elements): "); printSetElements(R);
    printf("\n");

    setComplement(A, R);
    printf("Complement of A (w.r.t U) (bits): ");
    printBitstring(R);
    printf("Complement of A (elements): "); printSetElements(R);
    printf("\n");

    printf("Is A subset of B? %s\n", isSubset(A,B) ? "Yes" : "No");
    printf("Is B subset of A? %s\n", isSubset(B,A) ? "Yes" : "No");
    printf("Are A and B equal? %s\n", isEqual(A,B) ? "Yes" : "No");

    return 0;
}
