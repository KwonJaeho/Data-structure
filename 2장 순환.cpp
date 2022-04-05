#include <stdio.h>
int factorial(int n) // 순환적인 팩토리얼 계산
{
	printf("factorial(%d)\n", n);
	if (n <= 1) return(1);
	else return (n * factorial(n - 1)); // n은 해결부분 factorial(n - 1)은 미해결 부분
}
int factorial_iter(int n) // 순환적인 팩토리얼 계산
{
	int i, result = 1;
	for (i = 1; i <= n; i++)
		result = result + i;
	return(result);
}
double slow_power(double x, int n) // 반복적인 거듭제곱 계산
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
else if n이 짝수
	then return power(x^2,n/2);
else if n이 홀수
	then return power(x^2, (n-1)/2);
*/
double power(double x, int n) // 순환적인 거듭제곱 계산
{
	if (n == 0) return 1;
	else if ((n % 2) == 0)
		return power(x * x, n / 2);
	else return x * power(x * x, (n - 1) / 2);
}
int fib(int n) // 순환적인 피보나치 수열 계산
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return (fib(n - 1) + fib(n - 2));
}
int fib_iter(int n) // 반복적인 피보나치 수열 계산
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
	if (n == 1) printf("원판 1을 %c 에서 %c으로 옮긴다.\n", from, to);
	else {
		hanoi_tower(n - 1, from, to, tmp);
		printf("원판 %c을 %c에서 %c으로 옮긴다.\n", n, from, to);
		hanoi_tower(n - 1, tmp, from, to);
	}
}
int main()
{
	hanoi_tower(4, 'A', 'B', 'C');
	return 0;
}
