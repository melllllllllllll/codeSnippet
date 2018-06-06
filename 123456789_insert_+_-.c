#include <stdio.h>
#include <stdlib.h>

#define C10(x) if((x) == num) printf("%s = %d\n", #x, num);
#define C9(x) C10(x##9) C10(x+9) C10(x-9)
#define C8(x) C9(x##8) C9(x+8) C9(x-8)
#define C7(x) C8(x##7) C8(x+7) C8(x-7)
#define C6(x) C7(x##6) C7(x+6) C7(x-6)
#define C5(x) C6(x##5) C6(x+5) C6(x-5)
#define C4(x) C5(x##4) C5(x+4) C5(x-4)
#define C3(x) C4(x##3) C4(x+3) C4(x-3)
#define C2(x) C3(x##2) C3(x+2) C3(x-2)

/**
* insert '+' or '-' to 123456789 to equal the num(argv[1])
*/
int main(int argc, char *argv[])
{
    int num;
    if(argc == 1)
    {
        num = 0;
    }
    else
    {
        num = atoi(argv[1]);
    }
    C2(1);
    C2(-1);
    return 0;
}
