#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int n;
    struct Node *next;

};

void reverse(struct Node *a, struct Node *b)
{
    if (b -> next == NULL)
    {
        b -> next = a;
        return;
    }
    reverse(b, b -> next);
    b -> next = a;
}

int main(int argc, char *argv[])
{
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp -> n = 1;
    tmp -> next = NULL;
    struct Node *head = tmp;
    struct Node *last = tmp;
    for(int i = 2; i < 10; i++)
    {
        tmp = (struct Node*)malloc(sizeof(struct Node));
        tmp -> n = i;
        tmp -> next = NULL;
        last -> next = tmp;
        last = tmp;
    }

    struct Node *now = head;
    while(now != NULL)
    {
        printf("%d\n", now -> n);
        now = now -> next;
    }
    printf("----------------------------------------\n");
    reverse(NULL, head);
    now = last;
    while(now != NULL)
    {
        printf("%d\n", now -> n);
        now = now -> next;
    }
    return 0;
}
