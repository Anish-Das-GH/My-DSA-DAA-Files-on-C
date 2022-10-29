#include <stdio.h>
void Printarray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void heapify(int A[], int n, int i)
{
    int Larger = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    if (left < n && A[left] > A[Larger])
    {
        Larger = left;
    }
    if (right < n && A[right] > A[Larger])
    {
        Larger = right;
    }

    if (Larger != i)
    {
        int temp = A[i];
        A[i] = A[Larger];
        A[Larger] = temp;

        heapify(A, n, Larger);
    }
}

void Heapsort(int A[], int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(A, n, i);
    }

    for (i = n - 1; i >= 0; i--)
    {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;

        heapify(A, i, 0);
    }
}

int main()
{
    int arr[] = {10, 30, 5, 63, 22, 12, 56, 33};
    int n = 8;

    Heapsort(arr, n);

    Printarray(arr, n);

    return 0;
}
