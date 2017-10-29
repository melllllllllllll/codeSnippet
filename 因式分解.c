#include <stdio.h>

int main()
{
	int i = 0;
	int n;

	scanf_s("%d", &n);
	printf_s("%d = ", n);

	for (i = 2; n != 1; ++i)
		while (n % i == 0)
		{
			printf_s("%d", i);
			n /= i;
			printf_s("%s", n == 1 ? "\0" : " * ");
		}

	printf_s("\n");
	getchar();

	return 0;
}
