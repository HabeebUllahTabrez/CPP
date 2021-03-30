#include<iostream>
using namespace std;

class Heap
{
public:
    // All functions here use index as parameter but not size 
    void insert(int H[], int n);
    void createHeap(int H[], int n);
    int deleteEle(int H[], int n);
    void heapSort(int H[], int n);
};

void Heap::insert(int H[], int n)
{
    int i = n, temp;
    temp = H[i];

    while (i>1 && temp>H[i/2])
    {
        H[i] = H[i/2];
        i = i/2;
    }
    
    H[i] = temp;
}

void Heap::createHeap(int H[], int n)
{
    for (int i = 2; i <= n; i++)
        insert(H, i);
}

int Heap::deleteEle(int H[], int n)
{
    int i, j, x;
    int temp;
    x = H[1];

    H[1] = H[n];
    H[n] = x;

    i = 1, j = i*2;

    while (j < n-1)
    {
        if (H[j+1] > H[j])
            j = j+1;
        if (H[i] < H[j])
        {
            temp = H[i];
            H[i] = H[j];
            H[j] = temp;
            i = j;
            j = 2*i;
        }
        else 
            break;
    }

    return x;
}

void Heap::heapSort(int H[], int n)
{
    for (int i = n; i > 1; i--)
    {
        deleteEle(H, i);
    }
}

int main()
{
    int A[] = {0,10,20,30,25,5,40,35};
    Heap h;
    h.createHeap(A, 7);
    
    for (int i = 1; i < 8; i++)
    {
        cout << A[i] << " ";
    }

    // Heap sort
    h.heapSort(A, 7);
    cout << endl << endl;

    for (int i = 1; i < 8; i++)
    {
        cout << A[i] << " ";
    }
    
    return 0;
}
