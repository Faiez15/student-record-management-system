/*
 * Student Record Search using Hashing with Linear Probing
 * Compile: gcc hashing.c -o hashing
 * Run:     ./hashing
 */
#include <stdio.h>

#define SIZE 61
#define EMPTY -1

int table[SIZE];
int collisions = 0;
int comparisons = 0;

int hashFunction(int key) { return key % SIZE; }

void initialize(void) {
    for (int i=0;i<SIZE;i++) table[i]=EMPTY;
}

/* Returns 1 if inserted, 0 if duplicate or table full. */
int insert(int key) {
    int index=hashFunction(key);
    for (int i=0;i<SIZE;i++) {
        int pos=(index+i)%SIZE;
        if (table[pos]==EMPTY) { table[pos]=key; return 1; }
        if (table[pos]==key) return 0;
        collisions++; /* occupied slot that must be probed */
    }
    return 0;
}

int search(int key) {
    int index=hashFunction(key);
    for (int i=0;i<SIZE;i++) {
        int pos=(index+i)%SIZE;
        comparisons++;
        if (table[pos]==EMPTY) return 0;
        if (table[pos]==key) return 1;
    }
    return 0;
}

void display(void) {
    for (int i=0;i<SIZE;i++)
        if (table[i]!=EMPTY) printf("Index %2d : %d\n",i,table[i]);
}

int main(void) {
    int data[]={105,110,115,120,125,130,135,140,145,150,
                155,160,165,170,175,180,185,190,195,200,
                205,210,215,220,225,230,235,240,245,250};
    int n=sizeof(data)/sizeof(data[0]);
    initialize();
    for (int i=0;i<n;i++) insert(data[i]);

    printf("Hashing with Linear Probing - Student Record Search\n");
    printf("Records inserted: %d\n",n);
    printf("Table size: %d; hash function: key %% %d\n",SIZE,SIZE);
    printf("Total insertion collisions: %d\n",collisions);
    printf("Occupied table slots:\n"); display();

    int key=175;
    comparisons=0;
    printf("Successful search %d: %s; comparisons = %d\n",
           key,search(key)?"FOUND":"NOT FOUND",comparisons);

    key=999;
    comparisons=0;
    printf("Unsuccessful search %d: %s; comparisons = %d\n",
           key,search(key)?"FOUND":"NOT FOUND",comparisons);

    insert(252);
    comparisons=0;
    printf("After inserting 252, search: %s; comparisons = %d\n",
           search(252)?"FOUND":"NOT FOUND",comparisons);
    printf("Total collisions including insertion of 252: %d\n",collisions);
    return 0;
}
