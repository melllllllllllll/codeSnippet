#include <stdio.h>
#include <stdlib.h>

#define NUMOFDIGIT 3
#define ARRLEN 10

struct Node {
    int val;
    struct Node *next;
};

void push(struct Node **lists, struct Node *node, int cmp) {
    int pos = node -> val / cmp % 10;
    struct Node *tmp = lists[pos];
    if(tmp == NULL) {
        lists[pos] = node;
    } else {
        while(tmp -> next != NULL) {
            tmp = tmp -> next;
        }
        tmp -> next = node;
    }
    
}

int main(int argc, char *argv[]) {
    int arr[ARRLEN] = {0, 1, 512, 343, 64, 125, 216, 27, 8, 729};
    struct Node *tmp = NULL;
    struct Node *lists[10];
    int cmp = 1;

    for(int i = 0; i < NUMOFDIGIT; i++) {
        for(int i = 0; i < 10; i++) {
            lists[i] = NULL;
        }

        for(int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
            tmp = malloc(sizeof(struct Node));
            tmp -> val = arr[i];
            tmp -> next = NULL;
            push(lists, tmp, cmp);
        }
        cmp *= 10;

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        for(int i = 0; i < sizeof(lists) / sizeof(lists[0]); i++) {
            printf("%d\t", i);
            tmp = lists[i];
            while(tmp != NULL) {
                printf("|>%p -> %3d\t", tmp, tmp -> val);
                tmp = tmp -> next;
            }
            printf("\n");
        }

        for(int i = 0, j = 0; i < sizeof(lists) / sizeof(lists[0]); i++) {
            tmp = lists[i];
            struct Node *tofree;
            while(tmp != NULL) {
                arr[j++] = tmp -> val;
                tofree = tmp;
                tmp = tmp -> next;
                free(tofree);
                tofree = NULL;
            }
        }
    }

    return 0;
}
