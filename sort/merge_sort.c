#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 2000000
#define MOD 1000000000
#define num 1

int cmpint(const void *v1, const void *v2)
{
	return *(int*)v1 > *(int*)v2;
}

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1, n2 = r - m, i = 0, j = 0, k = l;
	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int l, int r)
{
	if(l >= r)
		return;

	int m = (l + r - 1) / 2;
	merge_sort(arr, l, m);
	merge_sort(arr, m + 1, r);
	merge(arr, l, m, r);
}


void print_array(int A[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	
	printf("\n");
}

int t_merge_sort(int A[], int size)
{
	int i;
	clock_t begin, end;
	double time_spent;

	time_spent = 0.0;
	begin = clock();
	for (i = 0; i < num; ++i)
		merge_sort(A, 0, size - 1);
	end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("merge spent: %f\n", time_spent);

	return 0;
}

int t_qsort(int A[], int size)
{
	int i;
	clock_t begin, end;
	double time_spent;

	time_spent = 0.0;
	begin = clock();
	for (i = 0; i < num; ++i)
		qsort(A, size, sizeof(int), cmpint);
	end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("qsort spent: %f\n", time_spent);

	return 0;
}

int main()
{
	int *arr1 = (int*)malloc(N * sizeof(int)), i;
	int *arr2 = (int*)malloc(N * sizeof(int)), tmp;
	time_t t;
	
	srand((unsigned) time(&t));
	for (i = 0; i < N; ++i)
		{
			tmp = rand() % MOD;
			arr1[i] = tmp;
			arr2[i] = tmp;
		}

	t_merge_sort(arr1, N);
	//print_array(arr1, N);
	t_qsort(arr2, N);
	//print_array(arr2, N);
	
	return 0;
}
