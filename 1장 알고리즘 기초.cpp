
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	배열에서 최대값 찾는 알고리즘 의사코드
	ArrayMax(list, N) :
		largest < -list[0]
		for i<- 1 to N-1 do
			if list[i] >largest
				then largest <- list[i]
		return largest;
*/
int ArrayMax(int list[], int N)
{
	int largest, i;
	largest = list[0];
	for (i = 1; i < N; i++)
	{
		if (list[i] > largest)
		{
			largest = list[i];
		}
	}
	return largest;
}
int seq_serah(int list[], int key) //비교 연산
{
	int i,n;
	n = 100;
	for (i = 0; i < n ; i++)
	{
		if (list[i] == key) {
			return i;
		}
	}
	return -1;
}

/*
Nat_Number zero() :: = 0
Nat_Number successor() :: = if( x == INT_MAX ) return x
							else return x + 1
Boolean is_zero(x) :: = if (x) return FALSE
						else return TRUE
Boolean equal(x,y) :: = if ( x == y) return TRUE
						else return FALSE
Nat_Number add(x,y) :: = if ( ( x + y ) <= INT_MAX )
						 return x+y
						 else return INT_MAX
Nat_Number sub(x,y) :: = if ( x < y ) return 0
						 else return x-y;
*/
int main()  // cal_time.c
{
	clock_t start, stop;
	double duration;
	start = clock();
	for (int i = 0; i < 1000000; i++); // 의미없는 반복
	stop = clock();
	duration = (double)(stop - start) / CLOCKS_PER_SEC;
	printf("수행시간은 %f초입니다.\n", duration);
	return 0;
}
