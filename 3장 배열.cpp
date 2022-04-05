#include <stdio.h>
#include <stdlib.h>


#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct { //다항식 구조체
	int degree; // 다항식 차수
	float coef[MAX_DEGREE]; //다항식 개수
}polynomial;
// C = A+B 여기서 A와 B는 다항식이다. 구조체 반환
polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C; //결과 다항식
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree); // 결과 다항식 차수

	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) { //A항 > B항
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;
		}
		else if (degree_a == degree_b) { // A항 == B항
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else { //B항 > A항
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}
void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f\n", p.coef[p.degree]);
}
int main()
{
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	print_poly(a);
	print_poly(b);
	c = poly_add1(a, b);
	printf("---------------------------------------------------------------\n");
	print_poly(c);
	return 0;
}
typedef struct studentTag { //structure.c
	char name[10]; //문자배열 이름
	int age; //정수값 나이
	double gpa; // 실수값 평균평점
} student;
int main()
{
	student a = { "kim",20,4.3 };
	student b = { "park",21,4.2 };
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
	float coef;
	int expon;
}polynomial;
polynomial terms[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
int avail = 6;
//두개의 정수 비교
char compare(int a, int b)
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}
// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail].expon = expon;
	avail++;
}
// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	float tempcoef;
	*Cs = avail;
	while(As<=Ae&&Bs<=Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>':
			attach(terms[As].expon, terms[Bs].expon);
			As++;		break;
		case '=':
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++; Bs++; break;
		case'<':
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;		break;
		}
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	for (; Bs <= Be; Bs++)
		attach(terms[As].coef, terms[Bs].expon);
	*Ce = avail - 1;
}
void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d +", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}
int main()
{
	int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("---------------------------------------------");
	print_poly(Cs, Ce);
	return 0;
}

#include <stdio.h>
#define ROWS 3
#define COLS 3
//행렬 전치 함수
void matrix_transpose(int A[ROWS][COLS], int B[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++)
		for (int c = 0; c < COLS; c++)
			B[c][r] = A[r][c];
}
void matrix_print(int A[ROWS][COLS])
{
	printf("=============\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++)
			printf("%d", A[r][c]);
		printf("\n");
	}
	printf("======================\n");
}
int main()
{
	int array1[ROWS][COLS] = { {2,3,0},{8,9,1},{7,0,5} };
	int array2[ROWS][COLS];
	matrix_transpose(array1, array2);
	matrix_print(array1);
	matrix_print(array2);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100
typedef struct {
	int row;
	int col;
	int value;
}element;
typedef struct SparseMatrix {
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix matrix_transpose2(SparseMatrix a)
{
	SparseMatrix b;

	int bindex;
	b.rows = a.rows;
	b.cols = a.cols;
	b.terms = a.terms;

	if (a.terms > 0) {
		bindex = 0;
		for (int c = 0; c < a.cols; c++) {
			for (int i = 0; i < a.terms; i++) {
				if (a.data[i].col == c) {
					b.data[bindex].row = a.data[i].col;
					b.data[bindex].col = a.data[i].row;
					b.data[bindex].value = a.data[i].value;
					bindex++;
				}
			}
		}
	}
	return b;
}
void matrix_print(SparseMatrix a)
{
	printf("===================\n");
	for (int i = 0; i < a.terms; i++) {
		printf("(%d, %d, %d) \n", a.data[i].row, a.data[i].col, a.data[i].value);
	}
	printf("==================\n");
}
int main()
{
	SparseMatrix m = {
		{{0,3,7},{1,0,9},{1,5,8},{3,0,6},{3,1,5},{4,5,1},{5,2,2}},
		6,
		6,
		7
	};
	SparseMatrix result;
	result = matrix_transpose2(m);
	matrix_print(result);
	return 0;
}
#include <stdio.h>
void swap(int*px,int *py)
{
	int tmp;
	tmp = *px;
	*px = *py;
	*py = tmp;
}
int main()
{
	int a = 1, b = 2;
	printf("swap을 호출하기전: a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("swap을 호출한 다음: a=%d, b=%d\n", a, b);
	return 0;
}
#include <stdio.h>
#define SIZE 6
void get_integers(int list[])
{
	printf("6개의 정수를 입력하시오:");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%d", &list[i]);
	}
}
int cal_sum(int list[])
{
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
	{
		sum += *(list + i);
	}
	return sum;
}
int main()
{
	int list[SIZE];
	get_integers(list);
	printf("합=%d \n", cal_sum(list));
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main()
{
	int *p;
	p = (int*)malloc(SIZE * sizeof(int));
	if (p == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	for (int i = 0; i < SIZE; i++)
		p[i] = i;
	for (int i = 0; i < SIZE; i++)
		printf("%d ", p[i]);

	free(p);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct studentTah {
	char name[10];
	int age;
	double gpa;
}student;

int main()
{
	student *s;
	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");
		exit(1);
	}
	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
	return 0;
}
