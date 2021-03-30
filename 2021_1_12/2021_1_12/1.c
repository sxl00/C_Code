#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int x = 0;
	int y = 0;
	int max = 0;
	scanf("%d %d", &x, &y);
	max = Max(x, y);
	printf("%d\n", max);
	return 0;
}

