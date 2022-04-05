#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
//히프트리 테스트 프로그램
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() //생성함수
{
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) //초기화 함수
{
	h->heap_size = 0;
}
void insert_max_heap(HeapType* h, element item) //삽입함수
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) //삭제함수
{
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
void heap_sort(element a[], int n) //히프를 이용한 정렬
{
	int i;
	HeapType* h;
	h = create();
	init(h);
	for (i = 0; i < n; i++) //트리에 값 삽입
	{
		insert_max_heap(h, a[i]);
	}
	for (i = (n - 1); i >= 0; i--)
	{
		a[i] = delete_max_heap(h);
	}
	free(h);
}
#define SIZE 8
int main()
{
	element list[SIZE] = { 23,56,11,9,56,99,27,34 };
	heap_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}

--------------------------------------------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
//LPT code
typedef struct {
	int id;
	int avail;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() //생성 함수
{
	//메모리 할당
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType*h) //초기화 함수
{
	h->heap_size = 0;
}
void insert_min_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.avail < h->heap[i / 2].avail))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}
element delete_min_heap(HeapType* h)
{
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child <= h->heap_size) && (h->heap[child].avail) > h->heap[child + 1].avail) // 현재 노드의 자식노드중 더 작은 노드를 찾는다.
		{
			child++;
		}
		if (temp.avail < h->heap[child].avail) break; // 한단계 아래로 이동
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
#define JOBS 7
#define MACHINES 3
int main()
{
	int jobs[JOBS] = { 8,7,6,5,3,2,1 };
	element m = { 0,0 };
	HeapType* h;
	h = create();
	init(h);
	for (int i = 0; i < MACHINES; i++)
	{
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}
	for (int i = 0; i < JOBS; i++)
	{
		m = delete_min_heap(h);
		printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다.\n", i, m.avail, m.avail + jobs[i] - 1, m.id);
		m.avail += jobs[i];
		insert_min_heap(h, m);
	}
	return 0;
}
--------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
//허프만 코드 생성
typedef struct TreeNode{
	int weight;
	char ch;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;
typedef struct {
	TreeNode* ptree;
	char ch;
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

HeapType* create() //생성함수
{
	return (HeapType*)malloc(sizeof(HeapType));
}
void init(HeapType* h) //초기화 함수
{
	h->heap_size = 0;
}
void insert_min_heap(HeapType* h, element item) //삽입함수
{
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key < h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_min_heap(HeapType* h) //삭제함수
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}
TreeNode* make_tree(TreeNode* left, TreeNode* right)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->left = left;
	node->right = right;
	return node;
}
void destroy_tree(TreeNode* root)
{
	if (root == NULL) return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}
int is_leaf(TreeNode* root)
{
	return !(root->left) && !(root->right);
}
void print_array(int codes[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}
void print_codes(TreeNode* root, int codes[], int top)
{
	if (root->left){
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}
	if (root->right) {
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}
	if (is_leaf(root)) {
		printf("%c: ", root->ch);
		print_array(codes, top);
	}
}
void huffman_tree(int freq[], char ch_list[], int n) // 허프만 트리 함수
{
	int i;
	TreeNode* node, * x;
	HeapType* heap;
	element e, e1, e2;
	int codes[100];
	int top = 0;

	heap = create();
	init(heap);
	for (i = 0; i < n; i++) {
		node = make_tree(NULL, NULL);
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}
	for (i = 1; i < n; i++) {
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d + %d -> %d \n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap);
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);
}

int main()
{
	char ch_list[] = { 's','i','n','t','e' };
	int freq[] = { 4,6,8,12,15 };
	huffman_tree(freq, ch_list, 5);
	return 0;
}
