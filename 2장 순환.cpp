#include <stdio.h>
int factorial(int n) // ��ȯ���� ���丮�� ���
{
	printf("factorial(%d)\n", n);
	if (n <= 1) return(1);
	else return (n * factorial(n - 1)); // n�� �ذ�κ� factorial(n - 1)�� ���ذ� �κ�
}
int factorial_iter(int n) // ��ȯ���� ���丮�� ���
{
	int i, result = 1;
	for (i = 1; i <= n; i++)
		result = result + i;
	return(result);
}
double slow_power(double x, int n) // �ݺ����� �ŵ����� ���
{
	int i;
	double result = 1.0;
	for (i = 0; i < n; i++)
		result = result * x;
	return(result);
}
/*
power(x,n):
if n==0
	then return 1;
else if n�� ¦��
	then return power(x^2,n/2);
else if n�� Ȧ��
	then return power(x^2, (n-1)/2);
*/
double power(double x, int n) // ��ȯ���� �ŵ����� ���
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}
int fib(int n) // ��ȯ���� �Ǻ���ġ ���� ���
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
int fib_iter(int n) // �ݺ����� �Ǻ���ġ ���� ���
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	int pp = 0;
	int p = 1;
	int result = 0;
	for (int i = 2; i <= n; i++) {
		result = p + pp;
		pp = p;
		p = result;
	}
	return result;
}
void hanoi_tower(int n, char from, char tmp, char to)
{
	if (n == 1) printf("���� 1�� %c ���� %c���� �ű��.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("���� %c�� %c���� %c���� �ű��.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}
