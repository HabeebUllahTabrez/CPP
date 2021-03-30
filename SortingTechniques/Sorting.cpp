#include<iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n)
{
    int flag;
    for (int i = 0; i < n-1; i++)
    {
        flag = 0;
        for (int j = 0; i < n-1-i; i++)
        {
            if (A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
            return;
    }
}

void insertionSort(int A[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        x = A[i];
        j = i - 1;

        while (A[j] > x && j >= 0)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void selectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n-1; i++)
    {
        for (j = i+1, k = i ; j < n ; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        if (i != k)
            swap(&A[i], &A[k]);
    }
}

// function used in quick sort
int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;

    do
    {
        do{i++;} while (A[i] <= pivot);
        do{j--;} while (A[j] > pivot);
        
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);

    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;

    if (l < h)
    {
        j = partition(A, l, h);
        quickSort(A, l, j);
        quickSort(A, j+1, h);
    }
}

// function used in merge sort
void Merge(int A[], int l, int m, int h)
{
    int i, j, k;
    int B[100];
    i = l;
    j = m+1;
    k = l;

    while (i <= m && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= m; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for(i = l; i <= h; i++)
        A[i] = B[i];

}

void iMergeSort(int A[], int n)
{
    int i, p, l, h, m;
    for (p = 2; p <= n; p = p*2)
    {
        for (i = 0; i+p-1 < n; i = i+p)
        {
            l = i;
            h = i+p-1;
            m = (l+h)/2;
            Merge(A, l, m, h);
        }
    }
    if (p/2 < n)
        Merge(A, 0, p/2-1, n-1);
}

void rMergeSort(int A[], int l, int h)
{
    if(l < h)
    {
        int m = (l+h)/2;
        rMergeSort(A, l, m);
        rMergeSort(A, m+1, h);
        Merge(A, l, m, h);
    }
}

int findMax(int A[], int n)
{
    int max = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void countSort(int A[], int n)
{
    int *c;
    int i,j;
    int max = findMax(A, n);
    c = new int[max+1];
    for (i = 0; i < max+1; i++)
        c[i] = 0;
    for(i = 0; i<n ; i++)
        c[A[i]]++;
    i = 0;
    j = 0;
    while (i < max+1)
    {
        if (c[i] > 0)
        {
            A[j++] = i;
            c[i]--;
        }
        else
            i++;
    }
}

void shellSort(int A[], int n)
{
    int gap, i, j;
    int temp;
    for (gap = n/2; gap >= 1 ; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = A[i];
            j = i-gap;
            while (j>=0 && A[j]>temp)
            {
                A[j+gap] = A[j];
                j = j-gap;
            }
            A[j+gap] = temp;
        }
    }
}


int main()
{
    // for quick sort you need to set an element on the right as the highest element
    // (also can be referred as infinity)
    // here we use max integer
    int A[] = {45,67,76,43,65,87,23,69,98,56};

    int n = 11;

    // quickSort(A, 0, 10);
    shellSort(A, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
