#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#define N 10000 
int main()
{
	int i = 0;
	int num[N] = {0};
	int length = 0;
	int n = 0;  //输入要查找的数
	//输入一组有序数组
	do{
		scanf("%d", &num[length]);
		length++;
	} while (getchar() != '\n');
	printf("查找的数:");
	scanf("%d", &n);
	printf("数组长度：%d\n", length);
	int left = 0;
	int right = length - 1;
	while (left <= right){
		int mid = (left + right) / 2;
		if (num[mid] == n){
			printf("找到了，所在下标为：%d\n", mid);
			break;
		}
		else if (num[mid] > n){
			right = mid - 1;
		}
		else if (num[mid] < n){
			left = mid + 1;
		}

	}
	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	int mul = 0;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= 9; j++)
//		{
//			mul = j * i;
//			if (i >= j)
//				printf("%d*%d = %d ", j, i, mul);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int num[10] = { 0 };
//	int max = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &num[i]);
//	}
//	max = num[0];
//	for (i = 0; i < 10; i++)
//	{
//		if (num[i] > max)
//			max = num[i];
//	}
//	printf("%d\n", max);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	double sum = 0.0;
//	double temp = 0.0;
//	for (i = 1; i <= 100; i++)
//	{
//		temp = 1.0 / i;
//		if (i % 2 == 0)
//		{
//			temp = (-1.0) / i;
//		}
//		sum += temp;
//	}
//	printf("%lf\n", sum);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if ((i / 10 == 9) || (i % 10 == 9))
//			count++;
//	}
//	printf("%d\n", count);
//	return 0;
//}
//#include<math.h>
//int prime(int n)
//{
//	int i = 0;
//	int flag = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			flag = 1;
//			break;
//		}	
//	}
//	if (i > sqrt(n))
//		return flag;
//}
//int main()
//{
//	int i = 0;
//	int k = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		k = prime(i);
//		if (0 == k)
//			printf("%d ", i);
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int k = 0;
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &a, &b);
//	m = b;
//	n = a;
//	while (k = a % b)
//	{
//		a = b;
//		b = k;
//	}
//	printf("最大公约数：%d", b);
//	printf("最小公倍数：%d", m * n / b);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if ((i % 10 == 9) || (i / 10 == 9))
//			count++;
//	}
//	printf("%d", count);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int k = 0;
//	int j = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		k = sqrt(i);
//		for (j = 2; j < k; j++)
//		{
//			if (i % j == 0)
//				break;
//		}
//		if (i > k)
//		printf("%d ", i);
//
//
//	}
//	//printf("%d ", i);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int k = 0;
//	scanf("%d %d", &a, &b);
//	while (k = a % b)
//	{
//		a = b;
//		b = k;
//	}
//	printf("%d", b);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main()
// {
//	int num[3] = { 0 };
//	int i = 0;
//	int j = 0;
//	int temp = 0;
//	for (i = 0; i < 3; i++)
//	{
//		scanf("%d", &num[i]);
//	}
//	//temp = num[0];
//	for (i = 0; i < 3; i++)
//	{
//		for (j = i; j < 3; j++)
//		{
//			if (num[j] > num[i])
//			{
//				temp = num[j];
//				num[j] = num[i];
//				num[i] = temp;
//			}
//		}
//	}
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d ", num[i]);
//	}
//	return 0;
//}