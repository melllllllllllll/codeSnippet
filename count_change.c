#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* args: amount
* i.e. ./a.out 100
* sicp 1.2.2
* 换零钱方式的统计
* 记忆递归实现
*/

int coins[5] = {1, 5, 10, 25, 50};
int **counts;

int count_change(int amount, int count)
{
    if(amount < 0)
    {
        return 0;
    }
    if(counts[amount][count] == -1)
    {
        if(amount == 0)
        {
            counts[amount][count] = 1;
        }
        else if(count == 0)
        {
            counts[amount][count] = 0;
        }
        else
        {
            counts[amount][count] = count_change(amount, count - 1) + count_change(amount - coins[count - 1], count);
        }
    }
    return counts[amount][count];
}

int main(int argc, char *argv[])
{
    int amount = atoi(argv[1]);
    int coins_count = sizeof(coins) / sizeof(coins[0]);

    counts = (int**)malloc(sizeof(int*) * (amount + 1));
    for(int i = 0; i <= amount; i++)
    {
        counts[i] = (int*)malloc((coins_count + 1) * sizeof(int));
        for(int j = 0; j <= coins_count; j++)
            counts[i][j] = -1;
    }

    int c = count_change(amount, coins_count);
    printf("%d\n", c);

    for(int i = 0; i <= amount; i++)
        free(counts[i]);
    free(counts);

    return 0;
}
/*
* scheme codesnippet
(define (count-change amount)
    (cc amount 5)
)


(define (cc amount kinds-of-coins)
    (cond
        ((= amount 0) 1)
        ((or (< amount 0) (= kinds-of-coins 0)) 0)
        (else (+ (cc amount (- kinds-of-coins 1)) (cc (- amount (first-denomination kinds-of-coins)) kinds-of-coins)))
    )
)

(define (first-denomination kinds-of-coins)
    (cond
        ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)
    )
)
*/
