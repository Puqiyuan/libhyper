#include <stdio.h>

#define SEN 1073741824

int display(int *A, int start, int end)
{
	int i;

	for (i = start; i <= end; ++i)
		printf("%d ", A[i]);

	printf("\n");
	return 0;
}

int merge(int *A, int p, int q, int r)
{
	int n1 = q - p + 2;
	int n2 = r - q + 1;
	int L[n1], R[n2], i, j, k;

	for (i = 0; i < n1 - 1; ++i)
		L[i] = A[p + i];
	for (j = 0; j < n2 - 1; ++j)
		R[j] = A[q + j + 1];
	L[n1] = R[n2] = SEN;

	i = j = 0;
	for (k = 0; k <= r; ++k)
		{
			if (L[i] <= R[j])
				{
					A[k] = L[i];
					++i;
				}
			else
				{
					A[k] = R[j];
					++j;
				}
		}

	return 0;
}

int merge_sort(int *A, int p, int r)
{
	int q;

	if (p < r)
		{
			q = (p + r) / 2;
			merge_sort(A, p, q);
			display(A, p, q);
			merge_sort(A, q + 1, r);
			merge(A, p, q, r);
		}
}

int main(int argc, char *argv[])
{
	int A[8] = {5, 2, 4, 7, 1, 3, 2, 6};
	display(A, 0, 7);
	//merge(A, 0, 3, 7);
	merge_sort(A, 0, 7);
	display(A, 0, 7);
	
    return 0;
}
