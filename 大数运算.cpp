#pragma warning(disable:4996)

#include <iostream>

const int CHSIZE = 16;
const int INSIZE = 4;
const int DEC = 10000;

void multiply(const int *a, const int *b, int *c);
void chToNum(const char *charr, int *inarr);
void readCh(char *arr);
void display(const int *arr);

int main()
{
	int arrayA[INSIZE] = { 0 };
	int arrayB[INSIZE] = { 0 };
	int arrayC[INSIZE + 1] = { 0 };
	char charrayA[CHSIZE] = { 0 };
	char charrayB[CHSIZE] = { 0 };

	readCh(charrayA);
	readCh(charrayB);

	chToNum(charrayA, arrayA);
	chToNum(charrayB, arrayB);

	multiply(arrayA, arrayB, arrayC);

	display(arrayC);

	return 0;
}

void multiply(const int *a, const int *b, int *c)
{
	int carry = 0;
	int i = 0;

	for (; i < INSIZE; ++i)
	{
		c[i] = (a[i] + b[i] + carry) % DEC;
		carry = (a[i] + b[i]) / DEC;
	}
	c[i] = carry;

	return;
}

void chToNum(const char *charr, int *inarr)
{
	int temp = 0;
	int chIndex = CHSIZE - 1;

	for (int inIndex = 0; inIndex < INSIZE; ++inIndex)
	{
		int situ = 1;
		for (; chIndex >= 0 && situ < DEC; --chIndex)
		{
			if (charr[chIndex] == '\n' || charr[chIndex] == '\0')
				continue;
			else
				temp = charr[chIndex] - '0';

			inarr[inIndex] += temp * situ;
			situ *= 10;	
		}
	}
	return;
}

void readCh(char *arr)
{
	int i = 0;

	//compare i with CHSIZE first or that buffer would be read
	while (i < CHSIZE && scanf("%c", arr + i)) 
	{
		if (arr[i] == '\n')
			break;
		++i;
	}

	return;
}

void display(const int * arr)
{
	bool begin = false;

	for (int i = INSIZE; i >= 0; --i)
	{
		if (!begin)
		{
			if (arr[i])
			{
				printf("%d", arr[i]);
				begin = true;
			}
		}
		else
		{
			printf("%d", arr[i]);
		}
	}

	return;
}
