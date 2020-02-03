#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int left(int i);
int right(int i);
void maxHeapify(vector<int> *A, int i);
void heapsort(vector<int> *A);
void buildMaxHeap(vector<int> *A);
void echo(vector<int> *A);

int heapSize = 0;

int main(int argc, char *argv[])
{
    vector<int> A;
    while (--argc)
        A.push_back(atoi(*(++argv)));

    heapsort(&A);
    echo(&A);
    return 0;
}

void echo(vector<int> *A)
{
    for (vector<int>::const_iterator iter = A->begin(); iter != A->end(); ++iter)
        cout << *iter << " ";
    cout << endl;
}

void heapsort(vector<int> *A)
{
    buildMaxHeap(A);
    int largestValue;
    for (int i = A->size() - 1; i >= 1; i--)
    {
        largestValue = (*A)[0];
        (*A)[0] = (*A)[i];
        (*A)[i] = largestValue;
        heapSize = heapSize - 1;
        maxHeapify(A, 0);
    }
}

void buildMaxHeap(vector<int> *A)
{
    heapSize = A->size();
    for (int i = floor(A->size() / 2) - 1; i >= 0; i--)
        maxHeapify(A, i);
}

void maxHeapify(vector<int> *A, int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heapSize and (*A)[l] > (*A)[i])
        largest = l;
    if (r < heapSize and (*A)[r] > (*A)[largest])
        largest = r;
    if (largest != i)
    {
        int tmp = (*A)[i];
        (*A)[i] = (*A)[largest];
        (*A)[largest] = tmp;
        maxHeapify(A, largest);
    }
}

int left(int i)
{
    return (i << 1) + 1;
}

int right(int i)
{
    return (i << 1) + 2;
}
